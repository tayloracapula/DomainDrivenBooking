#include "../../shared/domain/ValueObject.hpp"
#include "../../shared/domain/DomainAssertions.hpp"
#include <string>
#include <format>


class FullName : public ValueObject {
public: 
    static constexpr int MAX_FIRST_NAME_LENGTH = 20;
    static constexpr int MAX_LAST_NAME_LENGTH = 20;
    
    inline static const std::string FIRST_NAME_NOT_EMPTY = "First Name Cannot Be Empty";
    inline static const std::string SURNAME_NOT_EMPTY = "Surname Cannot Be Empty";
    inline static const std::string FULL_NAME_CANNOT_BE_NULL = "Full Name to copy cannot be null";

    inline static const std::string FIRST_NAME_LENGTH = std::format("First Name must be between 1 and {} characters", MAX_LAST_NAME_LENGTH);
    inline static const std::string SURNAME_LENGTH = std::format("Surname must be between 1 and {} characters", MAX_LAST_NAME_LENGTH);
    //constructors
    FullName(std::string firstName, std::string surname) {
	trim(firstName);
	trim(surname);
	argumentNotEmpty(firstName, FIRST_NAME_NOT_EMPTY);
	argumentNotEmpty(surname, SURNAME_NOT_EMPTY);

	argumentLength(firstName,1 , MAX_FIRST_NAME_LENGTH, FIRST_NAME_LENGTH);
	argumentLength(surname,1 , MAX_LAST_NAME_LENGTH, SURNAME_LENGTH);

	_firstName = firstName ;
	_surname = surname;
    }
    FullName(const FullName& fullName) {
	_firstName = fullName._firstName;
	_surname = fullName._surname;
    }

    std::string firstName() {
	return _firstName;
    }

    std::string surname() {
	return _surname;
    }

private:
    std::string _surname;
    std::string _firstName;
};
