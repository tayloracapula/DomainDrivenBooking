#include "modules/leave/domain/LeaveRequestId.hpp"
#include "shared/domain/IUseCase.hpp"
#include "shared/domain/Identity.hpp"
#include "modules/leave/application/dto/CancelLeaveRequestDTO.hpp"
#include "modules/leave/application/repositories/ILeaveAllowanceRepository.hpp"
#include "modules/leave/application/repositories/ILeaveRepository.hpp"


class CancelLeaveRequest : public IUseCase<CancelLeaveRequestDTO, Identity<LeaveRequestId>>
{
public:
    CancelLeaveRequest(
	ILeaveRepository& leaveRepository,
	ILeaveAllowanceRepository& leaveAllowanceRepository)
    :   leaveRepository_(leaveRepository),
	leaveAllowanceRepository_(leaveAllowanceRepository)
    {}
    Identity<LeaveRequestId> execute(const CancelLeaveRequestDTO& dto) override;
private:
    ILeaveRepository& leaveRepository_;
    ILeaveAllowanceRepository& leaveAllowanceRepository_;
};
