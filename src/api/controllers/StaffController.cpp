#include "infrastructure/server/api/StaffController.hpp"
#include "infrastructure/server/ApplicationServices.hpp"
#include "infrastructure/server/api/JSONReturnMappers/StaffResponseMapper.hpp"
#include "modules/staff/domain/StaffId.hpp"
#include "shared/domain/Identity.hpp"
#include "shared/server/GetDTO.hpp"
#include "shared/tools/ResponseTools.hpp"
#include "json/value.h"
#include <drogon/HttpResponse.h>

using namespace drogon;

void api::Staff::createStaffMember(
	const HttpRequestPtr& req,
	std::function<void (const HttpResponsePtr&)>&& callback
    ){
    auto json = req->getJsonObject();

    CreateStaffMemberDTO dto;

    dto.firstName = (*json)["firstName"].asString();
    dto.surName = (*json)["surname"].asString();
    dto.houseNameNumber = (*json)["houseNameNumber"].asString();
    dto.street = (*json)["street"].asString();
    dto.town = (*json)["town"].asString();
    dto.postcode = (*json)["postcode"].asString();
    dto.role = (*json)["role"].asString();   

    if ((*json).isMember("managerId")) {
	dto.firstName = (*json)["firstName"].asString();
    }

    auto id = ApplicationServices::instance()
		.createStaffMember()
		.execute(dto);

    callback(createIdResponse(id.value()));
}

void api::Staff::getStaffMember(
	    const HttpRequestPtr& req,
	    std::function<void (const HttpResponsePtr&)>&& callback,
	    std::string staffId
	    ){
    GetDTO<Identity<StaffId>> dto{
	Identity<StaffId>::of(staffId)
    };

    auto staff = ApplicationServices::instance()
		.getStaffMember()
		.execute(dto);
    callback(HttpResponse::newHttpJsonResponse(
	StaffResponseMapper::toJson(staff)
    ));
}

void api::Staff::getStaffForManager(
	    const HttpRequestPtr& req,
	    std::function<void (const HttpResponsePtr&)>&& callback,
	    std::string staffId
	    ){
    GetDTO<Identity<StaffId>> dto{
	Identity<StaffId>::of(staffId)
    };

    auto staffMembers = ApplicationServices::instance()
		.getStaffForManager()
		.execute(dto);

    Json::Value response(
	Json::arrayValue);

    for (const auto& staff : staffMembers) {
	response.append(StaffResponseMapper::toJson(staff));
    }
    callback(
	HttpResponse::newHttpJsonResponse(response)
    );
    
}

void api::Staff::getManagerForStaff(
	const HttpRequestPtr& req,
	std::function<void (const HttpResponsePtr&)>&& callback,
	std::string staffId
	){
    GetDTO<Identity<StaffId>> dto{
	Identity<StaffId>::of(staffId)
    };

    auto manager = ApplicationServices::instance()
		.getManagerForStaff()
		.execute(dto);
    callback(HttpResponse::newHttpJsonResponse(
	StaffResponseMapper::toJson(manager)
	)
    );
}

void api::Staff::updateName(
	    const HttpRequestPtr& req,
	    std::function<void (const HttpResponsePtr&)>&& callback,
	    std::string staffId
	    ){
    auto json = req->getJsonObject();

    UpdateStaffNameDTO dto;
    dto.staffId = staffId; 
    dto.firstName = (*json)["firstName"].asString();
    dto.surName = (*json)["surName"].asString();

    auto id = ApplicationServices::instance()
	    .updateStaffName()
	    .execute(dto);

    callback(createIdResponse(id.value()));
}


void api::Staff::updateRole(
	    const HttpRequestPtr& req,
	    std::function<void (const HttpResponsePtr&)>&& callback,
	    std::string staffId
	){
    auto json = req->getJsonObject();

    UpdateStaffRoleDTO dto;
    dto.staffId = staffId;  
    dto.role = (*json)["role"].asString();

    auto id = ApplicationServices::instance()
	    .updateStaffRole()
	    .execute(dto);

    callback(createIdResponse(id.value()));
}

void api::Staff::terminateEmployee(
	    const HttpRequestPtr& req,
	    std::function<void (const HttpResponsePtr&)>&& callback,
	    std::string staffId
	){

    TerminateStaffMemberDTO dto;

    dto.staffId =  staffId;   

    auto id = ApplicationServices::instance()
	    .terminateStaffMember()
	    .execute(dto);	
}

