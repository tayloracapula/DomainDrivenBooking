#include <stdexcept>
#include <string>
enum class RoleType{
    Staff,
    Manager,
    Administrator
};

inline RoleType stringToRole(const std::string &value){

    if (value == "staff") return RoleType::Staff;
    if (value == "manager") return RoleType::Manager;
    if (value == "administrator") return RoleType::Administrator;

    throw std::runtime_error(
	"Unknown role value: " + value 
    );
}

inline std::string roleToString(RoleType role){
    switch (role) {
	case RoleType::Staff: return "Staff";
	case RoleType::Manager: return "Manager";
	case RoleType::Administrator: return "Administrator";
	default : return "I have no idea how you got here";
    }
}
