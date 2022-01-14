add_subdirectory("demo_util_lib")
set_target_properties(demo-util PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

file(GLOB GLOBBED_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

foreach(f ${GLOBBED_FILES})
	get_filename_component(n "${f}" NAME_WLE)
	add_executable("${n}" "${f}")
	target_link_libraries("${n}" SeaBreeze demo-util)
	set_target_properties("${n}" PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
endforeach()

target_link_libraries(demo-pthreads ${CMAKE_THREAD_LIBS_INIT})
