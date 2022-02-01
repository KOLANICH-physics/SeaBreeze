buildAndPackageLib("SeaBreezeNativeNetworkCommon"
	NON_RECURSIVE_GLOB
	COMPONENT "SeaBreezeNativeNetworkCommon"
	DESCRIPTION "The shared library implementing the common code usied in the internal network abstraction layer"
	PUBLIC_INCLUDES ${INCLUDE_DIR}
	PRIVATE_LIBS ${LIBS_TO_LINK}
	PUBLIC_LIBS SeaBreezeExceptions
	USE_INCLUDES_FROM SeaBreeze
)
target_compile_definitions(SeaBreezeExceptions PRIVATE "-DBUILD_DLL")

if(WIN32)
	target_link_libraries(SeaBreezeNativeNetworkCommon PRIVATE "-lws2_32")
endif()

macro(buildSeaBreezeNativeNetwork)
	buildAndPackageLib("SeaBreezeNativeNetwork"
		COMPONENT "SeaBreezeNativeNetwork"
		DESCRIPTION "The shared library implementing the platform-specific code used in the internal network abstraction layer"
		PRIVATE_INCLUDES ${INCLUDE_DIR}
		PRIVATE_LIBS ${LIBS_TO_LINK}
		PUBLIC_LIBS SeaBreezeExceptions SeaBreezeNativeNetworkCommon
		USE_INCLUDES_FROM SeaBreeze
	)
	target_compile_definitions(SeaBreezeExceptions PRIVATE "-DBUILD_DLL")
endmacro()

add_subdirectory("${PLATFORM_DIR}")

list(APPEND SYSTEM_ABSTRACTION_LAYER_LIBS SeaBreezeNativeNetwork)
set(SYSTEM_ABSTRACTION_LAYER_LIBS "${SYSTEM_ABSTRACTION_LAYER_LIBS}" PARENT_SCOPE)

pass_through_cpack_vars()
