#include "modules/staff/application/services/AssignManager.hpp"
#include <exception>

Identity<StaffId> AssignManager::execute(const AssignManagerDTO& dto){
    try {
	auto staff = staffRepository_.findById(Identity<StaffId>::of(dto.staffId));

	if (!staff) throw std::runtime_error("Failed to retrieve staff Member");

	auto manager = staffRepository_.findById(Identity<StaffId>::of(dto.managerId));

	if (!manager) throw std::runtime_error("Failed to retrieve Manager");

	staff->changeManager(manager->id());

	staffRepository_.update(staff.value());

	return staff->id();

    } catch (const std::exception& e) {
	throw;
    }
}
