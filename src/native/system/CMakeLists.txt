file(GLOB COMMON_SOURCE_CXX_FILES_NATIVE_SYSTEM "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_library(SeaBreezeNativeSystemCommon OBJECT ${COMMON_SOURCE_CXX_FILES_NATIVE_SYSTEM})
target_link_libraries(SeaBreezeNativeSystemCommon PRIVATE ${LIBS_TO_LINK})
target_compile_definitions(SeaBreezeNativeSystemCommon PRIVATE "-DBUILD_DLL")
target_include_directories(SeaBreezeNativeSystemCommon PUBLIC ${INCLUDE_DIR})
set_target_properties(SeaBreezeNativeSystemCommon PROPERTIES POSITION_INDEPENDENT_CODE ON)

macro(buildSeaBreezeNativeSystem)
	buildAndPackageLib("SeaBreezeNativeSystem"
		COMPONENT "SeaBreezeNativeSystem"
		DESCRIPTION "The shared library implementing the platform-specific code used in the internal OS API-related abstraction layer"
		PRIVATE_INCLUDES ${INCLUDE_DIR}
		PRIVATE_LIBS SeaBreezeNativeSystemCommon SeaBreezeNativeUSB ${LIBS_TO_LINK} ${ARGV}
		USE_INCLUDES_FROM SeaBreeze
	)
	target_compile_definitions(SeaBreezeExceptions PRIVATE "-DBUILD_DLL")
endmacro()

add_subdirectory("${PLATFORM_DIR}")

list(APPEND SYSTEM_ABSTRACTION_LAYER_LIBS SeaBreezeNativeSystem)
set(SYSTEM_ABSTRACTION_LAYER_LIBS "${SYSTEM_ABSTRACTION_LAYER_LIBS}" PARENT_SCOPE)

pass_through_cpack_vars()
