#include "infrastructure/persistence/mappers/StaffMapper.hpp"
#include "modules/staff/domain/StaffId.hpp"
#include "modules/staff/domain/StaffMember.hpp"
#include <optional>

StaffMember StaffMapper::toDomain(const drogon_model::LeaveBooking::StaffMember &model)
{
    return StaffMember(
	Identity<StaffId>::of(model.getValueOfId()),
	FullName(
	    model.getValueOfFirstName(), 
	    model.getValueOfSurname()
	),
	Address(
	    model.getValueOfHouseNameNumber(),
	    model.getValueOfStreet(),
	    model.getValueOfTown(),
	    model.getValueOfPostcode()
	),
	Role(
	    stringToRole(
		model.getValueOfRole()
	    )
	),
	EmploymentStatus(
	    stringToEmploymentStatus(
		model.getValueOfEmploymentStatus()
	    )
	),
	model.getValueOfManagerId().empty()
	    ? std::nullopt
	    : std::optional{
		Identity<StaffId>::of(
		    model.getValueOfManagerId()
		)
	    }

    );
}
