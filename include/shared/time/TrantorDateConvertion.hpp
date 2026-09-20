#include <bits/chrono.h>
#include <chrono>
#include <trantor/utils/Date.h>


inline std::chrono::year_month_day toYearMonthDay(const trantor::Date& date){
    auto tp = std::chrono::system_clock::time_point(std::chrono::microseconds(date.microSecondsSinceEpoch()));
    auto days = std::chrono::floor<std::chrono::days>(tp);
    return std::chrono::year_month_day{days};
}

inline trantor::Date toTrantorDate(const std::chrono::year_month_day& date) {
    auto days = std::chrono::sys_days{date};
    
    auto micros = std::chrono::duration_cast<std::chrono::microseconds>(days.time_since_epoch());

    return trantor::Date(micros.count());
}

inline std::chrono::system_clock::time_point toTimePoint(const trantor::Date& date)
{
    return std::chrono::system_clock::time_point{
	std::chrono::microseconds{
	    date.microSecondsSinceEpoch()
	}
    };
}

inline trantor::Date toTrantorDateTp(const std::chrono::system_clock::time_point& timePoint)
{
    const auto microseconds = 
	std::chrono::duration_cast<std::chrono::microseconds>(
	    timePoint.time_since_epoch()
	).count();

    return trantor::Date{microseconds};
}
