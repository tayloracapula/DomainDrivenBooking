#include "modules/leave/application/repositories/ILeaveRepository.hpp"
#include <drogon/orm/DbClient.h>

class DrogonLeaveRepository : public ILeaveRepository {
public:
    explicit DrogonLeaveRepository(
	drogon::orm::DbClientPtr db)
	: db_(std::move(db))
    {}
    void save(const LeaveRequest& leaveRequest) override;

private:
    drogon::orm::DbClientPtr db_;
};
