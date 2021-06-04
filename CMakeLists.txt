cmake_minimum_required(VERSION 3.17)

project(ip_filter VERSION 0.0.$ENV{GITHUB_RUN_NUMBER})

set(CMAKE_CXX_STANDARD 17)

set(SRC_MAIN main.cpp)
add_executable(ip_filter ${SRC_MAIN})

install(TARGETS ip_filter RUNTIME DESTINATION bin)
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT timoshenkonas@gmail.com)

include(CPack)

enable_testing()

add_subdirectory(test)
