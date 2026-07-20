#include "modules/leave/domain/LeaveAllowance.hpp"
#include "infrastructure/persistence/models/LeaveAllowance.hpp"

class LeaveAllowanceMapper {
public:
    static LeaveAllowance toDomain(
	const drogon_model::LeaveBooking::LeaveAllowance& model
    );
    static drogon_model::LeaveBooking::LeaveAllowance toModel(
	const LeaveAllowance& entity
    );
};
