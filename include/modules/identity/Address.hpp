#include "../../shared/domain/ValueObject.hpp"
#include "../../shared/domain/DomainAssertions.hpp"
#include <string>

class Address : public ValueObject {
public:
    inline static const std::string HOUSE_NAME_NUMBER_NOT_EMPTY = "House name/number cannot be empty";
    inline static const std::string STREET_NOT_EMPTY = "Street cannot be empty";
    inline static const std::string TOWN_NOT_EMPTY = "Town cannot be empty";
    inline static const std::string POSTCODE_NOT_EMPTY = "Postcode cannot be empty";
    //accessors
    Address(std::string houseNameNumber, std::string street, std::string town, std::string postcode){
	trim(houseNameNumber);
	trim(street);
	trim(town);
	trim(postcode);

	argumentNotEmpty(houseNameNumber, HOUSE_NAME_NUMBER_NOT_EMPTY);
	argumentNotEmpty(street, STREET_NOT_EMPTY);
	argumentNotEmpty(town, TOWN_NOT_EMPTY);
	argumentNotEmpty(postcode, POSTCODE_NOT_EMPTY);

	houseNameNumber_ = houseNameNumber;
	street_ = street;
	town_ = town;
	postcode_ = postcode;
    }

    Address(const Address& address){
	houseNameNumber_ = address.houseNameNumber_;
	street_ = address.street_;
	town_ = address.town_;
	postcode_ = address.postcode_;
    }
    //accessors
    std::string houseNameNumber() {
	return houseNameNumber_;
    }
    std::string street() {
	return street_;
    }
    std::string town() {
	return town_;
    }
    std::string postcode() {
	return postcode_;
    }
private: 
    std::string houseNameNumber_;
    std::string street_;
    std::string town_;
    std::string postcode_;
};
