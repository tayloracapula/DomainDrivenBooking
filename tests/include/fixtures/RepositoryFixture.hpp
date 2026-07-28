#include <drogon/HttpAppFramework.h>
#include <drogon/orm/DbClient.h>
#include "../TestEnvironment.hpp"
#include "infrastructure/persistence/DrogonStaffRepository.hpp"
#include "infrastructure/persistence/DrogonLeaveAllowanceRepository.hpp"
#include "infrastructure/persistence/DrogonLeaveRepository.hpp"


struct RepositoryFixture
{
    drogon::orm::DbClientPtr db;

    std::unique_ptr<DrogonStaffRepository> staffRepository;

    std::unique_ptr<DrogonLeaveAllowanceRepository> leaveAllowanceRepository;
    
    std::unique_ptr<DrogonLeaveRepository> leaveRepository;

    RepositoryFixture()
    {
	TestEnvironment::initialise();	
	std::string dbConfig = R""""(
	    host=localhost 
	    port=5432 
	    dbname=LeaveBooking_test 
	    user=pguser 
	    password=password 
	)"""";
    

	db = drogon::orm::DbClient::newPgClient(dbConfig, 1);

	clearDatabase();

	staffRepository = std::make_unique<DrogonStaffRepository>(db);

	leaveAllowanceRepository = std::make_unique<DrogonLeaveAllowanceRepository>(db);

	leaveRepository = std::make_unique<DrogonLeaveRepository>(db);
    }
private:
    void clearDatabase()
    {
	db->execSqlSync(
	    "DELETE FROM leave_request"
	);
	db->execSqlSync(
	    "DELETE FROM leave_allowance"
	);
	db->execSqlSync(
	    "DELETE FROM staff_member"
	);
    }
};
