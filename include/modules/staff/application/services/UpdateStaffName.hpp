#include "modules/staff/domain/StaffId.hpp"
#include "shared/domain/IUseCase.hpp"
#include "modules/staff/application/dto/UpdateStaffNameDTO.hpp"
#include "shared/domain/Identity.hpp"


class UpdateStaffName : public IUseCase<UpdateStaffNameDTO, Identity<StaffId>>
{};
