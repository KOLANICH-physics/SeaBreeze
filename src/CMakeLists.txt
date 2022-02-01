set(SYSTEM_ABSTRACTION_LAYER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/native")
set(MAIN_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/main")

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wno-dynamic-exception-spec")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/exceptions")
add_subdirectory("${SYSTEM_ABSTRACTION_LAYER_DIR}")
add_subdirectory("${MAIN_LIB_DIR}")
