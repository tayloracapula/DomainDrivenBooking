#include "modules/leave/domain/LeaveRequest.hpp"
#include "shared/domain/Identity.hpp"
#include <optional>

class ILeaveRepository{
public:
    virtual void save(const LeaveRequest&) = 0;

    virtual std::optional<LeaveRequest> findById(const Identity<LeaveRequestId>&) = 0;

    virtual ~ILeaveRepository() = default;
};
