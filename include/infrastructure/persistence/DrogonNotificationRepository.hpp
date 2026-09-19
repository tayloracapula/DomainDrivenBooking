#include "modules/notifications/application/repositoties/INotificationRepository.hpp"
#include "modules/notifications/domain/NotificationId.hpp"
#include <drogon/orm/DbClient.h>

class DrogonNotificationRepository : public INotificationRepository{
public:
    explicit DrogonNotificationRepository(
	drogon::orm::DbClientPtr db)
	: db_(std::move(db))
    {}

    void create(const Notification& leaveRequest) override;

    void update(const Notification& leaveRequest) override;

    std::optional<Notification> findById(const Identity<NotificationId>& id) override;

    std::vector<Notification> findByStaff(const Identity<NotificationId>& id);
private:
    drogon::orm::DbClientPtr db_;
};
