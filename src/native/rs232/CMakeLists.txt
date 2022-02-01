file(GLOB COMMON_SOURCE_CXX_FILES_NATIVE_RS232 "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_library(SeaBreezeNativeRS232Common OBJECT ${COMMON_SOURCE_CXX_FILES_NATIVE_RS232})
target_link_libraries(SeaBreezeNativeRS232Common PRIVATE ${LIBS_TO_LINK} SeaBreezeExceptions)
target_compile_definitions(SeaBreezeNativeRS232Common PRIVATE "-DBUILD_DLL")
target_include_directories(SeaBreezeNativeRS232Common PUBLIC ${INCLUDE_DIR})
set_target_properties(SeaBreezeNativeRS232Common PROPERTIES POSITION_INDEPENDENT_CODE ON)

file(GLOB SOURCE_CXX_FILES_NATIVE_RS232 "${CMAKE_CURRENT_SOURCE_DIR}/${PLATFORM_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/${PLATFORM_DIR}/*.c")
add_library(SeaBreezeNativeRS232 SHARED ${SOURCE_CXX_FILES_NATIVE_RS232})
target_link_libraries(SeaBreezeNativeRS232 PRIVATE ${LIBS_TO_LINK} SeaBreezeExceptions SeaBreezeNativeRS232Common)
target_compile_definitions(SeaBreezeNativeRS232 PRIVATE "-DBUILD_DLL")
target_include_directories(SeaBreezeNativeRS232 PUBLIC ${INCLUDE_DIR})


list(APPEND SYSTEM_ABSTRACTION_LAYER_LIBS SeaBreezeNativeRS232)
set(SYSTEM_ABSTRACTION_LAYER_LIBS "${SYSTEM_ABSTRACTION_LAYER_LIBS}" PARENT_SCOPE)

