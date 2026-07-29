#include <stdexcept>
#include <string>
enum class EmploymentStatus {
    Active,
    Suspended,
    Terminated
};

inline EmploymentStatus stringToEmploymentStatus(const std::string &value){
    if (value == "active") return EmploymentStatus::Active;
    if (value == "suspended") return EmploymentStatus::Suspended;
    if (value == "terminated") return EmploymentStatus::Terminated;

    throw std::runtime_error(
	"Unknown role value: " + value 
    );
}

inline std::string employmentStatusToString(EmploymentStatus status){
    switch (status) {
	case EmploymentStatus::Active: return "Active";
	case EmploymentStatus::Suspended: return "Suspended";
	case EmploymentStatus::Terminated: return "Terminated";
	default : return "I have no idea how you got here";
    }
}
