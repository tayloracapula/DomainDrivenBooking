#pragma once

#include <drogon/HttpController.h>
#include <functional>
#include <string>
using namespace drogon;
/**
 * @brief this class is created by the drogon_ctl command (drogon_ctl create controller -r Leave).
 * this class is a restful API controller.
 */
namespace api {

class Staff: public drogon::HttpController<Staff>
{
  public:
    METHOD_LIST_BEGIN
    // use METHOD_ADD to add your custom processing function here;
    //METHOD_ADD(LeaveController::update,"",Put,Options);
    METHOD_ADD(Staff::createStaffMember,"" , Post);
    METHOD_ADD(Staff::getStaffMember, "/staff_member/{1}", Get);
    METHOD_LIST_END

//    void update(const HttpRequestPtr &req,
//                std::function<void(const HttpResponsePtr &)> &&callback);

    void createStaffMember(
	const HttpRequestPtr& req,
	std::function<void (const HttpResponsePtr&)>&& callback
    );

    void getStaffMember(
	const HttpRequestPtr& req,
	std::function<void (const HttpResponsePtr&)>&& callback,
	std::string staffId
    );

    void updateName(
	const HttpRequestPtr& req,
	std::function<void (const HttpResponsePtr&)>&& callback,
	std::string staffId
    );

    void updateRole(
	const HttpRequestPtr& req,
	std::function<void (const HttpResponsePtr&)>&& callback,
	std::string staffId
    );

    void terminateEmployee(
	const HttpRequestPtr& req,
	std::function<void (const HttpResponsePtr&)>&& callback,
	std::string staffId
    );

    void findManagedStaff(
	const HttpRequestPtr& req,
	std::function<void (const HttpResponsePtr&)>&& callback,
	std::string managerId 
    );

};
}
