#include "modules/leave/application/repositories/ILeaveAllowanceRepository.hpp"
#include "modules/leave/domain/LeaveAllowance.hpp"
#include "modules/leave/domain/LeaveAllowanceId.hpp"
#include "shared/domain/IUseCase.hpp"
#include "shared/domain/Identity.hpp"
#include "shared/server/GetDTO.hpp"

class GetLeaveAllowance : public IUseCase<GetDTO<Identity<StaffId>>, LeaveAllowance>
{
public:
    GetLeaveAllowance(
	ILeaveAllowanceRepository& leaveAllowanceRepository)
    :	leaveAllowanceRepository_(leaveAllowanceRepository)
    {}
    LeaveAllowance execute(const GetDTO<Identity<StaffId>>& dto) override;
private:
    ILeaveAllowanceRepository& leaveAllowanceRepository_;
};
