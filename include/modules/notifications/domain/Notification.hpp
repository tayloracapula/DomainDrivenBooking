#pragma once

#include "modules/leave/domain/LeaveRequestId.hpp"
#include "modules/notifications/domain/NotificationId.hpp"
#include "modules/notifications/domain/NotificationType.hpp"
#include "modules/staff/domain/StaffId.hpp"
#include "shared/domain/Entity.hpp"
#include <chrono>
#include <optional>
#include <string>
#include <utility>

class Notification : public Entity<Notification, NotificationId>{
public:
    //constructor
    Notification(
	Identity<NotificationId> id,
	Identity<StaffId> staffId,
	std::optional<Identity<LeaveRequestId>> leaveRequestId,
	NotificationType notificationType,
	std::string title,
	std::string message,
	std::chrono::system_clock::time_point createdAt,
	bool isRead
    )
    :	Entity(std::move(id)),
	staffId_(std::move(staffId)),
	leaveRequestId_(std::move(leaveRequestId)),
	notificationType_(std::move(notificationType)),
	title_(std::move(title)),
	message_(std::move(message)),
	createdAt_(std::move(createdAt)),
	isRead_(std::move(isRead))
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
    std::optional<Identity<LeaveRequestId>> leaveRequestId_;
    NotificationType notificationType_;
    std::string message_;
    std::string title_;
    std::chrono::system_clock::time_point createdAt_;
    bool isRead_;
};
