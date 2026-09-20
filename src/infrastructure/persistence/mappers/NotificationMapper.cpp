#include "infrastructure/persistence/mappers/NotificationMapper.hpp"
#include "modules/notifications/domain/Notification.hpp"
#include "shared/tools/StringTools.hpp"
#include "shared/time/TrantorDateConvertion.hpp"
#include <optional>


Notification NotificationMapper::toDomain(const drogon_model::LeaveBooking::Notification &model)
{
    return Notification(
	Identity<NotificationId>::of(model.getValueOfId()),
	Identity<StaffId>::of(model.getValueOfStaffId()),
	model.getValueOfLeaveRequestId().empty()
	    ? std::nullopt
	    : std::optional{
		Identity<LeaveRequestId>::of(model.getValueOfLeaveRequestId())
	    },
	stringToNotificationType(toLowerASCII(model.getValueOfNotificationType())),
	model.getValueOfTitle(),
	model.getValueOfMessage(),
	toTimePoint(model.getValueOfCreatedAt()),
	model.getValueOfIsRead()
    );
}

drogon_model::LeaveBooking::Notification NotificationMapper::toModel(const Notification &entity)
{
    drogon_model::LeaveBooking::Notification model;

    model.setId(entity.id().value());
    
    model.setStaffId(entity.staffId().value());

    if (entity.leaveRequestId().has_value()) {
	model.setLeaveRequestId(entity.leaveRequestId()->value());
    };
    
    model.setNotificationType(notificationTypeToString(entity.notificationType()));
    
    model.setTitle(entity.title());

    model.setMessage(entity.message());

    model.setCreatedAt(toTrantorDateTp(entity.createdAt()));

    model.setIsRead(entity.isRead());

    return model;
}
