project(HSS_PushServer)
cmake_minimum_required(VERSION 2.8)

aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})


set(Boost_USE_STATIC_LIBS        ON) # only find static libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost 1.60.0 COMPONENTS filesystem python system REQUIRED)

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif()

find_package(PythonLibs 2 REQUIRED)
if(PYTHONLIBS_FOUND)
  include_directories(${PYTHON_INCLUDE_DIRS})
  target_link_libraries(${PROJECT_NAME} ${PYTHON_LIBRARIES})
endif()

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
