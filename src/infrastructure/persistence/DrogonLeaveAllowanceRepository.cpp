#include "infrastructure/persistence/DrogonLeaveAllowanceRepository.hpp"
#include "infrastructure/persistence/models/LeaveAllowance.hpp"
#include "infrastructure/persistence/mappers/LeaveAllowanceMapper.hpp"
#include <drogon/orm/Criteria.h>
#include <drogon/orm/Mapper.h>

using LeaveAllowanceModel = drogon_model::LeaveBooking::LeaveAllowance;

void DrogonLeaveAllowanceRepository::save(const LeaveAllowance& leaveAllowance)
{
    LeaveAllowanceModel model = LeaveAllowanceMapper::toModel(leaveAllowance);

    drogon::orm::Mapper<LeaveAllowanceModel> mapper(db_);

    mapper.insert(model);
}

std::optional<LeaveAllowance> DrogonLeaveAllowanceRepository::findById(const Identity<LeaveAllowanceId>& id)
{
    drogon::orm::Mapper<LeaveAllowanceModel> mapper(db_);

    try {
	auto model = mapper.findByPrimaryKey(id.value());

	return LeaveAllowanceMapper::toDomain(model);
    } catch (const drogon::orm::DrogonDbException&) {
	return std::nullopt;
    }
}

std::optional<LeaveAllowance> DrogonLeaveAllowanceRepository::findByStaff(const Identity<StaffId>& id)
{
    drogon::orm::Mapper<LeaveAllowanceModel> mapper(db_);

    try {
	auto model = mapper.findOne(
	    drogon::orm::Criteria(
		LeaveAllowanceModel::Cols::_staff_id,
		drogon::orm::CompareOperator::EQ,
		id.value()
	    )
	);

	return LeaveAllowanceMapper::toDomain(model);
    } catch (const drogon::orm::DrogonDbException&) {
	return std::nullopt;
    }
}

