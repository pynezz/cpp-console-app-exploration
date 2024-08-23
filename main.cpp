/* *************************************** *\
*   Please note:                            *
*    Much of this code won't make "sense".  *
*    It's just a c++ exploration.           *
\* *************************************** */

#include <iostream>
#include <random>
#include <utility>

#include "HttpHandler.h"
#include <Ssl.h>
#include "../internal/internal.h"


int http(std::string bearer, std::string* targetUrl, ...) {
    using namespace std;    // nice

    // set the target url to be a predefined one, if param set to 'predefined'
    if (*targetUrl == "predefined") {
        Internal::internal pre;
        *targetUrl = pre.userAgent;
    }

    // Initialize RequestData
    networking::RequestData requestData = {
        "GET",                              // method
        *targetUrl,                         // target
        "C++/0.1",                          // userAgent
        std::move(bearer),                    // authorization (move seems to move the allocated
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

int sslEncrypt() {
    // Example plaintext
    unsigned char *plaintext = (unsigned char *)"This is a secret message";

    // 256-bit key (32 bytes)
    unsigned char *key = (unsigned char *)"01234567890123456789012345678901";

    // IV (Initialization Vector) 128-bit (16 bytes)
    unsigned char *iv = (unsigned char *)"0123456789012345";

    // Buffer for ciphertext
    unsigned char ciphertext[128];
    const int ciphertext_len = Ssl::encrypt(plaintext, strlen(reinterpret_cast<const char *>(plaintext)), key, iv, ciphertext);

    // Print the ciphertext as a hex string
    std::cout << "Ciphertext is: ";
    for (int i = 0; i < ciphertext_len; i++)
        printf("%02x", ciphertext[i]);
    std::cout << std::endl;
    return 0;
}

int main(int argc, char* argv[]) {
    // for (int i = 0; i < argc; ++i) {
    //     std::cout << argv[i] << std::endl;
    // }
    std::cout << "amount of args is " << argc << std::endl;

    std::map<std::string, std::string> headers = {{}};
    std::string url = "127.0.0.1";
    std::string method = "GET";
    std::string bearer = "unset";

    // loop through every argument passed to main
    for (int i = 1; i < argc; ++i) {
        if (argv[i][0] == '-' && argv[i][1] != '\0') {
            switch (argv[i][1]) {
                case 'u':
                    std::cout << "case u!" << std::endl;
                    url = argv[++i];
                    continue;
                case 0x6D:      // hex works too!
                    method = argv[++i];
                    continue;
                case 66 + 32:   // ascii character + 32 for lowercase (just exploring)
                    bearer = argv[++i];
                    continue;
                default:
                    std::cerr << "unknown argument: '" << argv[i][1] << "'" << std::endl;
                    break;
            }
        }
    }

    sslEncrypt();

    std::cout
    << "bearer: " << bearer << '\n' << "method: " << method <<
    std::endl;

    if (method == "unset") {
        std::cerr << "no bearer token set" << std::endl;
        return 1;
    }

    int res = http(bearer, &url, method);

    // I miss having ternary operators when writing Go...
    const std::string& result = res == 1
        ? "\033[31mnoo, it didn't work out..\033[0m"
        : "\033[32mgreat success\033[0m";

    std::cout << result << std::endl;
    return 0;
}
