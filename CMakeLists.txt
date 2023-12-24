cmake_minimum_required(VERSION 3.10)

# Project Name
project(miniRT)

# Specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Enable testing
enable_testing()

# Add libft subdirectory
add_subdirectory(libft)

# Add minilibx as an external project
include(ExternalProject)
ExternalProject_Add(
        minilibx
        GIT_REPOSITORY https://github.com/42Paris/minilibx-linux.git
        GIT_TAG master
        PREFIX ${CMAKE_BINARY_DIR}/minilibx
        SOURCE_DIR ${CMAKE_BINARY_DIR}/minilibx/src/minilibx
        CONFIGURE_COMMAND ""
        BUILD_IN_SOURCE 1
        BUILD_COMMAND make -i
        INSTALL_COMMAND ""
        BUILD_BYPRODUCTS ${CMAKE_BINARY_DIR}/minilibx/src/minilibx/libmlx.a
)
ExternalProject_Get_Property(minilibx SOURCE_DIR)
set(MLX_SOURCE_DIR ${SOURCE_DIR})

# Add minilibx as a static library
add_library(mlx STATIC IMPORTED)
set_property(TARGET mlx PROPERTY IMPORTED_LOCATION ${MLX_SOURCE_DIR}/libmlx.a)

# Include directories
include_directories(include)
include_directories(libft/include)
include_directories(/usr/X11/include)
include_directories(${MLX_SOURCE_DIR})

# Recursively find all source files in src directory
file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/*.c")

# Target for the main application
add_executable(miniRT ${SOURCE_FILES})
add_dependencies(miniRT minilibx)

# Link the libft library and minilibx
target_link_directories(miniRT PUBLIC /usr/X11/lib)
target_link_libraries(miniRT ft mlx m X11 Xext)

# Add tests
add_subdirectory(tests)
