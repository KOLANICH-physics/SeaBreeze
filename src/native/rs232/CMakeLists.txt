file(GLOB COMMON_SOURCE_CXX_FILES_NATIVE_RS232 "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_library(SeaBreezeNativeRS232Common OBJECT ${COMMON_SOURCE_CXX_FILES_NATIVE_RS232})
target_link_libraries(SeaBreezeNativeRS232Common PRIVATE ${LIBS_TO_LINK} SeaBreezeExceptions)
target_compile_definitions(SeaBreezeNativeRS232Common PRIVATE "-DBUILD_DLL")
target_include_directories(SeaBreezeNativeRS232Common PUBLIC ${INCLUDE_DIR})
set_target_properties(SeaBreezeNativeRS232Common PROPERTIES POSITION_INDEPENDENT_CODE ON)

macro(buildSeaBreezeNativeRS232)
	buildAndPackageLib("SeaBreezeNativeRS232"
		COMPONENT "SeaBreezeNativeRS232"
		DESCRIPTION "The shared library implementing the platform-specific code used in the internal RS232-related abstraction layer"
		PRIVATE_INCLUDES ${INCLUDE_DIR}
		PRIVATE_LIBS SeaBreezeNativeRS232Common ${LIBS_TO_LINK} ${ARGV}
		PUBLIC_LIBS SeaBreezeExceptions
		USE_INCLUDES_FROM SeaBreeze
	)
	target_compile_definitions(SeaBreezeExceptions PRIVATE "-DBUILD_DLL")
endmacro()

add_subdirectory("${PLATFORM_DIR}")

list(APPEND SYSTEM_ABSTRACTION_LAYER_LIBS SeaBreezeNativeRS232)
set(SYSTEM_ABSTRACTION_LAYER_LIBS "${SYSTEM_ABSTRACTION_LAYER_LIBS}" PARENT_SCOPE)

pass_through_cpack_vars()
