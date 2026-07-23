#include "modules/leave/domain/LeaveAllowance.hpp"
#include "modules/leave/domain/LeaveAllowanceId.hpp"
#include <optional>

class ILeaveAllowanceRepository{
public:
    virtual void save(const LeaveAllowance&) = 0;

    virtual std::optional<LeaveAllowance> findById(const Identity<LeaveAllowanceId>& id) = 0;

    virtual std::optional<LeaveAllowance> findByStaff(const Identity<StaffId>& id) = 0;

    virtual ~ILeaveAllowanceRepository() = default;
};
