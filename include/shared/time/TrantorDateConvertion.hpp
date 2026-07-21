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
