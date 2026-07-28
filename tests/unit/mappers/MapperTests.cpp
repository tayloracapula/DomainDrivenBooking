#include "../../include/doctest.hpp"
#include "infrastructure/persistence/mappers/LeaveMapper.hpp"
#include "infrastructure/persistence/mappers/StaffMapper.hpp"
#include "infrastructure/persistence/mappers/LeaveAllowanceMapper.hpp"
#include "infrastructure/persistence/models/LeaveAllowance.hpp"
#include "shared/time/TrantorDateConvertion.hpp"
#include "modules/staff/domain/StaffId.hpp"
#include <chrono>


TEST_CASE("LeaveRequest maps to ORM model") {
    
    LeaveRequest request(
	Identity<LeaveRequestId>::of("leave-1"),
	Identity<StaffId>::of("staff-1"),
	DateRange(
	    std::chrono::year{2026}/1/1,
	    std::chrono::year{2026}/1/5
	),
	LeaveReason("Holiday"),
	LeaveStatus::Pending
    );

    auto model = LeaveMapper::toModel(request);

    CHECK(model.getValueOfId() == "leave-1");
    CHECK(model.getValueOfStaffId() == "staff-1");
    CHECK(model.getValueOfLeaveReason() == "Holiday");
}

TEST_CASE("LeaveAllowance maps to ORM model") {

    LeaveAllowance allowance(
	Identity<LeaveAllowanceId>::of("allowance-1"),
	Identity<StaffId>::of("staff-1"),
	25,
	25
    );

    auto model = LeaveAllowanceMapper::toModel(allowance);

    CHECK(model.getValueOfId() == "allowance-1");
    CHECK(model.getValueOfStaffId() == "staff-1");
    CHECK(model.getValueOfAnnualEntitlement() == 25);
    CHECK(model.getValueOfRemainingLeave() == 25);
}

TEST_CASE("StaffMember maps to ORM model"){
    StaffMember staff(
	Identity<StaffId>::of("staff-1"),
	FullName(
	    "test",
	    "member"
	),
	Address(
	    "one",
	    "road",
	    "town",
	    "ABC123"
	),
	Role(RoleType::Staff),
	EmploymentStatus(EmploymentStatus::Active),
	Identity<StaffId>::of("manager-1")
    );

    auto model = StaffMapper::toModel(staff);

    CHECK(model.getValueOfId() == "staff-1");
    CHECK(model.getValueOfFirstName() == "test");
    CHECK(model.getValueOfSurname() == "member");
    CHECK(model.getValueOfHouseNameNumber() == "one");
    CHECK(model.getValueOfStreet() == "road");
    CHECK(model.getValueOfTown() == "town");
    CHECK(model.getValueOfPostcode() == "ABC123");
    CHECK(model.getValueOfRole() == "Staff");
    CHECK(model.getValueOfEmploymentStatus() == "Active");
    CHECK(model.getValueOfManagerId() == "manager-1");
}

TEST_CASE("ORM model maps to LeaveRequest") {
    drogon_model::LeaveBooking::LeaveRequest model;
    model.setId("leave-1");
    model.setStaffId("staff-1");
    model.setLeaveReason("Holiday");
    model.setStartDate(
	toTrantorDate(std::chrono::year{2026}/1/1)
    );
    model.setEndDate(
	toTrantorDate(std::chrono::year{2026}/1/5)
    );
    model.setLeaveStatus("Pending");

    auto result = LeaveMapper::toDomain(model);

    CHECK(result.id().value() == "leave-1");
    CHECK(result.staffId().value() == "staff-1");
    CHECK(result.reason().reason() == "Holiday");
}

TEST_CASE("ORM model maps to LeaveAllowance"){
    drogon_model::LeaveBooking::LeaveAllowance model;
    model.setId("allowance-1");
    model.setStaffId("staff-1");
    model.setAnnualEntitlement(25);
    model.setRemainingLeave(25);

    auto result = LeaveAllowanceMapper::toDomain(model);

    CHECK(result.id().value() == "allowance-1");
    CHECK(result.staffId().value() == "staff-1");
    CHECK(result.annualEntitlement() == 25);
    CHECK(result.remainingDays() == 25);
}

TEST_CASE("ORM model maps to StaffMember"){
    drogon_model::LeaveBooking::StaffMember model;

    model.setId("staff-1");
    model.setFirstName("test");
    model.setSurname("member");
    model.setHouseNameNumber("one");
    model.setStreet("road");
    model.setTown("town");
    model.setPostcode("ABC123");
    model.setRole("Staff");
    model.setEmploymentStatus("Active");
    model.setManagerId("manager-1");

    auto result = StaffMapper::toDomain(model);

    CHECK(result.id().value() == "staff-1");
    CHECK(result.fullName().firstName() == "test");
    CHECK(result.fullName().surname() == "member");
    CHECK(result.address().houseNameNumber() == "one");
    CHECK(result.address().street() == "road");
    CHECK(result.address().town() == "town");
    CHECK(result.address().postcode() == "ABC123");
    CHECK(result.role().role() == RoleType::Staff);
    CHECK(result.employmentStatus() == EmploymentStatus::Active);
    CHECK(result.managerId()->value() == "manager-1");
}

TEST_CASE("LeaveRequest round trip mapping"){

    LeaveRequest origional(
	Identity<LeaveRequestId>::of("leave-1"),
	Identity<StaffId>::of("staff-1"),
	DateRange(
	    std::chrono::year{2026}/1/1,
	    std::chrono::year{2026}/1/5
	),
	LeaveReason("Holiday"),
	LeaveStatus::Pending
    );

    auto model = LeaveMapper::toModel(origional);

    auto result = LeaveMapper::toDomain(model);

    CHECK(result.id().value() == "leave-1");
    CHECK(result.staffId().value() == "staff-1");
    CHECK(result.reason().reason() == "Holiday");

}

TEST_CASE("LeaveAllowance round trip mapping"){

    LeaveAllowance origional(
	Identity<LeaveAllowanceId>::of("allowance-1"),
	Identity<StaffId>::of("staff-1"),
	25,
	25
    );

    auto model = LeaveAllowanceMapper::toModel(origional);

    auto result = LeaveAllowanceMapper::toDomain(model);

    CHECK(result.id().value() == "allowance-1");
    CHECK(result.staffId().value() == "staff-1");
    CHECK(result.annualEntitlement() == 25);
    CHECK(result.remainingDays() == 25);
}

TEST_CASE("StaffMember round trip mapping"){
    StaffMember origional(
	Identity<StaffId>::of("staff-1"),
	FullName(
	    "test",
	    "member"
	),
	Address(
	    "one",
	    "road",
	    "town",
	    "ABC123"
	),
	Role(RoleType::Staff),
	EmploymentStatus(EmploymentStatus::Active),
	Identity<StaffId>::of("manager-1")
    );

    auto model = StaffMapper::toModel(origional);

    auto result = StaffMapper::toDomain(model);

    CHECK(result.id().value() == "staff-1");
    CHECK(result.fullName().firstName() == "test");
    CHECK(result.fullName().surname() == "member");
    CHECK(result.address().houseNameNumber() == "one");
    CHECK(result.address().street() == "road");
    CHECK(result.address().town() == "town");
    CHECK(result.address().postcode() == "ABC123");
    CHECK(result.role().role() == RoleType::Staff);
    CHECK(result.employmentStatus() == EmploymentStatus::Active);
    CHECK(result.managerId()->value() == "manager-1");
}
