find_package(Boost REQUIRED COMPONENTS unit_test_framework)

add_executable(gittests 
    dummytest.cpp
)

target_include_directories(gittests 
    PRIVATE 
        ${Boost_INCLUDE_DIRS}
)

target_link_libraries(gittests
    PRIVATE
        Boost::unit_test_framework
        git
)

add_test(all gittests)
