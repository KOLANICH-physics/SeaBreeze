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


file(GLOB SOURCE_CXX_FILES_NATIVE_NETWORK "${CMAKE_CURRENT_SOURCE_DIR}/${PLATFORM_DIR}/*.cpp")
add_library(SeaBreezeNativeNetwork SHARED ${SOURCE_CXX_FILES_NATIVE_NETWORK})
target_link_libraries(SeaBreezeNativeNetwork PRIVATE ${LIBS_TO_LINK} SeaBreezeExceptions SeaBreezeNativeNetworkCommon)
target_compile_definitions(SeaBreezeNativeNetwork PRIVATE "-DBUILD_DLL")
target_include_directories(SeaBreezeNativeNetwork PUBLIC ${INCLUDE_DIR})

if(WIN32)
	target_link_libraries(SeaBreezeNativeNetwork PRIVATE "-lws2_32")
	target_link_libraries(SeaBreezeNativeNetworkCommon PRIVATE "-lws2_32")
endif()

list(APPEND SYSTEM_ABSTRACTION_LAYER_LIBS SeaBreezeNativeNetwork)
set(SYSTEM_ABSTRACTION_LAYER_LIBS "${SYSTEM_ABSTRACTION_LAYER_LIBS}" PARENT_SCOPE)

pass_through_cpack_vars()
