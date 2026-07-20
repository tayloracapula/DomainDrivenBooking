#include <stdexcept>
#include <string>
enum class EmploymentStatus {
    Active,
    OnLeave,
    Terminated
};

inline EmploymentStatus stringToEmploymentStatus(const std::string &value){
    if (value == "active") return EmploymentStatus::Active;
    if (value == "on leave") return EmploymentStatus::OnLeave;
    if (value == "terminated") return EmploymentStatus::Terminated;

    throw std::runtime_error(
	"Unknown role value: " + value 
    );
}

inline std::string employmentStatusToString(EmploymentStatus status){
    switch (status) {
	case EmploymentStatus::Active: return "Active";
	case EmploymentStatus::OnLeave: return "On Leave";
	case EmploymentStatus::Terminated: return "Terminated";
	default : return "I have no idea how you got here";
    }
}
