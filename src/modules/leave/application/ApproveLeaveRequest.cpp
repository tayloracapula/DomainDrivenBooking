#include "modules/leave/domain/LeaveRequestId.hpp"
#include "shared/domain/Identity.hpp"
#include "modules/leave/application/services/ApproveLeaveRequest.hpp"
Identity<LeaveRequestId> ApproveLeaveRequest::execute(const ApproveDenyLeaveRequestDTO& dto){
}
