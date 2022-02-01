message("Building Ocean FX speed test for all platforms.")
add_executable(oceanfx_speed_test "oceanfx_speed_test.c")
target_link_libraries(oceanfx_speed_test SeaBreeze)

if(MINGW)
	target_link_libraries(oceanfx_speed_test ${CMAKE_THREAD_LIBS_INIT} -lws2_32)
endif()
