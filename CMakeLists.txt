cmake_minimum_required(VERSION 3.10)

# Project Name
project(miniRT)

# Specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Include directories
include_directories(include)
include_directories(libft/include)

# Enable testing
enable_testing()

# Add libft subdirectory
add_subdirectory(libft)

# Add custom command and target for minilibx
add_custom_command(
        OUTPUT MINILIBX_BUILD
        COMMAND ./configure
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/minilibx
)

add_custom_target(
        minilibx ALL
        DEPENDS MINILIBX_BUILD
)

# Recursively find all source files in src directory
file(GLOB_RECURSE SOURCE_FILES
        "${CMAKE_SOURCE_DIR}/src/*.c")

# Target for the main application
add_executable(miniRT ${SOURCE_FILES})

# Link the libft library and minilibx
add_dependencies(miniRT minilibx)
target_link_libraries(miniRT libft)

# Add tests
add_subdirectory(tests)
