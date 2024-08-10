cmake_minimum_required(VERSION 3.28)
project(cpp17_console_app)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp17_console_app main.cpp
        src/HttpHandler.cpp
        src/HttpRequest.cpp
        include/HttpRequest.h
        internal/internal.cpp
        internal/internal.h
)

include_directories(include)

