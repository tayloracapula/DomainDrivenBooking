#include "../include/fixtures/RepositoryFixture.hpp"
#include "../include/doctest.hpp"

#include "modules/staff/domain/StaffMember.hpp"
#include "modules/leave/domain/LeaveAllowance.hpp"

TEST_CASE_FIXTURE(RepositoryFixture,"LeaveAllowance can be saved and loaded")
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

    LeaveAllowance origional(
	Identity<LeaveAllowanceId>::generate(),
	staff.id(),
	25,
	25
    );

    staffRepository->save(staff);
    leaveAllowanceRepository->save(origional);

    auto loaded = leaveAllowanceRepository->findById(origional.id());

    REQUIRE(loaded.has_value());

    CHECK(loaded->id().value() == origional.id().value());
}

TEST_CASE_FIXTURE(RepositoryFixture, "LeaveAllowance can be loaded by staffId")
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

    LeaveAllowance origional(
	Identity<LeaveAllowanceId>::generate(),
	staff.id(),
	25,
	25
    );

    staffRepository->save(staff);
    leaveAllowanceRepository->save(origional);

    auto loaded = leaveAllowanceRepository->findByStaff(staff.id());

    REQUIRE(loaded.has_value());

    CHECK(loaded->id().value() == origional.id().value());

}
