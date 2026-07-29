#include "modules/leave/domain/LeaveRequestId.hpp"
#include "shared/domain/IUseCase.hpp"
#include "shared/domain/Identity.hpp"
#include "modules/leave/application/dto/ApproveDenyLeaveRequestDTO.hpp"

class DenyLeaveRequest : public IUseCase<ApproveDenyLeaveRequestDTO, Identity<LeaveRequestId>>
{};
