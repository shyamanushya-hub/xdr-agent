add_executable(xdr_agent
  src/main.cpp
  src/agent.cpp
)

target_include_directories(xdr_agent PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(xdr_agent PRIVATE xdr_common)
