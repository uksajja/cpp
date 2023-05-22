cmake_minimum_required(VERSION 3.18)
#Specify C++ standard
set(CMAKE_CXX_STANDARD 17)

#Set Project Name & Version
set(PROJECT_NAME cpp)
project(${PROJECT_NAME})
set(MAJOR_VERSION 2023)
set(MINOR_VERSION 0)
string(CONCAT EXE_NAME ${PROJECT_NAME} "-" ${MAJOR_VERSION} "." ${MINOR_VERSION})

#Define Build Types
set(CMAKE_CONFIGURATION_TYPES  Release Debug)

#Set Default Build Type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)
if (CMAKE_BUILD_TYPE STREQUAL "")
    # Build type is not set eg. command was "cmake .."
    message(STATUS "  Diag: Build type was unspecified, set to Release")
    set(CMAKE_BUILD_TYPE Release)
else ()
    message(STATUS "  Diag: Build type specified as '${CMAKE_BUILD_TYPE}'")
endif ()
if (${CMAKE_BUILD_TYPE} STREQUAL Debug)
    set_directory_properties(PROPERTIES COMPILE_DEFINITIONS "_DEBUG")
else ()
    set_directory_properties(PROPERTIES COMPILE_DEFINITIONS "NDEBUG")
endif ()

#Time Stamp
string(TIMESTAMP BUILD_TIME "%Y-%m-%d %H:%M:%S UTC" UTC)
string(TIMESTAMP BUILD_DATE "%Y-%m-%d" UTC)

#Testing Library
enable_testing() # to discover tests in test explorer
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)



#Sources and include directories
file(GLOB_RECURSE LIST_SOURCES CONFIGUTRE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE LIST_HEADERS CONFIGUTRE_DEPENDS "include/*.h" "src/*.h" "src/*.hpp")
set(LIST_INCUDE_DIRS "")
foreach(_headerFile ${LIST_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list(APPEND LIST_INCUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES LIST_INCUDE_DIRS)

add_executable(${EXE_NAME} ${LIST_SOURCES})
target_include_directories(${EXE_NAME} PRIVATE ${LIST_INCUDE_DIRS})
target_link_libraries(${EXE_NAME} PRIVATE gtest)

add_compile_options(${EXE_NAME} PRIVATE
    $<$<COMPILE_LANGUAGE:CXX:/w >
)









