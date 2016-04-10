project(HSS)
cmake_minimum_required(VERSION 2.8)

aux_source_directory(. HSS_SRC_LIST)
aux_source_directory(Connection HSS_SRC_LIST)
aux_source_directory(Engine HSS_SRC_LIST)
aux_source_directory(Setting HSS_SRC_LIST)
aux_source_directory(Database HSS_SRC_LIST)

add_executable(${PROJECT_NAME} ${HSS_SRC_LIST})

set(Boost_USE_STATIC_LIBS        ON) # only find static libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost 1.60.0 COMPONENTS filesystem system python date_time REQUIRED)

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif()

find_package(PythonLibs 2 REQUIRED)
if(PYTHONLIBS_FOUND)
  include_directories(${PYTHON_INCLUDE_DIRS})
  target_link_libraries(${PROJECT_NAME} ${PYTHON_LIBRARIES})
endif()

if(WIN32)
    target_link_libraries(${PROJECT_NAME} wsock32 ws2_32)
endif()

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})

set(HSS_LIBS_DIR Libs)
set(nlohman_json_INCLUDE ${HSS_LIBS_DIR}/nlohmann-json/src)
include_directories(${PROJECT_NAME} ${nlohman_json_INCLUDE})

add_subdirectory(${HSS_LIBS_DIR}/cppformat)
set(cppformat_INCLUDE ${HSS_LIB_DIR}/cppformat)
include_directories(${PROJECT_NAME} ${nlohman_json_INCLUDE})
target_link_libraries(${PROJECT_NAME} cppformat)

option(SQLITECPP_RUN_CPPLINT "Run cpplint.py tool for Google C++ StyleGuide." OFF)
add_subdirectory(${HSS_LIBS_DIR}/SQLiteCpp)
set(SQLiteCpp_INCLUDE ${HSS_LIBS_DIR}/SQLiteCpp/include)
include_directories(${PROJECT_NAME} ${SQLiteCpp_INCLUDE})
target_link_libraries(${PROJECT_NAME} SQLiteCpp sqlite3)
if(UNIX)
    target_link_libraries(${PROJECT_NAME} dl)
endif()

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
file(COPY "setting.json" DESTINATION ${CMAKE_BINARY_DIR})
file(COPY "HSS.sqlite" DESTINATION ${CMAKE_BINARY_DIR})
