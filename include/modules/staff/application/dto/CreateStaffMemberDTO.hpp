#include <optional>
#include <string>
using string = std::string;

struct CreateStaffMemberDTO{
    string firstName; 
    string surName;
    string houseNameNumber;
    string street;
    string town;
    string postcode;
    string role;
    std::optional<string> managerId;
};
