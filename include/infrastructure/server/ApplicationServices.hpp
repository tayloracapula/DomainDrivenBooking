#pragma once

#include "modules/staff/application/services/CreateStaffMember.hpp"
#include "modules/staff/application/services/UpdateStaffName.hpp"
#include "modules/staff/application/services/UpdateStaffRole.hpp"
#include "modules/staff/application/services/AssignManager.hpp"
#include "modules/staff/application/services/TerminateStaffMember.hpp"
#include "modules/leave/application/services/CreateLeaveRequest.hpp"
#include "modules/leave/application/services/CancelLeaveRequest.hpp"
#include "modules/leave/application/services/ApproveLeaveRequest.hpp"
#include "modules/leave/application/services/DenyLeaveRequest.hpp"

#include <memory>


class ApplicationServices {
public:
    static ApplicationServices& instance() {
	static ApplicationServices services;

	return services;
    };

    void initialise();

    CreateStaffMember& createStaffMember() {
	if (!createStaffMember_) {
	    throw std::runtime_error("Create Staff not registered");
	}

	return *createStaffMember_;
    };

    UpdateStaffName& updateStaffName() {
	if (!updateStaffName_) {
	    throw std::runtime_error("Update Staff Name not registered");
	}

	return *updateStaffName_;
    };

    UpdateStaffRole& updateStaffRole() {
	if (!updateStaffRole_) {
	    throw std::runtime_error("Update Staff Role not registered");
	}

	return *updateStaffRole_;
    };
    TerminateStaffMember& terminateStaffMember() {
	if (!terminateStaffMember_) {
	    throw std::runtime_error("Terminate Staff not registered");
	}

	return *terminateStaffMember_;
    };
    
    CreateLeaveRequest& createLeaveRequest() {
	if (!createLeaveRequest_) {
	    throw std::runtime_error("Create Leave not registered");
	}

	return *createLeaveRequest_;
    };
    CancelLeaveRequest& cancelLeaveRequest() {
	if (!cancelLeaveRequest_) {
	    throw std::runtime_error("Cancel Leave not registered");
	}

	return *cancelLeaveRequest_;
    };
    ApproveLeaveRequest& approveLeaveRequest() {
	if (!approveLeaveRequest_) {
	    throw std::runtime_error("Approve Leave not registered");
	}

	return *approveLeaveRequest_;
    };
    DenyLeaveRequest& denyLeaveRequest() {
	if (!denyLeaveRequest_) {
	    throw std::runtime_error("Deny Leave not registered");
	}

	return *denyLeaveRequest_;
    };

private:
    std::unique_ptr<CreateStaffMember> createStaffMember_;
    std::unique_ptr<UpdateStaffName> updateStaffName_;
    std::unique_ptr<UpdateStaffRole> updateStaffRole_;
    std::unique_ptr<TerminateStaffMember> terminateStaffMember_;

    std::unique_ptr<CreateLeaveRequest> createLeaveRequest_;
    std::unique_ptr<CancelLeaveRequest> cancelLeaveRequest_;
    std::unique_ptr<ApproveLeaveRequest> approveLeaveRequest_;
    std::unique_ptr<DenyLeaveRequest> denyLeaveRequest_;

};
