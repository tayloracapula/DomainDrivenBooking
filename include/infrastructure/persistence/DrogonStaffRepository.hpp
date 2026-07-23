#include "modules/staff/application/repositories/IStaffRepository.hpp"
#include <drogon/orm/DbClient.h>
#include <optional>

class DrogonStaffRepository : public IStaffRepository {
public:
    explicit DrogonStaffRepository(
	drogon::orm::DbClientPtr db)
	: db_(std::move(db))
    {}
    void save(const StaffMember& staffMember) override;

    std::optional<StaffMember> findById(const Identity<StaffId>& id) override;

    std::vector<StaffMember> findByManager(const Identity<StaffId>& managerId) override;

    std::optional<StaffMember> findManagerOf(const Identity<StaffId>& staffId) override;

private:
    drogon::orm::DbClientPtr db_;

};
