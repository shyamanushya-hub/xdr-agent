add_library(xdr_common STATIC
  src/log.cpp
)

target_include_directories(xdr_common PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
