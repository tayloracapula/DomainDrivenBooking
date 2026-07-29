#include "modules/leave/domain/LeaveRequest.hpp"
#include "modules/staff/domain/StaffId.hpp"
#include "shared/domain/Identity.hpp"
#include "shared/domain/IRepository.hpp"
#include <vector>

class ILeaveRepository : public IRepository<LeaveRequest, LeaveRequestId>{
public:
    virtual std::vector<LeaveRequest> findByStaff(const Identity<StaffId>& id) = 0;

    virtual ~ILeaveRepository() = default;
};
