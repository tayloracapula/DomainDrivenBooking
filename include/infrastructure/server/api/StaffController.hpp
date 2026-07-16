#pragma once

#include <drogon/HttpController.h>
#include <functional>
#include <string>
using namespace drogon;
/**
 * @brief this class is created by the drogon_ctl command (drogon_ctl create controller -r LeaveController).
 * this class is a restful API controller.
 */
class Staff: public drogon::HttpController<Staff>
{
  public:
    METHOD_LIST_BEGIN
    // use METHOD_ADD to add your custom processing function here;
    //METHOD_ADD(LeaveController::update,"",Put,Options);
    ADD_METHOD_TO(Staff::getStaffMember, "/staff_request/{1}", Get);
    METHOD_LIST_END

//    void update(const HttpRequestPtr &req,
//                std::function<void(const HttpResponsePtr &)> &&callback);
    void getStaffMember(
	    const HttpRequestPtr& req,
	    std::function<void (const HttpResponsePtr&)>&& callback,
	    std::string staffId
	    );
};
