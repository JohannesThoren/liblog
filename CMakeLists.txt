cmake_minimum_required(VERSION 3.10)

# set the project name
project(liblog)

# specify the C standard
add_library(liblog STATIC src/log.c include/log.h)

target_include_directories(liblog PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(test_logger tests/test_logger.c)

target_link_libraries(test_logger liblog)
