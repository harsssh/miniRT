# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Google Test v1.14.0
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        f8d7d77c06936315286eb55f8de22cd23c188571
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# Include the headers
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/libft/include)

# Add the tests
## Vector
file(GLOB_RECURSE VECTOR_SOURCES ${CMAKE_SOURCE_DIR}/src/vector/*.c)
add_executable(test_vector test_vector.cpp ${VECTOR_SOURCES})
target_link_libraries(test_vector gtest_main gtest)
gtest_discover_tests(test_vector)
