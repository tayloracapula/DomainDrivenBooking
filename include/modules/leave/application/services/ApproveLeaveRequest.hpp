#include "modules/leave/domain/LeaveRequestId.hpp"
#include "shared/domain/IUseCase.hpp"
#include "shared/domain/Identity.hpp"
#include "modules/leave/application/dto/ApproveDenyLeaveRequestDTO.hpp"

class ApproveLeaveRequest : public IUseCase<ApproveDenyLeaveRequestDTO, Identity<LeaveRequestId>>
{
public:
    Identity<LeaveRequestId> execute(const ApproveDenyLeaveRequestDTO& dto) override;
};
