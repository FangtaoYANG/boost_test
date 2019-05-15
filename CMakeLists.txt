

CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(boost_test)

ADD_SUBDIRECTORY(src)

# SET(Boost_NO_SYSTEM_PATHS true)
# SET (Boost_USE_STATIC_LIBS ON CACHE BOOL "use static libraries from Boost")


#FIND_PACKAGE(Boost REQUIRED)
#INCLUDE_DIRECTORIES(SYSTEM ${Boost_INCLUDE_DIRS})
#INCLUDE_DIRECTORIES("C:/Users/212760755/Documents/Barracuda_Library/vs2015/boost/1.60.0/without_mpi/64/include/boost-1_60/boost/multi_index")

#set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
#INCLUDE_DIRECTORIES(INCLUDE_DIR)
#include_directories(include)

#MESSAGE("INCLUDE_DIR is: ${INCLUDE_DIR}")
#MESSAGE("Boost_INCLUDE_DIR is: ${Boost_INCLUDE_DIR}")
#MESSAGE("Boost_LIBRARY_DIR is: ${Boost_LIBRARY_DIR}")
#MESSAGE("BOOST_ROOT is: ${BOOST_ROOT}")

#file(GLOB SOURCES "src/*.cpp")
#add_executable(boost_test_exe ${SOURCES})













