#include "modules/leave/application/repositories/ILeaveRepository.hpp"
#include "modules/leave/domain/LeaveRequest.hpp"
#include "modules/leave/domain/LeaveRequestId.hpp"
#include "shared/domain/IUseCase.hpp"
#include "shared/domain/Identity.hpp"
#include "shared/server/GetDTO.hpp"

class GetLeaveRequest : public IUseCase<GetDTO<Identity<LeaveRequestId>>, LeaveRequest>
{
public:
    GetLeaveRequest(
	ILeaveRepository& leaveRepository)
    :	leaveRepository_(leaveRepository)
    {}
    LeaveRequest execute(const GetDTO<Identity<LeaveRequestId>>& dto) override;
private:
    ILeaveRepository& leaveRepository_;
};
