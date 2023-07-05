cmake_minimum_required(VERSION 3.25)

project(EventProcessor)

# ---------------------------------------- Link Boost Library          ----------------------------------------
include(FetchContent) 

set(FETCHCONTENT_QUIET OFF)

include(FetchContent)
FetchContent_Declare(
  Boost
  GIT_REPOSITORY https://github.com/boostorg/boost.git
  GIT_TAG boost-1.80.0
  GIT_SHALLOW TRUE
)

FetchContent_GetProperties(boost)
if(NOT boost_POPULATED)
  FetchContent_Populate(boost)
  add_subdirectory(${boost_SOURCE_DIR} ${boost_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# ---------------------------------------- Add source files to project ----------------------------------------

# ---------------------------------------- Set include directories     ----------------------------------------

# ---------------------------------------- Set installation targets    ----------------------------------------

# ---------------------------------------- Create CMake package        ----------------------------------------

# ---------------------------------------- Install                     ----------------------------------------


