#pragma once 

#include "modules/leave/domain/LeaveAllowance.hpp"
#include "modules/leave/domain/LeaveAllowanceId.hpp"
#include "shared/domain/IRepository.hpp"
#include <optional>

class ILeaveAllowanceRepository: public IRepository<LeaveAllowance, LeaveAllowanceId>{
public:

    virtual std::optional<LeaveAllowance> findByStaff(const Identity<StaffId>& id) = 0;

    virtual ~ILeaveAllowanceRepository() = default;
};
