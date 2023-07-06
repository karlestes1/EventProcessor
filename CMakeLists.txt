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

# ---------------------------------------- Add source files to library ----------------------------------------
add_library(EventProcessor SHARED
  src/Event.hpp
  src/Event.cpp
  src/EventQueue.hpp
  src/EventQueue.cpp
  src/SimulationClock.hpp
  src/SimulationClock.cpp
)

target_link_libraries(EventProcessor PRIVATE
  Boost::uuid
)

# # ---------------------------------------- Set include directories     ----------------------------------------
# target_include_directories(EventProcessor PUBLIC
#   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#   $<INSTALL_INTERFACE:include>
#   ${Boost_INCLUDE_DIRS}
# )

# # ---------------------------------------- Set installation targets    ----------------------------------------
# install(TARGETS EventProcessor EXPORT EventProcessorTargets
#   LIBRARY DESTINATION lib
#   ARCHIVE DESTINATION lib
#   RUNTIME DESTINATION bin
#   INCLUDES DESTINATION include
# )

# install(DIRECTORY include/ DESTINATION include)

# install(EXPORT EventProcessorTargets
#   FILE EventProcessorTargets.cmake
#   NAMESPACE EventProcessor::
#   DESTINATION lib/cmake/EventProcessor
# )

# include(CMakePackageConfigHelpers)
# write_basic_package_version_file(
#   ${CMAKE_CURRENT_BINARY_DIR}/EventProcessorConfigVersion.cmake
#   VERSION 1.0.0
#   COMPATIBILITY AnyNewerVersion
# )

# configure_package_config_file(
#   ${CMAKE_CURRENT_LIST_DIR}/cmake/EventProcessorConfig.cmake.in
#   ${CMAKE_CURRENT_BINARY_DIR}/EventProcessorConfig.cmake
#   INSTALL_DESTINATION lib/cmake/EventProcessor
# )

# install(
#   FILES
#     ${CMAKE_CURRENT_BINARY_DIR}/EventProcessorConfig.cmake
#     ${CMAKE_CURRENT_BINARY_DIR}/EventProcessorConfigVersion.cmake
#   DESTINATION lib/cmake/EventProcessor
# )

# # ---------------------------------------- Install                     ----------------------------------------
# install(TARGETS EventProcessor DESTINATION lib)