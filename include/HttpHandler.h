//
// Created by k on 10.08.24.
//

#ifndef HTTPHANDLER_H
#define HTTPHANDLER_H

#include <string>

namespace networking {

    class HttpHandler {
    public:
        HttpHandler();
        std::string handleRequest(const std::string& request);

    private:
        // Private members and helper methods
    };

} // namespace networking

#endif // HTTPHANDLER_H

