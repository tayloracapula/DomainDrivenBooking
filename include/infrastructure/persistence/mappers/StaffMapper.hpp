#include "modules/staff/domain/StaffMember.hpp"
#include "infrastructure/persistence/models/StaffMember.hpp"

class StaffMapper{
public:
    static StaffMember toDomain(
	const drogon_model::LeaveBooking::StaffMember& model
    );

    static drogon_model::LeaveBooking::StaffMember toModel(
	const StaffMember& entity
    );
};
