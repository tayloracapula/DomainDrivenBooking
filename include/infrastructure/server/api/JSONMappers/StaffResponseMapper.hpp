#include "modules/staff/domain/StaffMember.hpp"
#include "json/value.h"
class StaffResponseMapper {
public:
    static Json::Value toJson(const StaffMember& staff);
};
