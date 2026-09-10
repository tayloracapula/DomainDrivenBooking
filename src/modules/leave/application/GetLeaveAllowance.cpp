#include "modules/leave/application/services/GetLeaveAllowance.hpp"
#include "shared/errors/ErrorTypes.hpp"

LeaveAllowance GetLeaveAllowance::execute(const GetDTO<Identity<StaffId>>& dto){
    try {
	auto leaveRequest = leaveAllowanceRepository_.findByStaff(dto.id);

	if (!leaveRequest) throw NotFoundException("Failed to retrieve leave request");

	return leaveRequest.value();

    } catch (const std::exception& e) {
	throw;
    }
}
