#pragma once

#include <string>
using string = std::string;

struct CreateLeaveRequestDTO {
    string staffId;
    string reason;
    string startDate;
    string endDate;
};
