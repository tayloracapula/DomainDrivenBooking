#include "../include/fixtures/RepositoryFixture.hpp"
#include "../include/doctest.hpp"

#include "modules/staff/domain/StaffMember.hpp"

TEST_CASE_FIXTURE(RepositoryFixture, "StaffMember can be saved and loaded")
{
    StaffMember origional(
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

    staffRepository->save(origional);

    auto loaded = staffRepository->findById(origional.id());

    REQUIRE(loaded.has_value());

    CHECK(
	loaded->id().value() == origional.id().value()
    );
}

TEST_CASE_FIXTURE(RepositoryFixture, "StaffMember can be found by manager id")
{
    StaffMember manager(
	Identity<StaffId>::generate(),
	FullName("test","user"),
	Address(
	    "1",
	    "road",
	    "town",
	    "ABC123"
	),
	Role(RoleType::Manager),
	EmploymentStatus::Active
    );

    StaffMember origional(
	Identity<StaffId>::generate(),
	FullName("test","user"),
	Address(
	    "1",
	    "road",
	    "town",
	    "ABC123"
	),
	Role(RoleType::Staff),
	EmploymentStatus::Active,
	manager.id()
    );


    staffRepository->save(manager);
    staffRepository->save(origional);

    auto loaded = staffRepository->findByManager(manager.id());

    REQUIRE(loaded.size() != 0);

    CHECK(
	loaded[0].id().value() == origional.id().value()
    );

}

TEST_CASE_FIXTURE(RepositoryFixture, "Manager can be found by its staff member")
{
    StaffMember manager(
	Identity<StaffId>::generate(),
	FullName("test","user"),
	Address(
	    "1",
	    "road",
	    "town",
	    "ABC123"
	),
	Role(RoleType::Manager),
	EmploymentStatus::Active
    );

    StaffMember origional(
	Identity<StaffId>::generate(),
	FullName("test","user"),
	Address(
	    "1",
	    "road",
	    "town",
	    "ABC123"
	),
	Role(RoleType::Staff),
	EmploymentStatus::Active,
	manager.id()
    );


    staffRepository->save(manager);
    staffRepository->save(origional);

    auto loaded = staffRepository->findManagerOf(origional.id());

    REQUIRE(loaded.has_value());

    CHECK(
	loaded->id().value() == manager.id().value()
    );

}
