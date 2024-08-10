//
// Created by k on 10.08.24.
// HttpRequest.h

#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <string>
#include <map>

namespace networking {

    struct RequestData {
        std::string method;
        std::string url;
        std::string userAgent;
        std::string authorization;
        std::map<std::string, std::string> headers;
    };

    class HttpRequest {
    public:

        // Constructor
        HttpRequest(const RequestData& requestData);

        // Method to set all request data with the struct
        void setRequestData(const RequestData& requestData);

        // We'll need to be able to easily set the bearer token as it's bound to change often
        void setBearerToken(const std::string& token);

        // Public getter for request data
        const RequestData& getRequestData() const;

    private:
        // Private member to hold the request data
        RequestData requestData_;
    };
} // namespace networking

#endif //HTTPREQUEST_H
