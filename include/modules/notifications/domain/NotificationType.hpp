#include "shared/errors/ErrorTypes.hpp"
#include <string>

enum class NotificationType {
    LeaveRequestPendingApproval,
    LeaveRequestApproved,
    LeaveRequestRejected,
    LeaveRequestCancelled,
    StaffMemberCreated,
    StaffMemberUpdated
};

inline NotificationType stringToNotificationType(const std::string &value){
    if (value == "leaverequestpendingapproval") return NotificationType::LeaveRequestPendingApproval;
    if (value == "leaverequestapproved") return NotificationType::LeaveRequestApproved;
    if (value == "leaverequestrejected") return NotificationType::LeaveRequestRejected;
    if (value == "leaverequestcancelled") return NotificationType::LeaveRequestCancelled;
    if (value == "staffmembercreated") return NotificationType::StaffMemberCreated;
    if (value == "staffmemberupdated") return NotificationType::StaffMemberUpdated;

    throw ValidationException(
	"Unknown notification value: " + value
    );
};

inline std::string notificationTypeToString(NotificationType notification){
    switch (notification) {
	case NotificationType::LeaveRequestPendingApproval: return "LeaveRequestPendingApproval";
	case NotificationType::LeaveRequestApproved: return "LeaveRequestApproved";
	case NotificationType::LeaveRequestRejected: return "LeaveRequestRejected";
	case NotificationType::LeaveRequestCancelled: return "LeaveRequestCancelled";
	case NotificationType::StaffMemberCreated: return "StaffMemberCreated";
	case NotificationType::StaffMemberUpdated: return "StaffMemberUpdated";
    	default : return "I have no idea how you got here";
    }
};
