file(GLOB COMMON_SOURCE_CXX_FILES_NATIVE_NETWORK "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_library(SeaBreezeNativeNetworkCommon SHARED ${COMMON_SOURCE_CXX_FILES_NATIVE_NETWORK})
target_link_libraries(SeaBreezeNativeNetworkCommon PRIVATE ${LIBS_TO_LINK} PUBLIC SeaBreezeExceptions)
target_compile_definitions(SeaBreezeNativeNetworkCommon PRIVATE "-DBUILD_DLL")
target_include_directories(SeaBreezeNativeNetworkCommon PUBLIC ${INCLUDE_DIR})

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
