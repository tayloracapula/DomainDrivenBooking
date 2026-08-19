#include "../../include/doctest.hpp"
#include "../../include/MockRepositories.hpp"
#include "infrastructure/server/RepositoryRegistry.hpp"
#include "infrastructure/server/ApplicationServices.hpp"

TEST_CASE("Application Services is singleton") {
    auto& a = ApplicationServices::instance();

    auto& b = ApplicationServices::instance();

    CHECK(&a == &b);
}

TEST_CASE("Application Services initialise") {

    auto& repos= RepositoryRegistry::instance();

    repos.setStaffRepository(std::make_shared<MockStaffRepository>());
    repos.setLeaveRepository(std::make_shared<MockLeaveRepository>());
    repos.setLeaveAllowanceRepository(std::make_shared<MockLeaveAllowanceRepository>());


    CHECK_NOTHROW(ApplicationServices::instance().initialise());
}

TEST_CASE("Can retrieve CreateStaffMember service") {
    CHECK_NOTHROW(ApplicationServices::instance()
		    .createStaffMember());
}

TEST_CASE("Can retrieve UpdateStaffName service") {
    CHECK_NOTHROW(ApplicationServices::instance()
		    .updateStaffName());
}

TEST_CASE("Can retrieve UpdateStaffRole service") {
    CHECK_NOTHROW(ApplicationServices::instance()
		    .updateStaffRole());
}

TEST_CASE("Can retrieve TerminateStaffMember service") {
    CHECK_NOTHROW(ApplicationServices::instance()
		    .terminateStaffMember());
}


TEST_CASE("Can retrieve CreateLeaveRequest service") {
    CHECK_NOTHROW(ApplicationServices::instance()
		    .createLeaveRequest());
}

TEST_CASE("Can retrieve CancelLeaveRequest service") {
    CHECK_NOTHROW(ApplicationServices::instance()
		    .cancelLeaveRequest());
}

TEST_CASE("Can retrieve ApproveLeaveRequest service") {
    CHECK_NOTHROW(ApplicationServices::instance()
		    .approveLeaveRequest());
}

TEST_CASE("Can retrieve DenyLeaveRequest service") {
    CHECK_NOTHROW(ApplicationServices::instance()
		    .denyLeaveRequest());
}

TEST_CASE("Service Registry returns same service") {
    auto& a = ApplicationServices::instance().createLeaveRequest();
    auto& b = ApplicationServices::instance().createLeaveRequest();

    CHECK(&a == &b);
}


