#include "modules/leave/domain/LeaveRequestId.hpp"
#include "shared/domain/IUseCase.hpp"
#include "shared/domain/Identity.hpp"
#include "modules/leave/application/dto/CancelLeaveRequestDTO.hpp"

class CancelLeaveRequest : public IUseCase<CancelLeaveRequestDTO, Identity<LeaveRequestId>>
{};
