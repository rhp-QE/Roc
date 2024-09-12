cmake_minimum_required(VERSION 3.5.0)
set (CMAKE_TOOLCHAIN_FILE "/root/tools/vcpkg/scripts/buildsystems/vcpkg.cmake")
set (CMAKE_CXX_STANDARD 20)
project(roc VERSION 0.1.0 LANGUAGES C CXX)

add_executable(roc main.cpp test.cpp)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

include_directories(${PROJECT_SOURCE_DIR})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_TOOLCHAIN_FILE "/root/tools/vcpkg/scripts/buildsystems/vcpkg.cmake")

# glog
find_package(glog CONFIG REQUIRED)
target_link_libraries(roc PRIVATE glog::glog)

add_subdirectory(base)