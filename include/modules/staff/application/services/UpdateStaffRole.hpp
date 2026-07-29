#include "modules/staff/domain/StaffId.hpp"
#include "shared/domain/IUseCase.hpp"
#include "modules/staff/application/dto/UpdateStaffRoleDTO.hpp"
#include "shared/domain/Identity.hpp"


class UpdateStaffRole : public IUseCase<UpdateStaffRoleDTO, Identity<StaffId>>
{};
