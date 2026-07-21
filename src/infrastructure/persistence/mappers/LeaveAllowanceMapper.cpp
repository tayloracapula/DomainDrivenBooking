#include "infrastructure/persistence/mappers/LeaveAllowanceMapper.hpp"

LeaveAllowance LeaveAllowanceMapper::toDomain(const drogon_model::LeaveBooking::LeaveAllowance &model)
{
    return LeaveAllowance(
	Identity<LeaveAllowanceId>::of(model.getValueOfId()),
	Identity<StaffId>::of(model.getValueOfStaffId()),
	model.getValueOfAnnualEntitlement(),
	model.getValueOfRemainingLeave()
    );
}

drogon_model::LeaveBooking::LeaveAllowance LeaveAllowanceMapper::toModel(const LeaveAllowance &entity)
{
    drogon_model::LeaveBooking::LeaveAllowance model;

    model.setId(entity.id().value());

    model.setStaffId(entity.staffId().value());

    model.setAnnualEntitlement(entity.annualEntitlement());

    model.setRemainingLeave(entity.remainingDays());
    
    return model;
}
