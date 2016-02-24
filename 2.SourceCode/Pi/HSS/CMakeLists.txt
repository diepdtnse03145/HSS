project(HSS)
cmake_minimum_required(VERSION 2.8)

aux_source_directory(. SRC_LIST)
aux_source_directory(ConnectionLayer CONNECTION_LAYER)
LIST(APPEND SRC_LIST ${CONNECTION_LAYER})
aux_source_directory(ConnectionLayer/RPC_Base CONNECTION_LAYER_RPC_BASE)
LIST(APPEND SRC_LIST ${CONNECTION_LAYER_RPC_BASE})
aux_source_directory(ConnectionLayer/RPC_Client CONNECTION_LAYER_RPC_CLIENT)
LIST(APPEND SRC_LIST ${CONNECTION_LAYER_RPC_CLIENT})
aux_source_directory(ConnectionLayer/RPC_Server CONNECTION_LAYER_RPC_SERVER)
LIST(APPEND SRC_LIST ${CONNECTION_LAYER_RPC_SERVER})

add_executable(${PROJECT_NAME} ${SRC_LIST})

set(Boost_USE_STATIC_LIBS        ON) # only find static libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost 1.55.0 COMPONENTS date_time filesystem system )

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif()

if(WIN32)
    target_link_libraries(${PROJECT_NAME} wsock32 ws2_32)
endif()

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
