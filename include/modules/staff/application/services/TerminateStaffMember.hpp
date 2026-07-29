#include "modules/staff/domain/StaffId.hpp"
#include "shared/domain/IUseCase.hpp"
#include "shared/domain/Identity.hpp"
#include "modules/staff/application/dto/TerminateStaffMemberDTO.hpp"

class TerminateStaffMember : public IUseCase<TerminateStaffMemberDTO, Identity<StaffId>>
{};
