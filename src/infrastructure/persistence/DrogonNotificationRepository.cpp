#include "infrastructure/persistence/models/Notification.hpp"
#include "infrastructure/persistence/mappers/NotificationMapper.hpp"
#include "infrastructure/persistence/DrogonNotificationRepository.hpp"

using NotificationModel = drogon_model::LeaveBooking::Notification;

void DrogonNotificationRepository::create(const Notification& notification)
{
    NotificationModel model = NotificationMapper::toModel(notification);

    drogon::orm::Mapper<NotificationModel> mapper(db_);

    mapper.insert(model);
}

void DrogonNotificationRepository::update(const Notification& notification)
{
    NotificationModel model = NotificationMapper::toModel(notification);

    drogon::orm::Mapper<NotificationModel> mapper(db_);

    mapper.update(model);
}

std::optional<Notification> DrogonNotificationRepository::findById(const Identity<NotificationId>& id)
{
    drogon::orm::Mapper<NotificationModel> mapper(db_);
    
    try {
	auto model = mapper.findByPrimaryKey(id.value());

	return NotificationMapper::toDomain(model);
    } catch (const drogon::orm::DrogonDbException&) {
	return std::nullopt;
    }

}

std::vector<Notification> DrogonNotificationRepository::findByStaff(const Identity<NotificationId>& id)
{
    drogon::orm::Mapper<NotificationModel> mapper(db_);

    auto models = 
	mapper.findBy(
	    drogon::orm::Criteria(
		NotificationModel::Cols::_staff_id,
		drogon::orm::CompareOperator::EQ,
		id.value()
	    )
	);

    std::vector<Notification> requests;

    for (const auto& model : models){
	requests.push_back(NotificationMapper::toDomain(model));
    }

    return requests;

}

