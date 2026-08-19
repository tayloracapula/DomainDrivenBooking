#include "../include/doctest.hpp"
#include "../include/MockRepositories.hpp"
#include "infrastructure/server/ApplicationServices.hpp"

TEST_CASE("CreateStaffMember saves a staff member") {
    MockStaffRepository repository;

    CreateStaffMember service(repository);

    CreateStaffMemberDTO dto;

    dto.firstName = "test";
    dto.surName = "name";
    dto.houseNameNumber = "3";
    dto.street = "road";
    dto.town = "town";
    dto.postcode = "abc123";
    dto.role = "staff";

    auto id = service.execute(dto);

    auto staff = repository.findById(id);

    REQUIRE(staff.has_value());

    CHECK(staff->id() == id);
}

TEST_CASE("CreateLeaveRequest saves request") {
    MockLeaveRepository leaveRepo;
    MockLeaveAllowanceRepository allowanceRepo;

    CreateLeaveRequest service(
	leaveRepo,
	allowanceRepo
    );

    Identity<StaffId> staffId = Identity<StaffId>::generate();
    
    LeaveAllowance allowance(
	Identity<LeaveAllowanceId>::generate(),
	staffId,
	25,
	25
    );

    allowanceRepo.create(allowance);

    CreateLeaveRequestDTO dto;

    dto.staffId = staffId.value();
    dto.reason = "holiday";
    dto.startDate = "2026-7-1";
    dto.endDate = "2026-7-9";
    
    auto id = service.execute(dto);

    auto request = leaveRepo.findById(id);

    CHECK(request.has_value());
}

TEST_CASE("Cannot exceed allowance") {
    MockLeaveRepository leaveRepo;
    MockLeaveAllowanceRepository allowanceRepo;

    CreateLeaveRequest service(
	leaveRepo,
	allowanceRepo
    );

    Identity<StaffId> staffId = Identity<StaffId>::generate();
    
    LeaveAllowance allowance(
	Identity<LeaveAllowanceId>::generate(),
	staffId,
	25,
	1
    );

    allowanceRepo.create(allowance);

    CreateLeaveRequestDTO dto;

    dto.staffId = staffId.value();
    dto.reason = "holiday";
    dto.startDate = "2026-7-1";
    dto.endDate = "2026-7-9";
    
    CHECK_THROWS(service.execute(dto));
}


TEST_CASE("Approving Leave updates Status") {
    MockLeaveRepository leaveRepo;
    MockLeaveAllowanceRepository allowanceRepo;
    MockStaffRepository staffRepo;

    CreateStaffMember staffService(staffRepo);

    CreateStaffMemberDTO mdto;

    mdto.firstName = "test";
    mdto.surName = "name";
    mdto.houseNameNumber = "3";
    mdto.street = "road";
    mdto.town = "town";
    mdto.postcode = "abc123";
    mdto.role = "staff";


    auto managerId = staffService.execute(mdto);

    CreateStaffMemberDTO sdto;

    sdto.firstName = "test";
    sdto.surName = "name";
    sdto.houseNameNumber = "3";
    sdto.street = "road";
    sdto.town = "town";
    sdto.postcode = "abc123";
    sdto.role = "staff";
    sdto.managerId = managerId.value();


    auto staffId = staffService.execute(sdto);
    

    CreateLeaveRequest createLeaveService(
	leaveRepo,
	allowanceRepo
    );

   
    LeaveAllowance allowance(
	Identity<LeaveAllowanceId>::generate(),
	staffId,
	25,
	25
    );

    allowanceRepo.create(allowance);

    CreateLeaveRequestDTO ldto;

    ldto.staffId = staffId.value();
    ldto.reason = "holiday";
    ldto.startDate = "2026-7-1";
    ldto.endDate = "2026-7-9";
    
    auto requestId = createLeaveService.execute(ldto);

    ApproveLeaveRequest service(
	leaveRepo,
	allowanceRepo,
	staffRepo
    );

    ApproveDenyLeaveRequestDTO dto;

    dto.leaveRequestId = requestId.value();
    dto.ManagerId = managerId.value();

    service.execute(dto);

    auto request = leaveRepo.findById(requestId);

    CHECK(request->status() == LeaveStatus::Approved);
}

TEST_CASE("Approving Leave reduces allowance") {
    MockLeaveRepository leaveRepo;
    MockLeaveAllowanceRepository allowanceRepo;
    MockStaffRepository staffRepo;

    CreateStaffMember staffService(staffRepo);

    CreateStaffMemberDTO mdto;

    mdto.firstName = "test";
    mdto.surName = "name";
    mdto.houseNameNumber = "3";
    mdto.street = "road";
    mdto.town = "town";
    mdto.postcode = "abc123";
    mdto.role = "staff";


    auto managerId = staffService.execute(mdto);

    CreateStaffMemberDTO sdto;

    sdto.firstName = "test";
    sdto.surName = "name";
    sdto.houseNameNumber = "3";
    sdto.street = "road";
    sdto.town = "town";
    sdto.postcode = "abc123";
    sdto.role = "staff";
    sdto.managerId = managerId.value();


    auto staffId = staffService.execute(sdto);
    

    CreateLeaveRequest createLeaveService(
	leaveRepo,
	allowanceRepo
    );

   
    LeaveAllowance allowance(
	Identity<LeaveAllowanceId>::generate(),
	staffId,
	25,
	25
    );

    allowanceRepo.create(allowance);

    CreateLeaveRequestDTO ldto;

    ldto.staffId = staffId.value();
    ldto.reason = "holiday";
    ldto.startDate = "2026-7-1";
    ldto.endDate = "2026-7-11";
    
    auto requestId = createLeaveService.execute(ldto);

    ApproveLeaveRequest service(
	leaveRepo,
	allowanceRepo,
	staffRepo
    );

    ApproveDenyLeaveRequestDTO dto;

    dto.leaveRequestId = requestId.value();
    dto.ManagerId = managerId.value();

    service.execute(dto);

    auto remainingAllowance = allowanceRepo.findByStaff(staffId);

    CHECK(remainingAllowance->remainingDays() == 15);
}
