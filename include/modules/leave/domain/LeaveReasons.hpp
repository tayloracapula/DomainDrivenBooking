#include "shared/domain/DomainAssertions.hpp"
#include "shared/domain/ValueObject.hpp"
#include "shared/tools/StringTools.hpp"
#include <string>

class LeaveReason : public ValueObject {
public:
    inline static const std::string REASON_IS_EMPTY = "Leave Reason cannot be empty";
    inline static const std::string REASON_IS_NOT_VALID = "Leave Reason has to be one of the valid options";

    //constructors
    LeaveReason(std::string reason) {
	trim(reason);
	argumentNotEmpty(reason, REASON_IS_EMPTY);

	reason_ = reason;
    }
    LeaveReason(const LeaveReason& leaveReason) {
	reason_ = leaveReason.reason_;
    }
    //accessors
    std::string reason() {
	return reason_;
    }
private:
    std::string reason_;
};
