set(Boost_USE_STATIC_LIBS OFF)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

include_directories(${Boost_INCLUDE_DIR})

add_executable(test_ip test.cpp)
target_link_libraries(test_ip ${Boost_LIBRARIES})

add_test(test_ip test_ip)