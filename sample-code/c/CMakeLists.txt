add_subdirectory("demo_util_lib")

file(GLOB GLOBBED_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

set(EXCLUDED_AUTO_DEMOS "demo-qepro-api;demo-pthreads")

foreach(f ${GLOBBED_FILES})
	get_filename_component(n "${f}" NAME_WLE)
	if("${n}" IN_LIST EXCLUDED_AUTO_DEMOS)
	else()
		add_executable("${n}" "${f}")
		target_link_libraries("${n}" PRIVATE SeaBreeze demo-util)
	endif()
endforeach()

if(UNIX)
	add_executable("demo-qepro-api" "demo-qepro-api.c")
	target_link_libraries("demo-qepro-api" SeaBreeze demo-util)

	add_executable(demo-pthreads "demo-pthreads.c")
	target_link_libraries(demo-pthreads SeaBreeze demo-util ${CMAKE_THREAD_LIBS_INIT})
endif()

if(MINGW)
	target_link_libraries(demo-timeout PRIVATE ${CMAKE_THREAD_LIBS_INIT})
endif()
