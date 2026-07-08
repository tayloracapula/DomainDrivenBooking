#include "modules/staff/domain/StaffId.hpp"
#include "modules/staff/domain/StaffMember.hpp"
#include "shared/domain/Identity.hpp"
#include <optional>

class IStaffRepository{
public:
    virtual void save(const StaffMember&) = 0;

    virtual std::optional<StaffMember> findById(const Identity<StaffId>&) = 0;
    
    virtual ~IStaffRepository() = default;
};
