#include "../include/fixtures/RepositoryFixture.hpp"
#include "../include/doctest.hpp"

#include "modules/leave/domain/LeaveRequest.hpp"
#include "modules/staff/domain/StaffMember.hpp"

TEST_CASE_FIXTURE(RepositoryFixture, "LeaveRequest can be saved and loaded")
{
    StaffMember staff(
	Identity<StaffId>::generate(),
	FullName("test","user"),
	Address(
	    "1",
	    "road",
	    "town",
	    "ABC123"
	),
	Role(RoleType::Staff),
	EmploymentStatus::Active
    );

    LeaveRequest origional(
	Identity<LeaveRequestId>::generate(),
	staff.id(),
	DateRange(
	    std::chrono::year{2026}/1/1,
	    std::chrono::year{2026}/1/5
	),
	LeaveReason("Holiday"),
	LeaveStatus::Pending
    );

    staffRepository->save(staff);
    leaveRepository->save(origional);

    auto loaded = leaveRepository->findById(origional.id());

    REQUIRE(loaded.has_value());

    CHECK(loaded->id().value() == origional.id().value());
}

TEST_CASE_FIXTURE(RepositoryFixture,"StaffMember's leave requests can be loaded")
{
    StaffMember staff(
	Identity<StaffId>::generate(),
	FullName("test","user"),
	Address(
	    "1",
	    "road",
	    "town",
	    "ABC123"
	),
	Role(RoleType::Staff),
	EmploymentStatus::Active
    );

    LeaveRequest first(
	Identity<LeaveRequestId>::generate(),
	staff.id(),
	DateRange(
	    std::chrono::year{2026}/1/1,
	    std::chrono::year{2026}/1/5
	),
	LeaveReason("Holiday"),
	LeaveStatus::Pending
    );

    staffRepository->save(staff);
    leaveRepository->save(first);

    auto loaded = leaveRepository->findByStaff(staff.id());

    REQUIRE(loaded.size() != 0);

    CHECK(
	loaded[0].id().value() == first.id().value()
    );
}




