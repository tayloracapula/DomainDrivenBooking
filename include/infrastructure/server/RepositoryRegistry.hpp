#pragma once

#include "modules/staff/application/repositories/IStaffRepository.hpp"
#include "modules/leave/application/repositories/ILeaveRepository.hpp"
#include "modules/leave/application/repositories/ILeaveAllowanceRepository.hpp"
#include <memory>
#include <stdexcept>
#include <utility>

class RepositoryRegistry {
public:
    static RepositoryRegistry& instance() {
	static RepositoryRegistry registry;

	return registry;
    };

    void setLeaveRepository(std::shared_ptr<ILeaveRepository> repository) {
	leaveRepository_ = std::move(repository);
    };

    void setLeaveAllowanceRepository(std::shared_ptr<ILeaveAllowanceRepository> repository) {
	leaveAllowanceRepository_ = std::move(repository);
    };

    void setStaffRepository(std::shared_ptr<IStaffRepository> repository) {
	staffRepository_ = std::move(repository);
    };

    ILeaveRepository& leaveRepository() {
	if (!leaveRepository_) {
	    throw std::runtime_error("Leave Repository not registered");
	}

	return *leaveRepository_;
    };
    ILeaveAllowanceRepository& leaveAllowanceRepository() {
	if (!leaveAllowanceRepository_) {
	    throw std::runtime_error("Leave Allowance Repository not registered");
	}

	return *leaveAllowanceRepository_;
    };
    IStaffRepository& staffRepository() {
	if (!staffRepository_) {
	    throw std::runtime_error("Staff Repository not registered");
	}

	return *staffRepository_;
    };
private:
    std::shared_ptr<ILeaveRepository> leaveRepository_;
    std::shared_ptr<ILeaveAllowanceRepository> leaveAllowanceRepository_;
    std::shared_ptr<IStaffRepository> staffRepository_;
};
