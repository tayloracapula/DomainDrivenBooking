#include "modules/leave/application/services/GetLeaveRequest.hpp"
#include <exception>

LeaveRequest GetLeaveRequest::execute(const GetDTO<Identity<LeaveRequestId>>& dto){
    try {
	auto leaveRequest = leaveRepository_.findById(dto.id);

	if (!leaveRequest) throw std::runtime_error("Failed to retrieve leave request");

	return leaveRequest.value();

    } catch (const std::exception& e) {
	throw;
    }
}
