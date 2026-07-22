#pragma once

#include <stdexcept>
#include <string>
enum class LeaveStatus {
    Pending,
    Approved,
    Rejected,
    Cancelled
};

inline LeaveStatus stringToLeaveStatus(const std::string &value){
    
    if (value == "approved") return LeaveStatus::Approved;
    if (value == "pending") return LeaveStatus::Pending;
    if (value == "rejected") return LeaveStatus::Rejected;
    if (value == "cancelled") return LeaveStatus::Cancelled;
    
    throw std::runtime_error(
	"Unknown role value: " + value 
    );
}

inline std::string leaveStatusToString(LeaveStatus status){
    switch (status) {
	case LeaveStatus::Approved: return "Approved";
	case LeaveStatus::Pending: return "Pending";
	case LeaveStatus::Rejected: return "Rejected";
	case LeaveStatus::Cancelled: return "Cancelled";
	default : return "I have no idea how you got here";
    }
}
