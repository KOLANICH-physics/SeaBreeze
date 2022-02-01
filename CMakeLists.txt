cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 98)
#set(CMAKE_BUILD_TYPE DEBUG)

project(SeaBreeze)

find_package(Threads REQUIRED)

set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")

file(GLOB_RECURSE COMMON_SOURCE_HPP_FILES "${INCLUDE_DIR}/api/seabreezeapi/*.h" "${INCLUDE_DIR}/api/*.h" "${INCLUDE_DIR}/common/*.h" "${INCLUDE_DIR}/native/*.h" "${INCLUDE_DIR}/vendors/OceanOptics/*.h")
file(GLOB_RECURSE COMMON_SOURCE_CXX_FILES "src/api/seabreezeapi/*.cpp" "src/api/*.cpp" "src/common/*.cpp" "src/vendors/OceanOptics/*.cpp")

set(NATIVE_DIR "src/native")
file(GLOB COMMON_SOURCE_CXX_FILES_NATIVE_SYSTEM "${NATIVE_DIR}/system/*.cpp")
file(GLOB COMMON_SOURCE_CXX_FILES_NATIVE_USB "${NATIVE_DIR}/usb/*.cpp" "${NATIVE_DIR}/usb/*.cpp")

set(COMMON_SOURCE_FILES ${COMMON_SOURCE_HPP_FILES} ${COMMON_SOURCE_CXX_FILES})

if(WIN32)
	#add_compile_options(-std=c++0x)
	message("Compiling for Windows")
	set(WINDOWS_TEST_SOURCE_FILES
		test/VisualStudio2015/windows_api_test/stdafx.cpp
		test/VisualStudio2015/windows_api_test/stdafx.h
		test/VisualStudio2015/windows_api_test/targetver.h
		test/VisualStudio2015/windows_api_test/windows_api_test.cpp
	)
	set(PLATFORM_WINDOWS_HEADER_FILES
		include/native/rs232/windows/NativeRS232Windows.h
		include/native/network/windows/NativeSocketWindows.h
		include/native/usb/winusb/WindowsGUID.h
	)

	set(PLATFORM_SOURCE_FILES_STUDIO
		os-support/windows/VisualStudio2010/VSProj/resource.h
		os-support/windows/VisualStudio2010/VSProj/stdafx.cpp
		os-support/windows/VisualStudio2010/VSProj/stdafx.h
		os-support/windows/VisualStudio2012/VSProj/resource.h
		os-support/windows/VisualStudio2012/VSProj/stdafx.cpp
		os-support/windows/VisualStudio2012/VSProj/stdafx.h
		os-support/windows/VisualStudio2013/VSProj/resource.h
		os-support/windows/VisualStudio2013/VSProj/stdafx.cpp
		os-support/windows/VisualStudio2013/VSProj/stdafx.h
		os-support/windows/VisualStudio2015/VSProj/resource.h
		os-support/windows/VisualStudio2015/VSProj/stdafx.cpp
		os-support/windows/VisualStudio2015/VSProj/stdafx.h
	)
	set(CSHARP_SAMPLE_FILES
		sample-code/CSharpDemo/Properties/AssemblyInfo.cs
		sample-code/CSharpDemo/Properties/Resources.Designer.cs
		sample-code/CSharpDemo/Properties/Resources.resx
		sample-code/CSharpDemo/Properties/Settings.Designer.cs
		sample-code/CSharpDemo/Properties/Settings.settings
		sample-code/CSharpDemo/Setup/Setup.vdproj
		sample-code/CSharpDemo/app.config
		sample-code/CSharpDemo/CSharpDemo.csproj
		sample-code/CSharpDemo/Form1.cs
		sample-code/CSharpDemo/Form1.Designer.cs
		sample-code/CSharpDemo/Form1.resx
		sample-code/CSharpDemo/Logger.cs
		sample-code/CSharpDemo/OmniDriverSpectrometer.cs
		sample-code/CSharpDemo/Program.cs
		sample-code/CSharpDemo/README.TXT
		sample-code/CSharpDemo/SeaBreezeAPI.cs
		sample-code/CSharpDemo/SeaBreezeSpectrometer.cs
		sample-code/CSharpDemo/SeaBreezeWrapper.cs
		sample-code/CSharpDemo/Spectrometer.cs
	)
	set(CONSOLE_DEMO_SAMPLE_FILES
		sample-code/VisualCppConsoleDemo/src/stdafx.cpp
		sample-code/VisualCppConsoleDemo/src/stdafx.h
		sample-code/VisualCppConsoleDemo/src/targetver.h
		sample-code/VisualCppConsoleDemo/src/VisualCppConsoleDemo.cpp
	)
	set(PLATFORM_SOURCE_FILES ${PLATFORM_WINDOWS_HEADER_FILES} ${PLATFORM_SOURCE_FILES_STUDIO})
	# ${CSHARP_SAMPLE_FILES} ${CONSOLE_DEMO_SAMPLE_FILES} ${WINDOWS_TEST_SOURCE_FILES}

	message("Building Windows")
	set(LIBS_TO_LINK "-lwinusb" "-lws2_32" "-lsetupapi")
