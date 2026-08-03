#include "modules/leave/domain/LeaveRequestId.hpp"
#include "shared/domain/IUseCase.hpp"
#include "shared/domain/Identity.hpp"
#include "modules/leave/application/dto/ApproveDenyLeaveRequestDTO.hpp"
#include "modules/leave/application/repositories/ILeaveAllowanceRepository.hpp"
#include "modules/leave/application/repositories/ILeaveRepository.hpp"
#include "modules/staff/application/repositories/IStaffRepository.hpp"

class ApproveLeaveRequest : public IUseCase<ApproveDenyLeaveRequestDTO, Identity<LeaveRequestId>>
{
public:
    ApproveLeaveRequest(
	ILeaveRepository& leaveRepository,
	ILeaveAllowanceRepository& leaveAllowanceRepository,
	IStaffRepository& staffRepository)
    :   leaveRepository_(leaveRepository),
	leaveAllowanceRepository_(leaveAllowanceRepository),
	staffRepository_(staffRepository)
    {}
    Identity<LeaveRequestId> execute(const ApproveDenyLeaveRequestDTO& dto) override;
private:
    ILeaveRepository& leaveRepository_;
    ILeaveAllowanceRepository& leaveAllowanceRepository_;
    IStaffRepository& staffRepository_;
};
