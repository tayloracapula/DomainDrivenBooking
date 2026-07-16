#pragma once

#include <drogon/HttpController.h>
#include <functional>
#include <string>
using namespace drogon;
/**
 * @brief this class is created by the drogon_ctl command (drogon_ctl create controller -r LeaveController).
 * this class is a restful API controller.
 */

class Leave: public drogon::HttpController<Leave>
{
  public:
    METHOD_LIST_BEGIN
    // use METHOD_ADD to add your custom processing function here;
    //METHOD_ADD(LeaveController::update,"",Put,Options);
    METHOD_ADD(Leave::getLeaveRequest, "/leave_request/{1}", Get);
    METHOD_LIST_END

//    void update(const HttpRequestPtr &req,
//                std::function<void(const HttpResponsePtr &)> &&callback);
    void getLeaveRequest(
	    const HttpRequestPtr& req,
	    std::function<void (const HttpResponsePtr&)>&& callback,
	    std::string leaveId
	    );
};
