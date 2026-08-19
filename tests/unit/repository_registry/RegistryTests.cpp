#include "../../include/doctest.hpp"
#include "../../include/MockRepositories.hpp"
#include "infrastructure/server/RepositoryRegistry.hpp"
#include <memory>

TEST_CASE("Repository registry is singleton") {
    auto& a = RepositoryRegistry::instance();

    auto& b = RepositoryRegistry::instance();

    CHECK(&a == &b);
}

TEST_CASE("Can register staff repository") {
    auto repo = std::make_shared<MockStaffRepository>();

    RepositoryRegistry::instance().setStaffRepository(repo);

    auto& retrieved = RepositoryRegistry::instance().staffRepository();

    CHECK(&retrieved == repo.get());
}

TEST_CASE("Can register all repositories") {
    auto staffRepo = std::make_shared<MockStaffRepository>();

    auto leaveRepo = std::make_shared<MockLeaveRepository>();

    auto allowanceRepo = std::make_shared<MockLeaveAllowanceRepository>();

    auto& registry = RepositoryRegistry::instance();

    registry.setStaffRepository(staffRepo);
    registry.setLeaveRepository(leaveRepo);
    registry.setLeaveAllowanceRepository(allowanceRepo);

    CHECK(&registry.staffRepository() == staffRepo.get());

    CHECK(&registry.leaveRepository() == leaveRepo.get());

    CHECK(&registry.leaveAllowanceRepository() == allowanceRepo.get());
}
