#include "modules/leave/application/services/GetLeaveRequestForStaff.hpp"
#include <exception>

std::vector<LeaveRequest> GetLeaveForStaff::execute(const GetDTO<Identity<StaffId>>& dto){
    try {
	auto requests = leaveRepository_.findByStaff(dto.id);

	if (requests.empty()) throw std::runtime_error("Failed to retrieve leave requests");

	return requests;
	
    } catch (const std::exception& e) {
	throw;
    }
}
