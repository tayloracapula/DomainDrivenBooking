#include "modules/staff/application/services/GetStaffMember.hpp"
#include "shared/errors/ErrorTypes.hpp"

StaffMember GetStaffMember::execute(const GetDTO<Identity<StaffId>>& dto){
    try {
	auto staffMember = staffRepository_.findById(dto.id);

	if (!staffMember) throw NotFoundException("Failed to retrieve staff Member");

	return staffMember.value();

    } catch (const std::exception& e) {
	throw;
    }
}
