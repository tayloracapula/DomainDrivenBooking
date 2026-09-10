#include "modules/staff/application/services/TerminateStaffMember.hpp"
#include "shared/errors/ErrorTypes.hpp"

Identity<StaffId> TerminateStaffMember::execute(const TerminateStaffMemberDTO& dto){
    try {
	auto staff = staffRepository_.findById(Identity<StaffId>::of(dto.staffId));

	if (!staff) throw NotFoundException("Failed to retrieve staff Member");

	staff->changeEmploymentStatus(EmploymentStatus::Terminated);

	staffRepository_.update(staff.value());

	return staff->id();
	
    } catch (const std::exception& e) {
	throw;
    }
}
