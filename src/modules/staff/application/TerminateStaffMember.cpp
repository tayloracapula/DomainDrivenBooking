#include "modules/staff/application/services/TerminateStaffMember.hpp"
#include <exception>

Identity<StaffId> TerminateStaffMember::execute(const TerminateStaffMemberDTO& dto){
    try {
	auto staff = staffRepository_.findById(Identity<StaffId>::of(dto.staffId));

	if (!staff) throw std::runtime_error("Failed to retrieve staff Member");

	staff->changeEmploymentStatus(EmploymentStatus::Terminated);

	staffRepository_.update(staff.value());

	return staff->id();
	
    } catch (const std::exception& e) {
	throw;
    }
}
