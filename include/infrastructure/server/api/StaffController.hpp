#pragma once

#include <drogon/HttpController.h>
#include <drogon/HttpTypes.h>
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
    METHOD_ADD(Staff::getStaffForManager, "/managed/{1}", Get);
    METHOD_ADD(Staff::getManagerForStaff, "/manager/{1}", Get);
    METHOD_ADD(Staff::updateName, "/update_name/{1}", Patch);
    METHOD_ADD(Staff::updateRole, "/update_role/{1}", Patch);
    METHOD_ADD(Staff::terminateEmployee, "/terminate/", Patch);
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

    void getStaffForManager(
	const HttpRequestPtr& req,
	std::function<void (const HttpResponsePtr&)>&& callback,
	std::string staffId
    );

    void getManagerForStaff(
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
};
}
