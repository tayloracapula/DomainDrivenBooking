#include "infrastructure/persistence/mappers/StaffMapper.hpp"
#include "modules/staff/domain/StaffId.hpp"
#include "modules/staff/domain/StaffMember.hpp"
#include "shared/tools/StringTools.hpp"
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
		toLowerASCII(model.getValueOfRole())
	    )
	),
	EmploymentStatus(
	    stringToEmploymentStatus(
		toLowerASCII(model.getValueOfEmploymentStatus())
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

drogon_model::LeaveBooking::StaffMember StaffMapper::toModel(const StaffMember &entity)
{
    drogon_model::LeaveBooking::StaffMember model;
    
    model.setId(entity.id().value());
    
    model.setFirstName(entity.fullName().firstName());

    model.setSurname(entity.fullName().surname());
    
    model.setHouseNameNumber(entity.address().houseNameNumber());
    
    model.setStreet(entity.address().street());

    model.setTown(entity.address().town());

    model.setPostcode(entity.address().postcode());

    model.setRole(roleToString(entity.role().role()));

    model.setEmploymentStatus(employmentStatusToString(entity.employmentStatus()));

    if (entity.managerId().has_value()) {
	model.setManagerId(entity.managerId()->value());
    }
    return model;
}
