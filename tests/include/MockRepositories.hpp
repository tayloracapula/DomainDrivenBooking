#include "modules/leave/application/repositories/ILeaveAllowanceRepository.hpp"
#include "modules/leave/application/repositories/ILeaveRepository.hpp"
#include "modules/staff/application/repositories/IStaffRepository.hpp"

class MockLeaveRepository : public ILeaveRepository {

};

class MockLeaveAllowanceRepository : public ILeaveAllowanceRepository {

};

class MockStaffRepository : public IStaffRepository {

};
