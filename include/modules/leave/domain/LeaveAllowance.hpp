#pragma once
#include "modules/staff/domain/StaffId.hpp"
#include "shared/domain/Entity.hpp"
#include "LeaveAllowanceId.hpp"
#include "shared/domain/Identity.hpp"
class LeaveAllowance : public Entity<LeaveAllowance, LeaveAllowanceId>{
public:
    //constructor
    LeaveAllowance(
	Identity<LeaveAllowanceId> id,
	Identity<StaffId> staffId
    )
    :
	Entity(std::move(id)),
	staffId_(std::move(staffId)),
	annualEntitlement_(25)
    {}
    //operations
    void deductDays(int days);
    void addDays(int days);
    void resetAllowance();
    //accessors
    const Identity<StaffId>& staffId() const noexcept {
	return staffId_;
    }
    const int& annualEntitlement() const noexcept {
	return annualEntitlement_;
    }
    const int& remainingDays() const noexcept {
	return remainingDays_;
    }
private:
    Identity<StaffId> staffId_;
    int annualEntitlement_;
    int remainingDays_;
};
