#include "modules/leave/domain/LeaveRequest.hpp"
#include "modules/staff/domain/StaffId.hpp"
#include "shared/domain/Identity.hpp"
#include <optional>
#include <vector>

class ILeaveRepository{
public:
    virtual void save(const LeaveRequest&) = 0;

    virtual std::optional<LeaveRequest> findById(const Identity<LeaveRequestId>& id) = 0;

    virtual std::vector<LeaveRequest> findByStaff(const Identity<StaffId>& id) = 0;

    virtual ~ILeaveRepository() = default;
};
