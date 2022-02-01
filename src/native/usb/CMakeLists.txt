if(APPLE)
	set(PLATFORM_DIR_USB "osx")
elseif(UNIX)
	set(PLATFORM_DIR_USB "linux")
endif()
if(WIN32)
	set(PLATFORM_DIR_USB "winusb")
endif()

file(GLOB COMMON_SOURCE_CXX_FILES_NATIVE_USB "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_library(SeaBreezeNativeUSBCommon OBJECT ${COMMON_SOURCE_CXX_FILES_NATIVE_USB})
target_include_directories(SeaBreezeNativeUSBCommon PUBLIC ${INCLUDE_DIR})
set_target_properties(SeaBreezeNativeUSBCommon PROPERTIES POSITION_INDEPENDENT_CODE ON)

macro(buildSeaBreezeNativeUSB)
	buildAndPackageLib("SeaBreezeNativeUSB"
		COMPONENT "SeaBreezeNativeUSB"
		DESCRIPTION "The shared library implementing the platform-specific code used in the internal USB-related abstraction layer"
		PRIVATE_INCLUDES ${INCLUDE_DIR}
		PRIVATE_LIBS SeaBreezeNativeUSBCommon ${LIBS_TO_LINK} ${ARGV}
		PUBLIC_LIBS SeaBreezeExceptions SeaBreezeNativeNetworkCommon
		USE_INCLUDES_FROM SeaBreeze
	)
	target_compile_definitions(SeaBreezeExceptions PRIVATE "-DBUILD_DLL")
endmacro()

add_subdirectory("${PLATFORM_DIR_USB}")

list(APPEND SYSTEM_ABSTRACTION_LAYER_LIBS SeaBreezeNativeUSB)
set(SYSTEM_ABSTRACTION_LAYER_LIBS "${SYSTEM_ABSTRACTION_LAYER_LIBS}" PARENT_SCOPE)

pass_through_cpack_vars()
