#include "shared/domain/ValueObject.hpp"
#include <chrono>
#include <stdexcept>
#include <string>
class DateRange : public ValueObject {
public:
    using Date = std::chrono::year_month_day;
    inline static const std::string INVALID_DATE = "DateRange contains an invalid date";
    inline static const std::string END_BEFORE_START = "End date cannot be before start date";
    //constructors
    DateRange(Date startDate, Date endDate)
    {
	if (!startDate.ok() || !endDate.ok()) {
	    throw std::invalid_argument(INVALID_DATE);
	}
	if (std::chrono::sys_days(startDate) < std::chrono::sys_days(endDate)) {
	    throw std::invalid_argument(END_BEFORE_START);
	}

	startDate_ = startDate;
	endDate_ = endDate;
    }
    DateRange(const DateRange& other){
	startDate_ = other.startDate_;
	endDate_ = other.endDate_;
    }
    //accessors
    Date startDate() {
	return startDate_; 
    }
    Date endDate() {
	return endDate_;
    }
    
private:
    Date startDate_;
    Date endDate_;
};
