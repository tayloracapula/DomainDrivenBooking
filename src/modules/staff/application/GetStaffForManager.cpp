#include "modules/staff/application/services/GetStaffForManager.hpp"
#include "shared/errors/ErrorTypes.hpp"

std::vector<StaffMember> GetStaffForManager::execute(const GetDTO<Identity<StaffId>>& dto){
    try {
	auto staff = staffRepository_.findByManager(dto.id);

	if (staff.empty()) throw NotFoundException("Failed to retrieve staff Member");

	return staff;
    } catch (const std::exception& e) {
	throw;
    }
}
