#include "../../shared/domain/ValueObject.hpp"
#include "../../shared/domain/DomainAssertions.hpp"
#include <string>

class Address : public ValueObject {
public:
    inline static const std::string HOUSE_NAME_NUMBER_NOT_EMPTY = "House name/number cannot be empty";
    inline static const std::string STREET_NOT_EMPTY = "Street cannot be empty";
    inline static const std::string TOWN_NOT_EMPTY = "Town cannot be empty";
    inline static const std::string POSTCODE_NOT_EMPTY = "Postcode cannot be empty";

    Address(std::string houseNameNumber, std::string street, std::string town, std::string postcode){
	trim(houseNameNumber);
	trim(street);
	trim(town);
	trim(postcode);

	argumentNotEmpty(houseNameNumber, HOUSE_NAME_NUMBER_NOT_EMPTY);
	argumentNotEmpty(street, STREET_NOT_EMPTY);
	argumentNotEmpty(town, TOWN_NOT_EMPTY);
	argumentNotEmpty(postcode, POSTCODE_NOT_EMPTY);

	_houseNameNumber = houseNameNumber;
	_street = street;
	_town = town;
	_postcode = postcode;
    }

    Address(Address& address){
	_houseNameNumber = address._houseNameNumber;
	_street = address._street;
	_town = address._town;
	_postcode = address._postcode;
    }

    std::string houseNameNumber() {
	return _houseNameNumber;
    }
    std::string street() {
	return _street;
    }
    std::string town() {
	return _town;
    }
    std::string postcode() {
	return _postcode;
    }
private: 
    std::string _houseNameNumber;
    std::string _street;
    std::string _town;
    std::string _postcode;
};
