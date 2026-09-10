#include "modules/leave/domain/LeaveRequest.hpp"
#include "json/value.h"
class LeaveResponseMapper {
public:
    static Json::Value toJson(const LeaveRequest& leave);
};
