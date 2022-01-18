add_subdirectory("demo_util_lib")
set_target_properties(demo-util PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

file(GLOB GLOBBED_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

set(EXCLUDED_AUTO_DEMOS "demo-qepro-api")

foreach(f ${GLOBBED_FILES})
	get_filename_component(n "${f}" NAME_WLE)
	if("${n}" IN_LIST EXCLUDED_AUTO_DEMOS)
	else()
		add_executable("${n}" "${f}")
		target_link_libraries("${n}" SeaBreeze demo-util)
		set_target_properties("${n}" PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
	endif()
endforeach()

target_link_libraries(demo-pthreads ${CMAKE_THREAD_LIBS_INIT})
