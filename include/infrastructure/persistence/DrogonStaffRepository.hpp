#include "modules/staff/application/repositories/IStaffRepository.hpp"
#include <drogon/orm/DbClient.h>

class DrogonStaffRepository : public IStaffRepository {
public:
    explicit DrogonStaffRepository(
	drogon::orm::DbClientPtr db)
	: db_(std::move(db))
    {}
    void save(const StaffMember& staffMember) override;

private:
    drogon::orm::DbClientPtr db_;

};
