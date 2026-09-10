#include "modules/leave/domain/LeaveAllowance.hpp"
#include "json/value.h"
class LeaveAllowanceResponseMapper {
public:
    static Json::Value toJson(const LeaveAllowance& leaveAllowance);
};
