//
// Created by k on 10.08.24.
//

#include "HttpRequest.h"

namespace networking {

    HttpRequest::HttpRequest(const RequestData& requestData) : requestData_(requestData) {
        // Constructor implementation
    }

    void HttpRequest::setRequestData(const RequestData& requestData) {
        requestData_ = requestData;
    }

    const RequestData& HttpRequest::getRequestData() const {
        return requestData_;
    }

    // Set the request data authorization header to the bearer token
    void HttpRequest::setBearerToken(const std::string &token) {
        requestData_.authorization = "Bearer " + token;
    }


} // namespace networking
