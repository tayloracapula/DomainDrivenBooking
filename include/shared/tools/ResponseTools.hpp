#include <drogon/HttpResponse.h>

inline drogon::HttpResponsePtr createIdResponse(const std::string& id) {

    Json::Value response;

    response["id"] = id;

    return drogon::HttpResponse::newHttpJsonResponse(response);

}
