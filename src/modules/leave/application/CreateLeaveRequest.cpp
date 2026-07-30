#include "modules/leave/application/services/CreateLeaveRequest.hpp"
#include "modules/leave/domain/LeaveStatus.hpp"
#include "modules/staff/domain/StaffId.hpp"
#include "shared/time/parseDate.hpp"
#include <exception>
#include <stdexcept>

Identity<LeaveRequestId> CreateLeaveRequest::execute(const CreateLeaveRequestDTO& dto){
    try{
	auto leaveAllowance = leaveAllowanceRepository_.findByStaff(Identity<StaffId>::of(dto.staffId));

	if (!leaveAllowance) throw std::runtime_error("Failed to retrieve leave allowance");

	LeaveRequest request(
	    Identity<LeaveRequestId>::generate(),
	    Identity<StaffId>::of(dto.staffId),
	    DateRange(
		parseDate(dto.startDate),
		parseDate(dto.endDate)
	    ),
	    LeaveReason(dto.reason),
	    LeaveStatus::Pending
	);


	leaveRepository_.save(request);

	return request.id();

    }catch(const std::exception& e){
	throw;
    }
}
