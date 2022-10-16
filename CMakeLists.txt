cmake_minimum_required(VERSION 2.8.10)

project(usv_arch C CXX)

include_directories(
    include
)

file(GLOB ARCH_SRCs src/*.cpp)

list(REMOVE_ITEM ARCH_SRCs "src/main.cpp")

add_library(${PROJECT_NAME} STATIC ${ARCH_SRCs})

set_target_properties(${PROJECT_NAME}
                      PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_link_libraries(${PROJECT_NAME})

add_executable(arch_example src/main.cpp)
target_link_libraries(arch_example ${PROJECT_NAME})

set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
