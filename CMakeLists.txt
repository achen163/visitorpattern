CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(iterator
	main.cpp
	binary_iterator.cpp
	unary_iterator.cpp
	preorder_iterator.cpp
)
ADD_EXECUTABLE(test
        unit_test.cpp
	binary_iterator.cpp
	unary_iterator.cpp
	preorder_iterator.cpp
)

SET(DEBUG_FLAG "-g")
add_definitions(${DEBUG_FLAG})

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

