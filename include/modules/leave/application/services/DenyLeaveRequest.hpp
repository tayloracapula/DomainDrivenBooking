#include "modules/leave/domain/LeaveRequestId.hpp"
#include "shared/domain/IUseCase.hpp"
#include "shared/domain/Identity.hpp"
#include "modules/leave/application/dto/ApproveDenyLeaveRequestDTO.hpp"
#include "modules/leave/application/repositories/ILeaveAllowanceRepository.hpp"
#include "modules/leave/application/repositories/ILeaveRepository.hpp"

class DenyLeaveRequest : public IUseCase<ApproveDenyLeaveRequestDTO, Identity<LeaveRequestId>>
{
public:
    DenyLeaveRequest(
	ILeaveRepository& leaveRepository,
	ILeaveAllowanceRepository& leaveAllowanceRepository)
    :   leaveRepository_(leaveRepository),
	leaveAllowanceRepository_(leaveAllowanceRepository)
    {}
    Identity<LeaveRequestId> execute(const ApproveDenyLeaveRequestDTO& dto) override;
private:
    ILeaveRepository& leaveRepository_;
    ILeaveAllowanceRepository& leaveAllowanceRepository_;
};
