
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(collate)

list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}")

find_package(Boost 1.77.0)

if(Boost_FOUND)

include_directories(${Boost_INCLUDE_DIR})
add_executable(collate main.cpp collate_example.cpp)
target_link_directories(collate PUBLIC ${Boost_LIBRARY_DIRS})
target_link_libraries(collate ${Boost_LIBRARIES})
target_include_directories (collate PUBLIC "${PROJECT_BINARY_DIR}" 
                            ${BOOST_INCLUDE_DIRS}
                            ${EXTRA_INCLUDES} )
endif()