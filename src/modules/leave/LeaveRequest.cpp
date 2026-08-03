#include "modules/leave/domain/LeaveRequest.hpp"

void LeaveRequest::approve(){
    status_ = LeaveStatus::Approved;
}

void LeaveRequest::reject(){
    status_ = LeaveStatus::Rejected;
}

void LeaveRequest::cancel(){
    status_ = LeaveStatus::Cancelled;
}
