#include <iostream>
#include <random>
#include <utility>

#include "HttpHandler.h"

int http(std::string bearer, std::string* targetUrl, ...) {
    using namespace std;    // nice

    // Initialize RequestData
    networking::RequestData requestData = {
        "GET",                             // method
        *targetUrl,                           //
        "C++/0.1",                 // userAgent
        std::move(bearer),                 // authorization (move seems to move the allocated
        {{"Content-Type", "application/json"}} // headers
    };

    // Create an HttpHandler object
    networking::HttpHandler handler;

    std::cout << "\033[32mmessing with vectors\033[0m " << std::endl;
    std::vector<int>* vec;
    std::cout << &vec << std::endl;

    // Handle the request using HttpHandler
    std::string response = handler.handleRequest(requestData);

    // Output the response
    std::cout << response << std::endl;

    return 0;
}

int main(int argc, char* argv[]) {
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }

    int counter = 0;
    std::map<std::string, std::string> headers = {{}};
    std::string url = "127.0.0.1";
    std::string method = "GET";
    std::string bearer = "unset";

    // loop through every argument passed to main
    for (const char* arg: argv) {
        switch(arg) {
            // case "--header":    // check for specific args
                // headers = arg[counter+1];
            case "--url":
                url = arg[counter+1];
            case "--method":
                method = arg[counter+1];
            case "--bearer":
                bearer = arg[counter+1];
            default: std::cout << "unknown argument" << arg << std::endl;
        }
        counter++;
    }

    std::cout
    << "bearer: " << bearer << '\n' << "method: " <<
    std::endl;

    http(bearer, &url, method);

    // std::cout << "Hello, World!" << std::endl;

    return 0;
}
