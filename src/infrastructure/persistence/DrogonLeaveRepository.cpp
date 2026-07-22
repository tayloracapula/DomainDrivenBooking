#include "infrastructure/persistence/DrogonLeaveRepository.hpp"
#include "infrastructure/persistence/models/LeaveRequest.hpp"
#include "infrastructure/persistence/mappers/LeaveMapper.hpp"
#include "shared/domain/Identity.hpp"
#include <drogon/orm/Mapper.h>

using LeaveModel = drogon_model::LeaveBooking::LeaveRequest;

void DrogonLeaveRepository::save(const LeaveRequest& leaveRequest)
{
    LeaveModel model = LeaveMapper::toModel(leaveRequest);

    drogon::orm::Mapper<LeaveModel> mapper(db_);

    mapper.insert(model);
}

std::optional<LeaveRequest> DrogonLeaveRepository::findById(const Identity<LeaveRequestId>& id)
{
    drogon::orm::Mapper<LeaveModel> mapper(db_);
    
    try {
	auto model = mapper.findByPrimaryKey(id.value());

	return LeaveMapper::toDomain(model);
    } catch (const drogon::orm::DrogonDbException&) {
	return std::nullopt;
    }
}
