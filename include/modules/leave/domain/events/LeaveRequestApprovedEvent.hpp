#include "modules/leave/domain/LeaveRequestId.hpp"
#include "modules/staff/domain/StaffId.hpp"
#include "shared/domain/Identity.hpp"
#include "shared/events/DomainEvent.hpp"
#include <utility>

class LeaveRequestApprovedEvent : public DomainEvent
{
public:
    explicit LeaveRequestApprovedEvent(
	Identity<LeaveRequestId> requestId,
	Identity<StaffId> staffId,
	Identity<StaffId> approvedBy 
    ) : requestId_(std::move(requestId)),
	staffId_(std::move(staffId)),
	approvedBy_(std::move(approvedBy))
    {}
    const Identity<LeaveRequestId>& requestId() const noexcept
    {
	return requestId_;
    }

    const Identity<StaffId>& staffId() const noexcept
    {
	return staffId_;
    }
private:
    Identity<LeaveRequestId> requestId_;
    Identity<StaffId> staffId_;
    Identity<StaffId> approvedBy_;
};
