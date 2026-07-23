#include "modules/staff/domain/StaffMember.hpp"
#include "shared/domain/Identity.hpp"
#include <optional>
#include <vector>

class IStaffRepository{
public:
    virtual void save(const StaffMember&) = 0;

    virtual std::optional<StaffMember> findById(const Identity<StaffId>& id) = 0;

    virtual std::vector<StaffMember> findByManager(const Identity<StaffId>& managerId) = 0;

    virtual std::optional<StaffMember> findManagerOf(const Identity<StaffId>& staffId) = 0;
    
    virtual ~IStaffRepository() = default;
};
