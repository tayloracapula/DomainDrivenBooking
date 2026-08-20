#include "infrastructure/server/api/StaffController.hpp"
#include "infrastructure/server/ApplicationServices.hpp"
#include "shared/tools/ResponseTools.hpp"

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

}

