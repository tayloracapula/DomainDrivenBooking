#include "infrastructure/server/api/JSONReturnMappers/LeaveResponseMapper.hpp"
#include "shared/time/parseDate.hpp"
#include <ctime>

Json::Value LeaveResponseMapper::toJson(const LeaveRequest &leave){
    Json::Value json;
    json["id"] = leave.id().value();
    json["staffId"] = leave.staffId().value();
    json["period"]["startDate"] = dateToString(leave.dateRange().startDate()); 
    json["period"]["endDate"] = dateToString(leave.dateRange().endDate());
    json["reason"] = leave.reason().reason();
    json["status"] = leaveStatusToString(leave.status());
    return json;
}
