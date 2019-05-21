find_package(Boost REQUIRED COMPONENTS filesystem)

add_library(git
	Init.cpp
	Init.h
	Add.h
	Add.cpp)

target_include_directories(git 
    PRIVATE 
        ${Boost_INCLUDE_DIRS}
)

target_link_libraries(git
	PRIVATE
		Boost::filesystem
)