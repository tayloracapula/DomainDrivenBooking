#include "modules/leave/domain/LeaveRequestId.hpp"
#include "shared/domain/IUseCase.hpp"
#include "shared/domain/Identity.hpp"
#include "modules/leave/application/dto/CreateLeaveRequestDTO.hpp"

class CreateLeaveRequest: public IUseCase<CreateLeaveRequestDTO, Identity<LeaveRequestId>>
{};
