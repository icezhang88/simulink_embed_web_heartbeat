cmake_minimum_required(VERSION 3.22)
project(serial_smooth)

include_directories(
        /usr/local/include
        include
)
link_directories(
        /usr/local/lib
        src
)

set(CMAKE_CXX_STANDARD 14)

find_package(spdlog)
find_package(nlohmann_json CONFIG REQUIRED)

file(GLOB SRC_FILE src/*.cpp )
add_executable(serial_smooth main.cpp ${SRC_FILE})

target_link_libraries(${PROJECT_NAME} PUBLIC spdlog::spdlog)
target_link_libraries(${PROJECT_NAME} PUBLIC libserial.a)
target_link_libraries(${PROJECT_NAME} PUBLIC libhv_static.a)
target_link_libraries(${PROJECT_NAME} PUBLIC nlohmann_json::nlohmann_json)