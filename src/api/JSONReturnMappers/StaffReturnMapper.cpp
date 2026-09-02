#include "infrastructure/server/api/JSONReturnMappers/StaffResponseMapper.hpp"

Json::Value StaffResponseMapper::toJson(const StaffMember &staff){
    Json::Value json;
    json["id"] = staff.id().value();
    json["name"]["firstName"] = staff.fullName().firstName();
    json["name"]["lastName"] = staff.fullName().surname();
    json["address"]["houseNameNumber"] = staff.address().houseNameNumber();
    json["address"]["street"] = staff.address().street();
    json["address"]["town"] = staff.address().town();
    json["address"]["postcode"] = staff.address().postcode();
    json["role"] = roleToString(staff.role().role());
    if(staff.managerId().has_value()){
	json["managerId"] = staff.managerId()->value();
    }
    else{
	json["managerId"] = Json::nullValue;
    }
    json["employmentStatus"] = employmentStatusToString(staff.employmentStatus());
    return json;
}
