#include "modules/leave/application/services/CreateLeaveRequest.hpp"
#include "modules/leave/domain/LeaveStatus.hpp"
#include "modules/staff/domain/StaffId.hpp"
#include "shared/time/parseDate.hpp"
#include "shared/errors/ErrorTypes.hpp"
#include <exception>
#include <stdexcept>

Identity<LeaveRequestId> CreateLeaveRequest::execute(const CreateLeaveRequestDTO& dto){
    try{
	auto leaveAllowance = leaveAllowanceRepository_.findByStaff(Identity<StaffId>::of(dto.staffId));

	if (!leaveAllowance) throw NotFoundException("Failed to retrieve leave allowance");

	DateRange dateRange(
		parseDate(dto.startDate),
		parseDate(dto.endDate)
	);
	
	if (dateRange.days() > leaveAllowance->remainingDays()) {
	    throw ValidationException("Not enough leave remaining");
	}

	LeaveRequest request(
	    Identity<LeaveRequestId>::generate(),
	    Identity<StaffId>::of(dto.staffId),
	    dateRange,
	    LeaveReason(dto.reason),
	    LeaveStatus::Pending
	);


	leaveRepository_.create(request);

	return request.id();

    }catch(const std::exception& e){
	throw;
    }
}
