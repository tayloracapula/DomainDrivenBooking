#include "infrastructure/server/ApplicationServices.hpp"
#include "infrastructure/server/RepositoryRegistry.hpp"
#include <memory>
void ApplicationServices::initialise() 
{
    auto& repos = RepositoryRegistry::instance();

    createStaffMember_ = std::make_unique<CreateStaffMember>(
	repos.staffRepository()
    );

    updateStaffName_ = std::make_unique<UpdateStaffName>(
	repos.staffRepository()
    );

    updateStaffRole_ = std::make_unique<UpdateStaffRole>(
	repos.staffRepository()
    );

    terminateStaffMember_ = std::make_unique<TerminateStaffMember>(
	repos.staffRepository()
    );
    
    getStaffMember_ = std::make_unique<GetStaffMember>(
	repos.staffRepository()
    );

    getStaffForManager_ = std::make_unique<GetStaffForManager>(
	repos.staffRepository()
    );

    getManagerForStaff_ = std::make_unique<GetManagerForStaff>(
	repos.staffRepository()
    );


    createLeaveRequest_ = std::make_unique<CreateLeaveRequest>(
	repos.leaveRepository(),
	repos.leaveAllowanceRepository()
    );

    cancelLeaveRequest_ = std::make_unique<CancelLeaveRequest>(
	repos.leaveRepository(),
	repos.leaveAllowanceRepository(),
	repos.staffRepository()
    );

    approveLeaveRequest_ = std::make_unique<ApproveLeaveRequest>(
	repos.leaveRepository(),
	repos.leaveAllowanceRepository(),
	repos.staffRepository()
    );

    denyLeaveRequest_ = std::make_unique<DenyLeaveRequest>(
	repos.leaveRepository(),
	repos.leaveAllowanceRepository(),
	repos.staffRepository()
    );

    getLeaveRequest_ = std::make_unique<GetLeaveRequest>(
	repos.leaveRepository()
    );

    getLeaveForStaff_ = std::make_unique<GetLeaveForStaff>(
	repos.leaveRepository()
    );

    getLeaveAllowance_ = std::make_unique<GetLeaveAllowance>(
	repos.leaveAllowanceRepository()
    );

}
