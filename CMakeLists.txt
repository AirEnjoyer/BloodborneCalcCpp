cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(BloodborneCalc CXX)

add_executable(BloodborneCalc
src/main.cpp
src/weapon_data.cpp
src/damage.cpp)
target_link_libraries(BloodborneCalc m)


include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

