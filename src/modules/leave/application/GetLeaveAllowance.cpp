#include "modules/leave/application/services/GetLeaveAllowance.hpp"
#include <exception>

LeaveAllowance GetLeaveAllowance::execute(const GetDTO<Identity<LeaveAllowanceId>>& dto){
    try {
	auto leaveRequest = leaveAllowanceRepository_.findById(dto.id);

	if (!leaveRequest) throw std::runtime_error("Failed to retrieve leave request");

	return leaveRequest.value();

    } catch (const std::exception& e) {
	throw;
    }
}
