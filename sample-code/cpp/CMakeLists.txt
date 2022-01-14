set(SAMPLE_CODE_CPP_TARGETS data-collection)
add_executable(data-collection "data-collection.cpp" "util.h" "util.cpp")
target_link_libraries(data-collection SeaBreeze)

set_target_properties(${SAMPLE_CODE_CPP_TARGETS} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
