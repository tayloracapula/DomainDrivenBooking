#include "infrastructure/server/api/LeaveController.hpp"
#include "json/value.h"
#include <drogon/HttpResponse.h>
#include <string>
#include <trantor/utils/Logger.h>
using namespace drogon;

void LeaveController::getLeaveRequest(
	    const HttpRequestPtr& req,
	    std::function<void (const HttpResponsePtr&)>&& callback,
	    std::string leaveId
	    )
{
    LOG_INFO << "Request Recieved";
    Json::Value json;
    json["leaveIds"] = leaveId;

    auto response = HttpResponse::newHttpJsonResponse(json);

    callback(response);
}
