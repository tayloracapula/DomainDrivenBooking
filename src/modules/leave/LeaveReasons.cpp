#include "modules/leave/domain/LeaveReasons.hpp"

std::string to_string(LeaveReasons reason) {
    switch (reason) {
	case LeaveReasons::AnnualLeave: return "Annual Leave";
	case LeaveReasons::BankHoliday: return "Bank Holiday";
	case LeaveReasons::Sick: return "Sick Leave";
    }
} 
