#include "modules/staff/domain/StaffId.hpp"
#include "shared/domain/Identity.hpp"
#include "shared/events/DomainEvent.hpp"
#include <utility>

class StaffMemberCreatedEvent : public DomainEvent
{
public:
    explicit StaffMemberCreatedEvent(
	Identity<StaffId> staffId
    ) 
    :	staffId_(std::move(staffId))
    {}

    const Identity<StaffId>& staffId() const noexcept
    {
	return staffId_;
    }
private:
    Identity<StaffId> staffId_;
};
