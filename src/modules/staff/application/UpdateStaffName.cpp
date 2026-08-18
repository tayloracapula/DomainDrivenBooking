#include "modules/staff/application/services/UpdateStaffName.hpp"
#include <exception>

Identity<StaffId> UpdateStaffName::execute(const UpdateStaffNameDTO& dto){
    try {
	auto staff = staffRepository_.findById(Identity<StaffId>::of(dto.staffId));

	if (!staff) throw std::runtime_error("Failed to retrieve staff Member");
	
	FullName name (
	    dto.firstName,
	    dto.surName
	);

	staff->changeFullName(name);

	staffRepository_.update(staff.value());
	
	return staff->id();


    } catch (const std::exception& e) {
	throw;
    }
}
