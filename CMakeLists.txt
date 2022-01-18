#
#
# This CMakeLists file has not been set up for Windows or Linux yet. It only runs on OS X
#
#


cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 98)
#set(CMAKE_BUILD_TYPE DEBUG)

project(SeaBreeze)

find_package(Threads REQUIRED)

set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib/")

file(GLOB_RECURSE COMMON_SOURCE_HPP_FILES "include/api/seabreezeapi/*.h" "include/api/*.h" "include/common/*.h" "include/native/*.h" "include/vendors/OceanOptics/*.h")
file(GLOB_RECURSE COMMON_SOURCE_CXX_FILES "src/api/seabreezeapi/*.cpp" "src/api/*.cpp" "src/common/*.cpp" "src/vendors/OceanOptics/*.cpp")

file(GLOB COMMON_SOURCE_CXX_FILES_NATIVE "src/native/network/*.cpp" "src/native/rs232/*.cpp" "src/native/system/*.cpp" "src/native/usb/*.cpp")
file(GLOB COMMON_SOURCE_CXX_POSIX_FILES_NATIVE "src/native/network/posix/*.cpp" "src/native/rs232/posix/*.cpp" "src/native/rs232/posix/*.c" "src/native/system/posix/*.cpp" "src/native/system/posix/*.c" "src/native/usb/posix/*.cpp")

set(COMMON_SOURCE_FILES ${COMMON_SOURCE_HPP_FILES} ${COMMON_SOURCE_CXX_FILES} ${COMMON_SOURCE_CXX_FILES_NATIVE})

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
	set(PLATFORM_WINDOWS_SOURCE_FILES_NATIVE
		src/native/rs232/windows/NativeRS232Windows.c
		src/native/system/windows/NativeSystemWindows.c
		src/native/network/windows/NativeSocketWindows.cpp
		src/native/usb/winusb/NativeUSBWinUSB.c
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
	set(PLATFORM_SOURCE_FILES_WINDDK
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
		os-support/windows/WinDDK_Includes/POPPACK.H
		os-support/windows/WinDDK_Includes/PSHPACK1.H
		os-support/windows/WinDDK_Includes/usb.h
		os-support/windows/WinDDK_Includes/usb100.h
		os-support/windows/WinDDK_Includes/usb200.h
		os-support/windows/WinDDK_Includes/winusb.h
		os-support/windows/WinDDK_Includes/winusbio.h
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
	set(PLATFORM_SOURCE_FILES ${WINDOWS_TEST_SOURCE_FILES} ${PLATFORM_WINDOWS_HEADER_FILES} ${PLATFORM_WINDOWS_SOURCE_FILES_NATIVE} ${PLATFORM_SOURCE_FILES_STUDIO} ${PLATFORM_SOURCE_FILES_WINDDK} ${CSHARP_SAMPLE_FILES} ${CONSOLE_DEMO_SAMPLE_FILES})

	message("Building Windows")

elseif(APPLE)
	message("Building SeaBreeze for OS X, Darwin")
	set(CMAKE_OSX_ARCHITECTURES "x86_64")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -ggdb ")

	set(PLATFORM_SOURCE_FILES
			src/native/usb/osx/NativeUSBMacOSX.c
			)
	list(APPEND PLATFORM_SOURCE_FILES ${COMMON_SOURCE_CXX_POSIX_FILES_NATIVE})

	find_library(IOKIT_FRAMEWORK IOKit)
	find_library(COREFOUNDATION_FRAMEWORK CoreFoundation)
	set(LIBS_TO_LINK ${COREFOUNDATION_FRAMEWORK} ${IOKIT_FRAMEWORK})
	list(APPEND PLATFORM_SOURCE_FILES ${COMMON_SOURCE_CXX_POSIX_FILES_NATIVE})
elseif(UNIX)
# need to copy os-support/linux/FilesToInstall/10-oceanoptics.rules to the rules folder

	message("Building for Unix-like platforms")
	#add_compile_options(-std=c++0x)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -ggdb ${CMAKE_THREAD_LIBS_INIT}")

	set(PLATFORM_SOURCE_FILES
		src/native/usb/linux/NativeUSBLinux.c
		)
	list(APPEND PLATFORM_SOURCE_FILES ${COMMON_SOURCE_CXX_POSIX_FILES_NATIVE})

	set(LIBS_TO_LINK usb)
endif(WIN32)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wno-dynamic-exception-spec")
add_library(SeaBreeze SHARED ${COMMON_SOURCE_FILES} ${PLATFORM_SOURCE_FILES})
target_link_libraries(SeaBreeze PRIVATE ${LIBS_TO_LINK})
target_compile_definitions(SeaBreeze PRIVATE "-DBUILD_DLL")
target_include_directories(SeaBreeze PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_subdirectory("test")

message("Building sample code for all platforms.")

add_subdirectory("sample-code")

message("Building Ocean FX speed test for all platforms.")
add_executable(oceanfx_speed_test "oceanfx_speed_test/oceanfx_speed_test.c")
target_link_libraries(oceanfx_speed_test SeaBreeze)

set_target_properties("oceanfx_speed_test" PROPERTIES EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/oceanfx_speed_test/")

