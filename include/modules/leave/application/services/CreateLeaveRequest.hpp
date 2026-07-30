#include "modules/leave/domain/LeaveRequestId.hpp"
#include "shared/domain/IUseCase.hpp"
#include "shared/domain/Identity.hpp"
#include "modules/leave/application/dto/CreateLeaveRequestDTO.hpp"
#include "modules/leave/application/repositories/ILeaveAllowanceRepository.hpp"
#include "modules/leave/application/repositories/ILeaveRepository.hpp"

class CreateLeaveRequest: public IUseCase<CreateLeaveRequestDTO, Identity<LeaveRequestId>>
{
public:
    CreateLeaveRequest(
	ILeaveRepository& leaveRepository,
	ILeaveAllowanceRepository& leaveAllowanceRepository)
    :   leaveRepository_(leaveRepository),
	leaveAllowanceRepository_(leaveAllowanceRepository)
    {}
    Identity<LeaveRequestId> execute(const CreateLeaveRequestDTO& dto) override;
private:
    ILeaveRepository& leaveRepository_;
    ILeaveAllowanceRepository& leaveAllowanceRepository_;
};
