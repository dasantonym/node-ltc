cmake_minimum_required(VERSION 2.8)
project(node_ltc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -stdlib=libc++")

find_package(PkgConfig)
pkg_check_modules(LIBLTC REQUIRED ltc)

include_directories(${CMAKE_JS_INC} ${LIBLTC_INCLUDES} /usr/local/include/node/ ./node_modules/nan)

file(GLOB SOURCE_FILES
    "src/*.cc" "src/*.h"
    )

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")
target_link_libraries(${PROJECT_NAME} ${LIBLTC_LIBRARIES} ${CMAKE_JS_LIB})
