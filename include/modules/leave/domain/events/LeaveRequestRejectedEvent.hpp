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
	Identity<StaffId> rejectedBy 
    ) : requestId_(std::move(requestId)),
	staffId_(std::move(staffId)),
	rejectedBy_(std::move(rejectedBy))
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
    Identity<StaffId> rejectedBy_;
};
