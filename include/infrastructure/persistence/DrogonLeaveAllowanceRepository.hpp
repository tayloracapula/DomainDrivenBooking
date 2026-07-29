#include "modules/leave/application/repositories/ILeaveAllowanceRepository.hpp"
#include "modules/leave/domain/LeaveAllowance.hpp"
#include <drogon/orm/DbClient.h>
#include <optional>

class DrogonLeaveAllowanceRepository : public ILeaveAllowanceRepository {
public:
    explicit DrogonLeaveAllowanceRepository(
	drogon::orm::DbClientPtr db)
	: db_(std::move(db))
    {}

    void save(const LeaveAllowance& leaveAllowance) override;

    std::optional<LeaveAllowance> findById(const Identity<LeaveAllowanceId>& id) ;

    std::optional<LeaveAllowance> findByStaff(const Identity<StaffId>& id) override;

private:
    drogon::orm::DbClientPtr db_;
};
