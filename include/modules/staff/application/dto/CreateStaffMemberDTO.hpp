#include <optional>
#include <string>
using string = std::string;

struct CreateStaffMemberDTO{
    string firstName; 
    string surname;
    string houseNameNumber;
    string town;
    string postcode;
    string role;
    std::optional<string> managerId;
};
