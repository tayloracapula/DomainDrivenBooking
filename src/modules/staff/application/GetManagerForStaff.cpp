#include "modules/staff/application/services/GetManagerForStaff.hpp"
#include "shared/errors/ErrorTypes.hpp"

StaffMember GetManagerForStaff::execute(const GetDTO<Identity<StaffId>>& dto){
    try {
	auto staffMember = staffRepository_.findManagerOf(dto.id);

	if (!staffMember) throw NotFoundException("Failed to retrieve Manager");

	return staffMember.value();

    } catch (const std::exception& e) {
	throw;
    }
}
