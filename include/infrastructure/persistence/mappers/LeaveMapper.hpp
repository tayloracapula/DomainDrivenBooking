#include "modules/leave/domain/LeaveRequest.hpp"
#include "infrastructure/persistence/models/LeaveRequest.hpp"

class LeaveMapper {
public:
    static LeaveRequest toDomain(
	const drogon_model::LeaveBooking::LeaveRequest& model
    );
    static drogon_model::LeaveBooking::LeaveRequest toModel(
	const LeaveRequest& entity
    );
};
