//
// Created by k on 10.08.24.
//

// HttpHandler.cpp
#include "HttpHandler.h"

namespace networking {

    HttpHandler::HttpHandler() {
        // Constructor implementation
    }

    std::string HttpHandler::handleRequest(const std::string& request) {
        // Handle the HTTP request and return a response
        // make a request to api.segmentationviolation.com?

        return "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nHello, World!";
    }

    // Implement other methods here

} // namespace networking
