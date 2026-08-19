#include "modules/leave/application/repositories/ILeaveAllowanceRepository.hpp"
#include "modules/leave/application/repositories/ILeaveRepository.hpp"
#include "modules/staff/application/repositories/IStaffRepository.hpp"
#include <stdexcept>
#include <unordered_map>

class MockLeaveRepository : public ILeaveRepository {
public:
    void create(const LeaveRequest& request) override {
	auto key = request.id().value();

	if (requests_.contains(key)) {
	    throw std::runtime_error("Leave Request already exists");
	}

	requests_.emplace(key, request);
    }

    void update(const LeaveRequest& request) override {
	auto key = request.id().value();

	if (!requests_.contains(key)) {
	    throw std::runtime_error("Leave Request does not exists");
	}

	requests_.insert_or_assign(key, request);
    }

    std::optional<LeaveRequest> findById(const Identity<LeaveRequestId>& id) override {
	auto request = requests_.find(id.value());

	if (request == requests_.end()) {
	    return std::nullopt;
	}

	return request->second;
    }

    std::vector<LeaveRequest> findByStaff(const Identity<StaffId>& staffId) override {
	std::vector<LeaveRequest> result;

	for (const auto& [id, request] : requests_) {
	    if (request.staffId() == staffId) {
		result.push_back(request);
	    }
	}

	return result;
    }

private:
    std::unordered_map<std::string, LeaveRequest> requests_;
};

class MockLeaveAllowanceRepository : public ILeaveAllowanceRepository {
public:

    void create(const LeaveAllowance& allowance) override {
	auto key = allowance.id().value();

	if (allowances_.contains(key)) {
	    throw std::runtime_error("Leave Allowance already exists");
	}

	allowances_.emplace(key,allowance);
    }

    void update(const LeaveAllowance& allowance) override {
	auto key = allowance.id().value();

	if (!allowances_.contains(key)) {
	    throw std::runtime_error("Leave Allowance does not exists");
	}

	allowances_.insert_or_assign(key,allowance);
    }

    std::optional<LeaveAllowance> findById(const Identity<LeaveAllowanceId>& id) override {
	auto allowance = allowances_.find(id.value());

	if (allowance == allowances_.end()) {
	    return std::nullopt;
	}

	return allowance->second;
    }
    
    std::optional<LeaveAllowance> findByStaff(const Identity<StaffId>& id) override {
	for (const auto& [allowanceId, allowance] : allowances_) {
	    if (allowance.staffId() == id) {
		return allowance;
	    }
	}

	return std::nullopt;
    }

private:
    std::unordered_map<std::string, LeaveAllowance> allowances_;
};

class MockStaffRepository : public IStaffRepository {
public:

    void create(const StaffMember& staff) override {
	auto key = staff.id().value();

	if (staff_.contains(key)) {
	    throw std::runtime_error("Staff already exists");
	}

	staff_.emplace(key, staff);
    }

    void update(const StaffMember& staff) override {
	auto key = staff.id().value();

	if (!staff_.contains(key)) {
	    throw std::runtime_error("Staff does not exists");
	}

	staff_.insert_or_assign(key, staff);
    }



    std::optional<StaffMember> findById(const Identity<StaffId>& id) override {
	auto staff = staff_.find(id.value());

	if (staff == staff_.end()) {
	    return std::nullopt;
	}

	return staff->second;
    }

    std::vector<StaffMember> findByManager(const Identity<StaffId>& managerId) override {
	std::vector<StaffMember> result;
	for (const auto& [staffId, staff] : staff_) {
	    if (staff.managerId() == managerId) {
		result.push_back(staff);
	    }
	}

	return result;
    }

    std::optional<StaffMember> findManagerOf(const Identity<StaffId>& staffId) override {
	auto staff = staff_.find(staffId.value());

	if (staff == staff_.end()) {
	    return std::nullopt;
	}

	if (!staff->second.managerId().has_value()) {
	    return std::nullopt;
	}

	auto manager = staff_.find(staff->second.managerId().value().value());

	if (manager == staff_.end()) {
	    return std::nullopt;
	}

	return manager->second;
    }
private:
    std::unordered_map<std::string, StaffMember> staff_;
};
