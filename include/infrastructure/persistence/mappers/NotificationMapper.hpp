#include "infrastructure/persistence/models/Notification.hpp"
#include "modules/notifications/domain/Notification.hpp"

class NotificationMapper{
public:
    static Notification toDomain(
	const drogon_model::LeaveBooking::Notification& model
    );

    static drogon_model::LeaveBooking::Notification toModel(
	const Notification& entity
    );
};
