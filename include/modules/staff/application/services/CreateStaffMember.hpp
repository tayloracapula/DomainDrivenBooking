#include "modules/staff/domain/StaffId.hpp"
#include "shared/domain/IUseCase.hpp"
#include "modules/staff/application/dto/CreateStaffMemberDTO.hpp"
#include "shared/domain/Identity.hpp"

class CreateStaffMember : public IUseCase<CreateStaffMemberDTO, Identity<StaffId>>
{};
