


FIND_PACKAGE(Boost REQUIRED)
INCLUDE_DIRECTORIES(SYSTEM ${Boost_INCLUDE_DIRS})
#INCLUDE_DIRECTORIES("C:/Users/212760755/Documents/Barracuda_Library/vs2015/boost/1.60.0/without_mpi/64/include/boost-1_60/boost/multi_index")

#set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
#INCLUDE_DIRECTORIES(SYSTEM INCLUDE_DIR)
#SET(INCLUDE_DIR ${INCLUDE_DIR} PARENT_SCOPE)
include_directories("C:/Users/212760755/Documents/C_pp/include")


configure_file (
  "${PROJECT_SOURCE_DIR}/include/multi_index_test.hpp"
  "${PROJECT_BINARY_DIR}/multi_index_test.hpp"
  )


MESSAGE("INCLUDE_DIR is: ${INCLUDE_DIR}")
MESSAGE("Boost_INCLUDE_DIR is: ${Boost_INCLUDE_DIR}")
MESSAGE("Boost_LIBRARY_DIR is: ${Boost_LIBRARY_DIR}")
MESSAGE("BOOST_ROOT is: ${BOOST_ROOT}")
MESSAGE("CMAKE_CURRENT_SOURCE_DIR is: ${CMAKE_CURRENT_SOURCE_DIR}")

file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

MESSAGE("SOURCES is: ${SOURCES}")


add_executable(boost_test_exe ${SOURCES})













