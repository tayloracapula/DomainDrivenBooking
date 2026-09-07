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

class Leave: public drogon::HttpController<Leave>
{
  public:
    METHOD_LIST_BEGIN
    // use METHOD_ADD to add your custom processing function here;
    //METHOD_ADD(LeaveController::update,"",Put,Options);
    METHOD_ADD(Leave::createLeaveRequest, "", Post);
    METHOD_ADD(Leave::getLeaveRequest, "/request/{1}", Get);
    METHOD_ADD(Leave::getLeaveForStaff, "/request_list/{1}", Get);
    METHOD_ADD(Leave::getLeaveAllowance, "/allowance/{1}", Get);
    METHOD_ADD(Leave::cancelLeaveRequest, "/cancel/{1}", Patch);
    METHOD_ADD(Leave::approveLeaveRequest, "/approve/{1}", Patch);
    METHOD_ADD(Leave::denyLeaveRequest, "/deny/{1}", Patch);
    METHOD_LIST_END

//    void update(const HttpRequestPtr &req,
//                std::function<void(const HttpResponsePtr &)> &&callback);
    void createLeaveRequest(
	    const HttpRequestPtr& req,
	    std::function<void (const HttpResponsePtr&)>&& callback
    );

    void getLeaveRequest(
	    const HttpRequestPtr& req,
	    std::function<void (const HttpResponsePtr&)>&& callback,
	    std::string leaveId
    );

    void getLeaveForStaff(
	    const HttpRequestPtr& req,
	    std::function<void (const HttpResponsePtr&)>&& callback,
	    std::string staffId 
    );

    void getLeaveAllowance(
	    const HttpRequestPtr& req,
	    std::function<void (const HttpResponsePtr&)>&& callback,
	    std::string leaveAllowanceId 
    );

    void cancelLeaveRequest(
	    const HttpRequestPtr& req,
	    std::function<void (const HttpResponsePtr&)>&& callback,
	    std::string leaveId
    );

    void approveLeaveRequest(
	    const HttpRequestPtr& req,
	    std::function<void (const HttpResponsePtr&)>&& callback,
	    std::string leaveId
    );

    void denyLeaveRequest(
	    const HttpRequestPtr& req,
	    std::function<void (const HttpResponsePtr&)>&& callback,
	    std::string leaveId
    );

};
}
