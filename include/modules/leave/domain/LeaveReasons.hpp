#include <string>
enum class LeaveReasons {
    AnnualLeave,
    BankHoliday,
    Sick
};

std::string to_string(LeaveReasons reason); 
