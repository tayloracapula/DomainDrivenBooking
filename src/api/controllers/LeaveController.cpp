#include "infrastructure/server/api/LeaveController.hpp"
#include "infrastructure/server/ApplicationServices.hpp"
#include "modules/leave/application/dto/CreateLeaveRequestDTO.hpp"
#include "shared/tools/ResponseTools.hpp"
#include <trantor/utils/Logger.h>

using namespace drogon;

void api::Leave::createLeaveRequest(
	    const HttpRequestPtr& req,
	    std::function<void (const HttpResponsePtr&)>&& callback
    ){
    LOG_INFO << "Request Recieved";
    auto json = req->getJsonObject();

    CreateLeaveRequestDTO dto;

    dto.staffId = (*json)["staffId"].asString();
    dto.startDate = (*json)["startDate"].asString();
    dto.endDate = (*json)["endDate"].asString();
    dto.reason = (*json)["reason"].asString();

    auto id = ApplicationServices::instance()
		.createLeaveRequest()
		.execute(dto);

    callback(createIdResponse(id.value()));

}

void api::Leave::getLeaveRequest(
	    const HttpRequestPtr& req,
	    std::function<void (const HttpResponsePtr&)>&& callback,
	    std::string leaveId
	    ){
}

void api::Leave::getLeaveForStaff(
	    const HttpRequestPtr& req,
	    std::function<void (const HttpResponsePtr&)>&& callback,
	    std::string staffId
	    ){

}

void api::Leave::cancelLeaveRequest(
	    const HttpRequestPtr& req,
	    std::function<void (const HttpResponsePtr&)>&& callback,
	    std::string leaveId
	    ){

}

void api::Leave::approveLeaveRequest(
	    const HttpRequestPtr& req,
	    std::function<void (const HttpResponsePtr&)>&& callback,
	    std::string leaveId
	    ){
    auto json = req->getJsonObject();

    ApproveDenyLeaveRequestDTO dto;

    dto.leaveRequestId = leaveId;
    dto.ManagerId = (*json)["managerId"].asString();

    auto id = ApplicationServices::instance()
		.approveLeaveRequest()
		.execute(dto);

    callback(createIdResponse(id.value()));
    
}

void api::Leave::denyLeaveRequest(
	    const HttpRequestPtr& req,
	    std::function<void (const HttpResponsePtr&)>&& callback,
	    std::string leaveId
	    ){
    auto json = req->getJsonObject();

    ApproveDenyLeaveRequestDTO dto;

    dto.leaveRequestId = leaveId;
    dto.ManagerId = (*json)["managerId"].asString();

    auto id = ApplicationServices::instance()
		.denyLeaveRequest()
		.execute(dto);

    callback(createIdResponse(id.value()));

}

