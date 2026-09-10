#include "json/value.h"
#include "shared/errors/ErrorTypes.hpp"
#include <string>
#include <format>
inline void requireString(
    const Json::Value& json,
    const std::string& field
){
    if (!json.isMember(field)) {
	throw ValidationException(std::format("{} is required", field));
    }

    if (!json[field].isString()) {
	throw ValidationException(std::format("{} must be a string", field));
    }
}
