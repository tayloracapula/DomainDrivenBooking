#include "modules/notifications/domain/Notification.hpp"
#include "modules/notifications/domain/NotificationId.hpp"
#include "shared/domain/IRepository.hpp"
class INotificationRepository : public IRepository<Notification, NotificationId>
{
    virtual ~INotificationRepository() = default;
};