endif()


if(APPLE)
	message("Building SeaBreeze for OS X, Darwin")
	set(CMAKE_OSX_ARCHITECTURES "x86_64")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -ggdb ")

	find_library(IOKIT_FRAMEWORK IOKit)
	find_library(COREFOUNDATION_FRAMEWORK CoreFoundation)
	set(LIBS_TO_LINK ${COREFOUNDATION_FRAMEWORK} ${IOKIT_FRAMEWORK})
	list(APPEND PLATFORM_SOURCE_FILES ${COMMON_SOURCE_CXX_POSIX_FILES_NATIVE})
elseif(UNIX)
# need to copy os-support/linux/FilesToInstall/10-oceanoptics.rules to the rules folder

	message("Building for Unix-like platforms")
	#add_compile_options(-std=c++0x)

	set(LIBS_TO_LINK ${CMAKE_THREAD_LIBS_INIT})
endif()

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wno-dynamic-exception-spec")

if(APPLE)
	set(PLATFORM_DIR_USB "osx")
elseif(UNIX)
	set(PLATFORM_DIR_USB "linux")
endif()
if(WIN32)
	set(PLATFORM_DIR_USB "winusb")
endif()
file(GLOB SOURCE_CXX_FILES_NATIVE_USB "${NATIVE_DIR}/usb/${PLATFORM_DIR_USB}/*.c")

add_library(SeaBreezeNativeUSB SHARED ${SOURCE_CXX_FILES_NATIVE_USB} ${COMMON_SOURCE_CXX_FILES_NATIVE_USB})
target_link_libraries(SeaBreezeNativeUSB PRIVATE ${LIBS_TO_LINK})
if(APPLE)
elseif(UNIX)
	target_link_libraries(SeaBreezeNativeUSB PRIVATE usb ${CMAKE_THREAD_LIBS_INIT})
endif()
target_compile_definitions(SeaBreezeNativeUSB PRIVATE "-DBUILD_DLL")
target_include_directories(SeaBreezeNativeUSB PUBLIC ${INCLUDE_DIR})

if(APPLE OR UNIX)
	set(PLATFORM_DIR "posix")
endif()
if(WIN32)
	set(PLATFORM_DIR "windows")
endif()
file(GLOB SOURCE_CXX_FILES_NATIVE_SYSTEM "${NATIVE_DIR}/system/${PLATFORM_DIR}/*.cpp" "${NATIVE_DIR}/system/${PLATFORM_DIR}/*.c")
add_library(SeaBreezeNativeSystem SHARED ${COMMON_SOURCE_CXX_FILES_NATIVE_SYSTEM} ${SOURCE_CXX_FILES_NATIVE_SYSTEM})
target_link_libraries(SeaBreezeNativeSystem PRIVATE ${LIBS_TO_LINK} SeaBreezeNativeUSB)
target_compile_definitions(SeaBreezeNativeSystem PRIVATE "-DBUILD_DLL")
target_include_directories(SeaBreezeNativeSystem PUBLIC ${INCLUDE_DIR})

add_subdirectory("${NATIVE_DIR}/rs232")
add_subdirectory("${NATIVE_DIR}/network")

add_library(SeaBreeze SHARED ${COMMON_SOURCE_FILES} ${PLATFORM_SOURCE_FILES})
target_link_libraries(SeaBreeze PRIVATE ${LIBS_TO_LINK} SeaBreezeNativeUSB SeaBreezeNativeSystem SeaBreezeNativeRS232 SeaBreezeNativeNetwork)
target_compile_definitions(SeaBreeze PRIVATE "-DBUILD_DLL")
target_include_directories(SeaBreeze PUBLIC ${INCLUDE_DIR})

add_subdirectory("test")

message("Building sample code for all platforms.")

add_subdirectory("sample-code")

message("Building Ocean FX speed test for all platforms.")
add_executable(oceanfx_speed_test "oceanfx_speed_test/oceanfx_speed_test.c")
target_link_libraries(oceanfx_speed_test SeaBreeze)

if(MINGW)
	target_link_libraries(oceanfx_speed_test ${CMAKE_THREAD_LIBS_INIT} -lws2_32)
endif()
