#include "modules/staff/application/services/AssignManager.hpp"
#include "shared/errors/ErrorTypes.hpp"

Identity<StaffId> AssignManager::execute(const AssignManagerDTO& dto){
    try {
	auto staff = staffRepository_.findById(Identity<StaffId>::of(dto.staffId));

	if (!staff) throw NotFoundException("Failed to retrieve staff Member");

	auto manager = staffRepository_.findById(Identity<StaffId>::of(dto.managerId));

	if (!manager) throw NotFoundException("Failed to retrieve Manager");

	staff->changeManager(manager->id());

	staffRepository_.update(staff.value());

	return staff->id();

    } catch (const std::exception& e) {
	throw;
    }
}
