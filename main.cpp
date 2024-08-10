#include <iostream>
#include "HttpHandler.h"
#include <random>

int http() {
    using namespace std;    // nice

    networking::HttpHandler handler; // define the handler from the namespace::Class
    string res = handler.handleRequest("GET / HTTP/1.1");
    // cout << res << endl;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 10);
    // int randomValue = distrib(gen);

    if (distrib(gen) % 2 == 0) { // if the random num between 0-10 % 2 == 0
        return 1;
    }

    return 0;
}

int main(int argc, char* argv[]) {
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }

    std::cout << "Hello, World!" << std::endl;

    if (http() == 0) {
        std::cout << "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nHello, World!" << std::endl;
    }
    return 0;
}
