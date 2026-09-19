#include "modules/staff/domain/StaffId.hpp"
#include "shared/domain/Identity.hpp"
#include "shared/events/DomainEvent.hpp"
#include "modules/staff/domain/events/StaffUpdateType.hpp"
#include <utility>

class StaffMemberCreatedEvent : public DomainEvent
{
public:
    explicit StaffMemberCreatedEvent(
	Identity<StaffId> staffId,
	StaffUpdateType updateType
    ) 
    :	staffId_(std::move(staffId)),
	updateType_(std::move(updateType))
    {}

    const Identity<StaffId>& staffId() const noexcept
    {
	return staffId_;
    }

    const StaffUpdateType& updateType() const noexcept
    {
	return updateType_;
    }
private:
    Identity<StaffId> staffId_;
    StaffUpdateType updateType_;
};
