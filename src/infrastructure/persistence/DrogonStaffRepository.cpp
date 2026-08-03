#include "infrastructure/persistence/DrogonStaffRepository.hpp"
#include "infrastructure/persistence/models/LeaveAllowance.hpp"
#include "infrastructure/persistence/mappers/StaffMapper.hpp"
#include <drogon/orm/Criteria.h>
#include <drogon/orm/Mapper.h>

using StaffModel = drogon_model::LeaveBooking::StaffMember;

void DrogonStaffRepository::create(const StaffMember& staffMember)
{
    StaffModel model = StaffMapper::toModel(staffMember);

    drogon::orm::Mapper<StaffModel> mapper(db_);

    mapper.insert(model);
}

void DrogonStaffRepository::update(const StaffMember& staffMember)
{
    StaffModel model = StaffMapper::toModel(staffMember);

    drogon::orm::Mapper<StaffModel> mapper(db_);

    mapper.update(model);
}

std::optional<StaffMember> DrogonStaffRepository::findById(const Identity<StaffId>& id)
{
    drogon::orm::Mapper<StaffModel> mapper(db_);

    try {
	auto model = mapper.findByPrimaryKey(id.value());

	return StaffMapper::toDomain(model);
    } catch (const drogon::orm::DrogonDbException) {
	return std::nullopt;
    }
}

std::vector<StaffMember> DrogonStaffRepository::findByManager(const Identity<StaffId>& managerId)
{
    drogon::orm::Mapper<StaffModel> mapper(db_);

    auto models = 
	mapper.findBy(
	    drogon::orm::Criteria(
		StaffModel::Cols::_manager_id,
		drogon::orm::CompareOperator::EQ,
		managerId.value()
	    )
	);
    std::vector<StaffMember> staff;

    for (const auto& model : models){
	staff.push_back(StaffMapper::toDomain(model));
    }

    return staff;
}

std::optional<StaffMember> DrogonStaffRepository::findManagerOf(const Identity<StaffId>& staffId)
{
    auto staff = findById(staffId);

    if (!staff){
	return std::nullopt;
    }

    if (!staff->managerId()){
	return std::nullopt;
    }

    return findById(*staff->managerId());
}


