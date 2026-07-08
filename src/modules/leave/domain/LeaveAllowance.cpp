#include "modules/leave/domain/LeaveAllowance.hpp"

void LeaveAllowance::deductDays(int days) {
    remainingDays_ -= days;
}

void LeaveAllowance::addDays(int days) {
    remainingDays_ += days;
}

void LeaveAllowance::resetAllowance() {
    remainingDays_ = annualEntitlement_;
}
