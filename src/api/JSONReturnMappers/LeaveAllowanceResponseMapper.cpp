#include "infrastructure/server/api/JSONReturnMappers/LeaveAllowanceResponseMapper.hpp"

Json::Value LeaveAllowanceResponseMapper::toJson(const LeaveAllowance &leaveAllowance){
    Json::Value json;
    json["id"] = leaveAllowance.id().value();
    json["staffId"] = leaveAllowance.staffId().value();
    json["annualEntitlement"] = leaveAllowance.annualEntitlement();
    json["remainingDays"] = leaveAllowance.remainingDays();
    return json;
}
