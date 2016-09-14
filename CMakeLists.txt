cmake_minimum_required(VERSION 2.8.11)
project(libworld2d-qt)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_FLAGS}")

include_directories(${LIBLA} ${QT5_INCLUDE} ${QT5_INCLUDE}/QtWidgets ${QT5_INCLUDE}/QtCore ${QT5_INCLUDE}/QtGui)

add_subdirectory(libworld2d)
include_directories(${LIBWORLD2D})
set(LIBS ${LIBS} world2d)

set(INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/include ${LIBWORLD2D})
set(LIBWORLD2D_QT ${INCLUDE} PARENT_SCOPE)
include_directories(${INCLUDE})

set(SOURCE source/scene.cpp)

add_library(world2d-qt STATIC ${SOURCE})
target_link_libraries(world2d-qt ${LIBS})
