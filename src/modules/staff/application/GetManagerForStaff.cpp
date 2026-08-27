#include "modules/staff/application/services/GetManagerForStaff.hpp"
#include <exception>

StaffMember GetManagerForStaff::execute(const GetDTO<Identity<StaffId>>& dto){
    try {
	auto staffMember = staffRepository_.findManagerOf(dto.id);

	if (!staffMember) throw std::runtime_error("Failed to retrieve Manager");

	return staffMember.value();

    } catch (const std::exception& e) {
	throw;
    }
}
