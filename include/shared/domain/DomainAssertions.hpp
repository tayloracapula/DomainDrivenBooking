#include <stdexcept>
#include <string>
#include "../tools/StringTools.hpp"

inline void argumentNotEmpty(std::string value, std::string errorMessage) {
    if (trim_copy(value).empty()) {
	throw std::invalid_argument(errorMessage);
    }
}

inline void argumentLength(std::string value, int min, int max, std::string errorMessage) {
    int length = trim_copy(value).length();
    if (length < min || length > max) {
	throw std::invalid_argument(errorMessage);
    }
}
