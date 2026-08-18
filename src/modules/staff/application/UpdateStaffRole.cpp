#include "modules/staff/application/services/UpdateStaffRole.hpp"
#include <exception>

Identity<StaffId> UpdateStaffRole::execute(const UpdateStaffRoleDTO& dto){
    try {
	auto staff = staffRepository_.findById(Identity<StaffId>::of(dto.staffId));

	if (!staff) throw std::runtime_error("Failed to retrieve staff Member");
	

	staff->changeRole(stringToRole(dto.role));

	staffRepository_.update(staff.value());
	
	return staff->id();

    } catch (const std::exception& e) {
	throw;
    }
}
