#include "modules/notifications/domain/Notification.hpp"
#include "modules/notifications/domain/NotificationId.hpp"
#include "modules/staff/domain/StaffId.hpp"
#include "shared/domain/IRepository.hpp"
#include "shared/domain/Identity.hpp"
#include <vector>
class INotificationRepository : public IRepository<Notification, NotificationId>
{
public:
    virtual std::vector<Notification> findByStaffId(const Identity<StaffId>& staffId) = 0;

    virtual ~INotificationRepository() = default;
};
