cmake_minimum_required(VERSION 3.28)
project(cpp17_console_app)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenSSL REQUIRED)


add_executable(cpp17_console_app main.cpp
        src/HttpHandler.cpp
        src/HttpRequest.cpp
        include/HttpRequest.h
        internal/internal.cpp
        internal/internal.h
        src/Ssl.cpp
        include/Ssl.h
        include/Ssl.h
)

include_directories(include)

target_link_libraries(cpp17_console_app OpenSSL::SSL OpenSSL::Crypto)
