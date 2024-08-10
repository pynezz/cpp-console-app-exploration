//
// Created by k on 10.08.24.
//
// HttpHandler.cpp
#include "HttpHandler.h"

namespace networking {

    HttpHandler::HttpHandler() : request_({}) {
        // Initialize HttpRequest with default values if needed
    }

    std::string HttpHandler::handleRequest(const RequestData& requestData) {
        // Use the HttpRequest object internally
        request_.setRequestData(requestData);
        std::string response = "HTTP/1.1 200 OK\nContent-Type: text/plain\n\n";
        response += "Handled request for URL: " + request_.getRequestData().url + "\n";
        return response;
    }

    const HttpRequest& HttpHandler::getHttpRequest() const {
        return request_;
    }

} // namespace networking
