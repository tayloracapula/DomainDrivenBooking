#pragma once

#include "modules/staff/domain/StaffId.hpp"
#include "modules/staff/domain/StaffMember.hpp"
#include "shared/domain/Entity.hpp"
#include "shared/domain/Identity.hpp"
#include "DateRange.hpp"
#include "LeaveRequestId.hpp"
#include "LeaveReasons.hpp"
#include "LeaveStatus.hpp"


class LeaveRequest : public Entity<LeaveRequest, LeaveRequestId>{
public:
    //constructor
    LeaveRequest(
	Identity<LeaveRequestId> id,
	Identity<StaffId> staffId,
	DateRange period,
	LeaveReason reason,
	LeaveStatus status
    )
    :	Entity(std::move(id)),
	staffId_(std::move(staffId)),
	period_(std::move(period)),
	reason_(std::move(reason)),
	status_(std::move(status))
    {}
    //operations
    void approve(StaffMember approvingManager);
    void reject(StaffMember denyingManager);
    void cancel(StaffMember cancellingUser);
    //accessors
    const Identity<StaffId>& staffId() const noexcept {
	return staffId_;
    }    
    const DateRange& dateRange() const noexcept {
	return period_;
    }
    const LeaveReason& reason() const noexcept {
	return reason_;
    }
    const LeaveStatus& status() const noexcept {
	return status_;
    }

    bool isCancelled() {
	return status_ == LeaveStatus::Cancelled;
    }
    bool isApproved() {
	return status_ == LeaveStatus::Approved;
    }
    bool isPending() {
	return status_ == LeaveStatus::Pending;
    }
    bool isRejected() {
	return status_ == LeaveStatus::Rejected;
    }

private:
    Identity<StaffId> staffId_;
    DateRange period_;
    LeaveReason reason_;
    LeaveStatus status_;
};
