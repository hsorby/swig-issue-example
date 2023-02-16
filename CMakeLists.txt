
cmake_minimum_required(VERSION 3.10.2)

project(SWIG-Example LANGUAGES CXX)

cmake_policy(SET CMP0078 NEW)
cmake_policy(SET CMP0086 NEW)

include(GenerateExportHeader)

set(BUILD_SHARED_LIBS TRUE)

find_package(Python REQUIRED Development)
find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})

set(EXAMPLES_EXPORTDEFINITIONS_H ${CMAKE_CURRENT_BINARY_DIR}/examplesexportdefinitions.h)

add_library(examples foo.cpp foo.h bar.cpp bar.h baz.cpp baz.h ${EXAMPLES_EXPORTDEFINITIONS_H})
target_include_directories(examples PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
set_target_properties(examples PROPERTIES
  CXX_VISIBILITY_PRESET hidden
  VISIBILITY_INLINES_HIDDEN 1
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED YES
  CXX_EXTENSIONS NO
)

generate_export_header(examples EXPORT_FILE_NAME ${EXAMPLES_EXPORTDEFINITIONS_H} BASE_NAME EXAMPLES)

set(INTERFACE_SRCS
  ${CMAKE_CURRENT_SOURCE_DIR}/foo.i
  ${CMAKE_CURRENT_SOURCE_DIR}/bar.i
  ${CMAKE_CURRENT_SOURCE_DIR}/baz.i
)

foreach(_SRC ${INTERFACE_SRCS})
  get_filename_component(MODULE_TARGET ${_SRC} NAME_WE)
  set_source_files_properties(${_SRC} PROPERTIES
    CPLUSPLUS ON
  )

  swig_add_library(${MODULE_TARGET}
    LANGUAGE python
    SOURCES ${_SRC}
    OUTFILE_DIR swig_generated_cpp
  )

  target_link_libraries(${MODULE_TARGET} PRIVATE examples Python::Python)
  target_include_directories(${MODULE_TARGET} PRIVATE ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
  set_target_properties(${MODULE_TARGET} PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN 1
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
  )
endforeach()

