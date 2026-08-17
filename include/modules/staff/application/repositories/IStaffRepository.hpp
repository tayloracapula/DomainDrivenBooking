#pragma once

#include "modules/staff/domain/StaffMember.hpp"
#include "shared/domain/Identity.hpp"
#include "shared/domain/IRepository.hpp"
#include <optional>
#include <vector>

class IStaffRepository : public IRepository<StaffMember, StaffId> {
public:
    virtual std::vector<StaffMember> findByManager(const Identity<StaffId>& managerId) = 0;

    virtual std::optional<StaffMember> findManagerOf(const Identity<StaffId>& staffId) = 0;
    
    virtual ~IStaffRepository() = default ;
};
