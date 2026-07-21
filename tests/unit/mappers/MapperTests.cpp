#include "../../include/doctest.hpp"
#include "infrastructure/persistence/mappers/LeaveMapper.hpp"
#include "infrastructure/persistence/mappers/LeaveAllowanceMapper.hpp"
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
	LeaveReason("Holiday")
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

    auto result = LeaveMapper::toDomain(model);

    CHECK(result.id().value() == "leave-1");
    CHECK(result.staffId().value() == "staff-1");
    CHECK(result.reason().reason() == "Holiday");
}
