#pragma once

#include <string>
using string = std::string;

struct ApproveDenyLeaveRequestDTO{
    string leaveRequestId;
    string ManagerId;
};
