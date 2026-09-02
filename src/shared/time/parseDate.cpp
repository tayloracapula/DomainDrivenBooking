#include "shared/time/parseDate.hpp"
#include <chrono>
#include <sstream>
#include <stdexcept>
std::chrono::year_month_day parseDate(const std::string& value)
{
    int year, month, day;

    char dash1, dash2;

    std::stringstream stream(value);

    stream >> year >> dash1 >> month >> dash2 >> day;

    if (!stream || dash1 != '-' || dash2 != '-') {
	throw std::runtime_error("Invalid Date Format");
    }

    return std::chrono::year{year}
	/  std::chrono::month{static_cast<unsigned>(month)}
	/  std::chrono::day{static_cast<unsigned>(day)};
}

std::string dateToString(const std::chrono::year_month_day& date)
{
    return std::format(
	"{:04}/{:02}/{:02}",
	int(date.year()),
	unsigned(date.month()),
	unsigned(date.day())
    );
}
