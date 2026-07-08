#include <string>
using string = std::string;

struct CreateLeaveRequestDTO {
    string staffId;
    string leaveType;
    string reason;
    string startDate;
    string endDate;
};
