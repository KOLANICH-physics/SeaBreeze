add_library(demos-util "util.h" "util.c")

add_executable(demo-averaging "demo-averaging.c")
target_link_libraries(demo-averaging SeaBreeze demos-util)

add_executable(demo-named-spectrometer "demo-named-spectrometer.c")
target_link_libraries(demo-named-spectrometer SeaBreeze demos-util)

add_executable(demo-pthreads "demo-pthreads.c")
target_link_libraries(demo-pthreads SeaBreeze demos-util ${CMAKE_THREAD_LIBS_INIT})

add_executable(demo-qepro-api "demo-qepro-api.c")
target_link_libraries(demo-qepro-api SeaBreeze demos-util)

add_executable(demo-raw-usb-seabreezeapi "demo-raw-usb-seabreezeapi.c")
target_link_libraries(demo-raw-usb-seabreezeapi SeaBreeze demos-util)

add_executable(demo-raw-usb "demo-raw-usb.c")
target_link_libraries(demo-raw-usb SeaBreeze demos-util)

add_executable(demo-stability-scan "demo-stability-scan.c")
target_link_libraries(demo-stability-scan SeaBreeze demos-util)

add_executable(demo-streaming-xml "demo-streaming-xml.c")
target_link_libraries(demo-streaming-xml SeaBreeze demos-util)

add_executable(demo-strobe-sts "demo-strobe-sts.c")
target_link_libraries(demo-strobe-sts SeaBreeze demos-util)

add_executable(demo-strobe "demo-strobe.c")
target_link_libraries(demo-strobe SeaBreeze demos-util)

add_executable(demo-sts-api "demo-sts-api.c")
target_link_libraries(demo-sts-api SeaBreeze demos-util)

add_executable(demo-sts-eeprom "demo-sts-eeprom.c")
target_link_libraries(demo-sts-eeprom SeaBreeze demos-util)

add_executable(demo-timeout "demo-timeout.c")
target_link_libraries(demo-timeout SeaBreeze demos-util)

add_executable(demo-timing "demo-timing.c")
target_link_libraries(demo-timing SeaBreeze demos-util)

add_executable(demo-unformatted-spectrum "demo-unformatted-spectrum.c")
target_link_libraries(demo-unformatted-spectrum SeaBreeze demos-util)

add_executable(seabreeze-util "seabreeze-util.c")
target_link_libraries(seabreeze-util SeaBreeze demos-util)

set(SAMPLE_CODE_C_TARGETS
				"demo-averaging"
				"demo-named-spectrometer"
				"demo-pthreads"
				"demo-qepro-api"
				"demo-raw-usb-seabreezeapi"
				"demo-raw-usb"
				"demo-stability-scan"
				"demo-streaming-xml"
				"demo-strobe-sts"
				"demo-strobe"
				"demo-sts-api"
				"demo-sts-eeprom"
				"demo-timeout"
				"demo-timing"
				"demo-unformatted-spectrum"
				"seabreeze-util"
				)

set_target_properties(${SAMPLE_CODE_C_TARGETS} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
