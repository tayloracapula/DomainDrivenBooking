#include "modules/leave/domain/LeaveRequestId.hpp"
#include "modules/staff/domain/StaffId.hpp"
#include "shared/domain/Identity.hpp"
#include "shared/events/DomainEvent.hpp"
#include <utility>

class LeaveRequestCancelledEvent : public DomainEvent
{
public:
    explicit LeaveRequestCancelledEvent(
	Identity<LeaveRequestId> requestId,
	Identity<StaffId> staffId
    ) : requestId_(std::move(requestId)),
	staffId_(std::move(staffId))
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
};
