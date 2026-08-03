#include "modules/leave/domain/LeaveRequestId.hpp"
#include "modules/staff/domain/StaffId.hpp"
#include "shared/domain/Identity.hpp"
#include <exception>
#include <stdexcept>
#include "modules/leave/application/services/DenyLeaveRequest.hpp"
Identity<LeaveRequestId> DenyLeaveRequest::execute(const ApproveDenyLeaveRequestDTO& dto){
    try {
	auto leaveRequest = leaveRepository_.findById(Identity<LeaveRequestId>::of(dto.leaveRequestId));

	if (!leaveRequest) throw std::runtime_error("Failed to retrieve leave request");

	auto leaveAllowance = leaveAllowanceRepository_.findByStaff(leaveRequest->staffId());

	if (!leaveAllowance) throw std::runtime_error("Failed to retrieve leave allowance");

	auto manager = staffRepository_.findById(Identity<StaffId>::of(dto.ManagerId));

	if (!manager) throw std::runtime_error("Failed to retrieve manager");
	
	leaveRequest->reject();

	leaveAllowance->deductDays(leaveRequest->dateRange().days());

	leaveRepository_.update(leaveRequest.value());

	leaveAllowanceRepository_.update(leaveAllowance.value());
	
	return leaveRequest->id();

    } catch (const std::exception& e) {
	throw;
    }
}
