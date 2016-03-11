project(HSS)
cmake_minimum_required(VERSION 2.8)

aux_source_directory(. SRC_LIST)
aux_source_directory(Connection HSS_CONNECTION)
LIST(APPEND SRC_LIST ${HSS_CONNECTION})
aux_source_directory(Engine HSS_ENGINE)
LIST(APPEND SRC_LIST ${HSS_ENGINE})
aux_source_directory(Setting HSS_SETTING)
LIST(APPEND SRC_LIST ${HSS_SETTING})

add_executable(${PROJECT_NAME} ${SRC_LIST})

set(Boost_USE_STATIC_LIBS        ON) # only find static libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost 1.60.0 COMPONENTS filesystem system )

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif()

if(WIN32)
    target_link_libraries(${PROJECT_NAME} wsock32 ws2_32)
endif()

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} )

set(HSS_LIBS_DIR Libs)
set(nlohman_json_INCLUDE ${HSS_LIBS_DIR}/json-master/src)
include_directories(${PROJECT_NAME} ${nlohman_json_INCLUDE})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
#file(COPY "setting.json" DESTINATION ${CMAKE_BINARY_DIR})
