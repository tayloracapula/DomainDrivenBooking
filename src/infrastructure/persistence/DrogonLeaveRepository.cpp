#include "infrastructure/persistence/DrogonLeaveRepository.hpp"
#include "infrastructure/persistence/models/LeaveRequest.hpp"
#include "infrastructure/persistence/mappers/LeaveMapper.hpp"
#include <drogon/orm/Criteria.h>
#include <drogon/orm/Mapper.h>
#include <vector>

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

std::vector<LeaveRequest> DrogonLeaveRepository::findByStaff(const Identity<StaffId>& id)
{
    drogon::orm::Mapper<LeaveModel> mapper(db_);

    auto models = 
	mapper.findBy(
	    drogon::orm::Criteria(
		LeaveModel::Cols::_staff_id,
		drogon::orm::CompareOperator::EQ,
		id.value()
	    )
	);

    std::vector<LeaveRequest> requests;

    for (const auto& model : models){
	requests.push_back(LeaveMapper::toDomain(model));
    }

    return requests;
}
