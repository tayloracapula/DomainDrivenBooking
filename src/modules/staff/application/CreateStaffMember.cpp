#include "modules/staff/application/services/CreateStaffMember.hpp"
#include <exception>

Identity<StaffId> CreateStaffMember::execute(const CreateStaffMemberDTO& dto){
    try {
	std::optional<Identity<StaffId>> managerId;
	if (dto.managerId.has_value()) {
	    auto manager = staffRepository_.findById(Identity<StaffId>::of(dto.managerId.value()));	
	    managerId = manager->id();
	}	
	FullName name(
	    dto.firstName,
	    dto.surName
	);

	Address address(
	    dto.houseNameNumber,
	    dto.street,
	    dto.town,
	    dto.postcode
	);
    
	StaffMember staff(
	    Identity<StaffId>::generate(),
	    name,
	    address,
	    stringToRole(dto.role),
	    EmploymentStatus::Active,
	    managerId
	);

	staffRepository_.create(staff);

	return staff.id();
    } catch (const std::exception& e) {
	throw;
    }
}
