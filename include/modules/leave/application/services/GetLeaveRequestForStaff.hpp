#include "modules/leave/application/repositories/ILeaveRepository.hpp"
#include "modules/leave/domain/LeaveRequest.hpp"
#include "modules/staff/domain/StaffId.hpp"
#include "shared/domain/IUseCase.hpp"
#include "shared/domain/Identity.hpp"
#include "shared/server/GetDTO.hpp"
#include <vector>

class GetLeaveForStaff : public IUseCase<GetDTO<Identity<StaffId>>, std::vector<LeaveRequest>>
{
public:
    GetLeaveForStaff(
	ILeaveRepository& leaveRepository)
    :	leaveRepository_(leaveRepository)
    {}
    std::vector<LeaveRequest> execute (const GetDTO<Identity<StaffId>>& dto) override;
private:
    ILeaveRepository& leaveRepository_;
};
