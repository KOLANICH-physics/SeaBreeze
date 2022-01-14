cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 98)
#set(CMAKE_BUILD_TYPE DEBUG)

project(SeaBreeze)
set("PROJECT_DESCRIPTION" "A git mirror and a fork of discontinued FOSS library for operating Ocean Optics spectrometers")
set("PROJECT_HOMEPAGE_URL" "https://github.com/KOLANICH-physics/SeaBreeze")
set(PROJECT_VERSION "3.0.11.1")

set(CPACK_PACKAGE_VENDOR "KOLANICH")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")

set(OUR_CMAKE_MODULES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${OUR_CMAKE_MODULES_DIR}" "${OUR_CMAKE_MODULES_DIR}/Boilerplate" "${OUR_CMAKE_MODULES_DIR}/DoxygenUtils" "${OUR_CMAKE_3PARTY_MODULES_DIR}")

include(Boilerplate)

find_package(Threads REQUIRED)

set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")

file(GLOB_RECURSE COMMON_SOURCE_HPP_FILES "${INCLUDE_DIR}/api/seabreezeapi/*.h" "${INCLUDE_DIR}/api/*.h" "${INCLUDE_DIR}/common/*.h" "${INCLUDE_DIR}/native/*.h" "${INCLUDE_DIR}/vendors/OceanOptics/*.h")

if(WIN32)
	#add_compile_options(-std=c++0x)
	set(WINDOWS_TEST_SOURCE_FILES
		test/VisualStudio2015/windows_api_test/stdafx.cpp
		test/VisualStudio2015/windows_api_test/stdafx.h
		test/VisualStudio2015/windows_api_test/targetver.h
		test/VisualStudio2015/windows_api_test/windows_api_test.cpp
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
endif()
if(UNIX)
# need to copy os-support/linux/FilesToInstall/10-oceanoptics.rules to the rules folder
endif()

add_subdirectory("src")
add_subdirectory("test")
add_subdirectory("sample-code")
add_subdirectory("oceanfx_speed_test")
