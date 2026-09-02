#include "infrastructure/server/api/LeaveController.hpp"
#include "infrastructure/server/ApplicationServices.hpp"
#include "infrastructure/server/api/JSONReturnMappers/LeaveResponseMapper.hpp"
#include "modules/leave/application/dto/CancelLeaveRequestDTO.hpp"
#include "modules/leave/application/dto/CreateLeaveRequestDTO.hpp"
#include "modules/leave/domain/LeaveRequestId.hpp"
#include "shared/domain/Identity.hpp"
#include "shared/server/GetDTO.hpp"
#include "shared/tools/ResponseTools.hpp"
#include <drogon/HttpResponse.h>
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
    GetDTO<Identity<LeaveRequestId>> dto{
	Identity<LeaveRequestId>::of(leaveId)
    };

    auto leaveRequest =  ApplicationServices::instance()
	    .getLeaveRequest()
	    .execute(dto);
    callback(HttpResponse::newHttpJsonResponse(
	LeaveResponseMapper::toJson(leaveRequest)
    ));
	    
}

void api::Leave::getLeaveForStaff(
	    const HttpRequestPtr& req,
	    std::function<void (const HttpResponsePtr&)>&& callback,
	    std::string staffId
	    ){
    GetDTO<Identity<StaffId>> dto{
	Identity<StaffId>::of(staffId)
    };

    auto leaveRequests = ApplicationServices::instance()
		.getLeaveForStaff()
		.execute(dto);

    Json::Value response(
	Json::arrayValue);

    for (const auto& leave: leaveRequests) {
	response.append(LeaveResponseMapper::toJson(leave));
    }
    callback(
	HttpResponse::newHttpJsonResponse(response)
    );
}

void api::Leave::cancelLeaveRequest(
	    const HttpRequestPtr& req,
	    std::function<void (const HttpResponsePtr&)>&& callback,
	    std::string leaveId
	    ){
    CancelLeaveRequestDTO dto;

    dto.leaveRequestId = leaveId;

    auto id = ApplicationServices::instance()
	    .cancelLeaveRequest()
	    .execute(dto);

    callback(createIdResponse(id.value()));
    
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

