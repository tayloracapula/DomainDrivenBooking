#include "modules/leave/application/repositories/ILeaveRepository.hpp"
#include <drogon/orm/DbClient.h>

class DrogonLeaveRepository : public ILeaveRepository {
public:
    explicit DrogonLeaveRepository(
	drogon::orm::DbClientPtr db)
	: db_(std::move(db))
    {}

    void create(const LeaveRequest& leaveRequest) override;

    void update(const LeaveRequest& leaveRequest) override;

    std::optional<LeaveRequest> findById(const Identity<LeaveRequestId>& id) override;

    std::vector<LeaveRequest> findByStaff(const Identity<StaffId>& id) override;
private:
    drogon::orm::DbClientPtr db_;
};
