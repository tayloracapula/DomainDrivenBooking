#include "modules/leave/domain/LeaveRequestId.hpp"
#include "modules/leave/domain/LeaveStatus.hpp"
#include "shared/domain/Identity.hpp"
#include <exception>
#include <stdexcept>
#include "modules/leave/application/services/CancelLeaveRequest.hpp"

Identity<LeaveRequestId> CancelLeaveRequest::execute(const CancelLeaveRequestDTO& dto){
    try {
	auto leaveRequest = leaveRepository_.findById(Identity<LeaveRequestId>::of(dto.leaveRequestId));

	if (!leaveRequest) throw std::runtime_error("Failed to retrieve leave request");

	if (leaveRequest->status() == LeaveStatus::Approved) {

	    auto leaveAllowance = leaveAllowanceRepository_.findByStaff(leaveRequest->staffId());

	    if (!leaveAllowance) throw std::runtime_error("Failed to retrieve leave allowance");
	    
	    leaveAllowance->addDays(leaveRequest->dateRange().days());

	    leaveAllowanceRepository_.update(leaveAllowance.value());
		
	}

	leaveRequest->cancel();

	leaveRepository_.update(leaveRequest.value());

	return leaveRequest->id();

    } catch (const std::exception& e) {
	throw;
    }
}

