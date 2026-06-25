#pragma once
#include "ValueObject.hpp"
#include <stdexcept>
#include <string>
#include <strstream>
#include <utility>
#include <chrono>

template <typename Ttag>
class Identity : public ValueObject{
public:
    inline static const std::string IDENTITY_NOT_EMPTY = "Identity value cannot be empty";

    static Identity<Ttag> generate() {
	return Identity<Ttag>(generate_id());
    }

    static Identity<Ttag> of(std::string value) {
	return Identity<Ttag>(std::move(value));
    }

    const std::string& value() const noexcept {
	return value_;
    }

    bool operator==(const Identity& other) const = default;
private:

    explicit Identity(std::string value) : value_(std::move(value)) {
	if (value_.empty()) {
	    throw std::invalid_argument(IDENTITY_NOT_EMPTY);
	}
    }

    static std::string generate_id() {
	using namespace std::chrono;

	auto now = system_clock::now().time_since_epoch();
	auto millis = duration_cast<milliseconds>(now).count();

	std::ostrstream ss;
	ss << millis;
	
	return ss.str();
    }

    std::string value_;
};
