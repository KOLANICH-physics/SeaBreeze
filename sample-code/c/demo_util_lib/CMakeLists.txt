add_library(demo-util "util.h" "util.c")
target_include_directories(demo-util PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(demo-util PRIVATE SeaBreeze)

if(MINGW)
	target_link_libraries(demo-util PRIVATE ${CMAKE_THREAD_LIBS_INIT})
endif()
