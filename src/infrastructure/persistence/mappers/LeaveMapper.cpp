#include "infrastructure/persistence/mappers/LeaveMapper.hpp"
#include "shared/time/TrantorDateConvertion.hpp"


LeaveRequest LeaveMapper::toDomain(const drogon_model::LeaveBooking::LeaveRequest &model)
{
    return LeaveRequest(
	Identity<LeaveRequestId>::of(model.getValueOfId()),
	Identity<StaffId>::of(model.getValueOfStaffId()),
	DateRange(
	    toYearMonthDay(model.getValueOfStartDate()),
	    toYearMonthDay(model.getValueOfEndDate())
	),
	LeaveReason(
	    model.getValueOfLeaveReason()
	)
    );
}

drogon_model::LeaveBooking::LeaveRequest LeaveMapper::toModel(const LeaveRequest &entity)
{
    drogon_model::LeaveBooking::LeaveRequest model;
    
    model.setId(entity.id().value());

    model.setStaffId(entity.staffId().value());

    model.setStartDate(toTrantorDate(entity.dateRange().startDate()));

    model.setEndDate(toTrantorDate(entity.dateRange().endDate()));

    model.setLeaveReason(entity.reason().reason());

    return model;
}
