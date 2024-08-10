
#ifndef HTTPHANDLER_H
#define HTTPHANDLER_H

#include <string>
#include "HttpRequest.h"

namespace networking {

    class HttpHandler {
    public:
        HttpHandler();

        std::string handleRequest(const RequestData& requestData);  // No need to fully qualify now

        // Get the internal HttpRequest object
        const HttpRequest& getHttpRequest() const;
    private:
        HttpRequest request_;
    };

} // namespace networking

#endif // HTTPHANDLER_H

