#include <chrono>
#include <string>
std::chrono::year_month_day parseDate(const std::string& value);

std::string dateToString(const std::chrono::year_month_day& date);
