option(WITH_TESTS "Build tests" ON)

if(WITH_TESTS)
	message("Building api test")

	if(WIN32)
		if(CYGWIN)
			add_executable(api_test WIN32 "seabreeze_test_posix.c")
		else()
			add_executable(api_test WIN32 "seabreeze_test_windows.c")
		endif()
	elseif(APPLE)
		add_executable(api_test "seabreeze_test_posix.c" "spectral_correction.c")
	elseif(UNIX)
		# build test applicaitons against the seabreeze api
		message("Building api test")
		add_executable(api_test "api_test.c")
	endif(WIN32)

	target_link_libraries(api_test SeaBreeze)
	set_target_properties("api_test" PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
endif()
