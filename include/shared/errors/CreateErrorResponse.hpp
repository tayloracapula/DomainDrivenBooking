#include "json/value.h"
#include <drogon/HttpResponse.h>
#include <drogon/HttpTypes.h>
inline drogon::HttpResponsePtr createErrorMessage(
    const std::string& message,
    drogon::HttpStatusCode status
){
    Json::Value response;

    response["error"] = message;

    auto httpResponse = drogon::HttpResponse::newHttpJsonResponse(response);

    httpResponse->setStatusCode(status);

    return httpResponse;
}
