project(HSS_VoIP)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})

include_directories(/home/mio/Documents/linphone-desktop/OUTPUT/include)
find_library(L_LINPHONE linphone /home/mio/Documents/linphone-desktop/OUTPUT/lib)
#LINK_DIRECTORIES(/home/mio/Documents/linphone-desktop/OUTPUT/lib)
target_link_libraries(${PROJECT_NAME} ${L_LINPHONE})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
