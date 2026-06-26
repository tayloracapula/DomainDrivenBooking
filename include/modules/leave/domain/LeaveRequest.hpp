#include "modules/staff/domain/StaffId.hpp"
#include "shared/domain/Entity.hpp"
#include "shared/domain/Identity.hpp"
#include "DateRange.hpp"
#include "LeaveRequestId.hpp"
#include "LeaveReasons.hpp"



class LeaveRequest : public Entity<LeaveRequest, LeaveRequestId>{
public:
    LeaveRequest(
	Identity<LeaveRequestId> id,
	Identity<StaffId> staffId,
	DateRange period,
	LeaveReasons reason
    )
    :	Entity(std::move(id)),
	staffId_(std::move(staffId)),
	period_(std::move(period)),
	reason_(std::move(reason)){}

private:
    Identity<StaffId> staffId_;
    DateRange period_;
    LeaveReasons reason_;
};
