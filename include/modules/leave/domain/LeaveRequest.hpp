#include "modules/staff/domain/StaffId.hpp"
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
	LeaveReason reason
    )
    :	Entity(std::move(id)),
	staffId_(std::move(staffId)),
	period_(std::move(period)),
	reason_(std::move(reason)),
	status_(LeaveStatus::Pending)
    {}
    //operations
    void approve();
    void reject();
    void cancel();
    //accessors
    

private:
    Identity<StaffId> staffId_;
    DateRange period_;
    LeaveReason reason_;
    LeaveStatus status_;
};
