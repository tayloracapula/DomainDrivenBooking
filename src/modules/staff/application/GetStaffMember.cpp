#include "modules/staff/application/services/GetStaffMember.hpp"
#include <exception>

StaffMember GetStaffMember::execute(const GetDTO<Identity<StaffId>>& dto){
    try {
	auto staffMember = staffRepository_.findById(dto.id);

	if (!staffMember) throw std::runtime_error("Failed to retrieve staff Member");

	return staffMember.value();

    } catch (const std::exception& e) {
	throw;
    }
}
