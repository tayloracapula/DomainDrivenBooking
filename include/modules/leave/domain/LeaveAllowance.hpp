#include "modules/staff/domain/StaffMember.hpp"
#include "LeaveAllowanceId.hpp"
#include "shared/domain/Identity.hpp"
class LeaveAllowance : public Entity<LeaveAllowance, LeaveAllowanceId>{
public:
    //constructor

    //operations

    //accessors

private:
    Identity<StaffId> staffId_;
    int annualEntitlement_;
    int remainingDays_;
};
