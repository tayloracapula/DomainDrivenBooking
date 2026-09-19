#pragma once

#include "modules/notifications/domain/NotificationId.hpp"
#include "modules/notifications/domain/NotificationType.hpp"
#include "modules/staff/domain/StaffId.hpp"
#include "shared/domain/Entity.hpp"
#include <chrono>
#include <string>
#include <utility>

class Notification : public Entity<Notification, NotificationId>{
public:
    //constructor
    Notification(
	Identity<NotificationId> id,
	Identity<StaffId> staffId,
	NotificationType notificationType,
	std::string message
    )
    :	Entity(std::move(id)),
	staffId_(std::move(staffId)),
	notificationType_(std::move(notificationType)),
	message_(std::move(message)),
	createdAt_(std::chrono::system_clock::now()),
	isRead_(false)
    {}
    //operators
    void markRead() {
	isRead_ = true;
    }
    void markUnread() {
	isRead_ = false;
    }
    //accessors
    const Identity<StaffId>& staffId() const noexcept {
	return staffId_;
    }
    const NotificationType& notificationType() const noexcept {
	return notificationType_;
    }
    const std::string& message() const noexcept {
	return message_;
    }
    const std::chrono::system_clock::time_point createdAt() const noexcept {
	return createdAt_;
    }
    const bool& isRead() const noexcept {
	return isRead_;
    }

private:
    Identity<StaffId> staffId_;
    NotificationType notificationType_;
    std::string message_;
    std::chrono::system_clock::time_point createdAt_;
    bool isRead_;
};
