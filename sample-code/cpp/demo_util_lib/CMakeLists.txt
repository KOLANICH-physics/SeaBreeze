add_library(demo-util-cpp "util.h" "util.cpp")
target_include_directories(demo-util-cpp PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(demo-util-cpp PRIVATE SeaBreeze)

if(MINGW)
	target_link_libraries(demo-util-cpp PRIVATE ${CMAKE_THREAD_LIBS_INIT})
endif()
