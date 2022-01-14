add_executable(demo-averaging "demo-averaging.c" "util.h" "util.c")
target_link_libraries(demo-averaging SeaBreeze)

add_executable(demo-named-spectrometer "demo-named-spectrometer.c" "util.h" "util.c")
target_link_libraries(demo-named-spectrometer SeaBreeze)

add_executable(demo-pthreads "demo-pthreads" "util.h" "util.c")
target_link_libraries(demo-pthreads SeaBreeze ${CMAKE_THREAD_LIBS_INIT})

add_executable(demo-qepro-api "demo-qepro-api.c" "util.h" "util.c")
target_link_libraries(demo-qepro-api SeaBreeze)

add_executable(demo-raw-usb-seabreezeapi "demo-raw-usb-seabreezeapi.c"  "util.h" "util.c")
target_link_libraries(demo-raw-usb-seabreezeapi SeaBreeze)

add_executable(demo-raw-usb "demo-raw-usb.c" "util.h" "util.c")
target_link_libraries(demo-raw-usb SeaBreeze)

add_executable(demo-stability-scan "demo-stability-scan.c" "util.h" "util.c")
target_link_libraries(demo-stability-scan SeaBreeze)

add_executable(demo-streaming-xml "demo-streaming-xml.c" "util.h" "util.c")
target_link_libraries(demo-streaming-xml SeaBreeze)

add_executable(demo-strobe-sts "demo-strobe-sts.c" "util.h" "util.c")
target_link_libraries(demo-strobe-sts SeaBreeze)

add_executable(demo-strobe "demo-strobe.c" "util.h" "util.c")
target_link_libraries(demo-strobe SeaBreeze)

add_executable(demo-sts-api "demo-sts-api.c" "util.h" "util.c")
target_link_libraries(demo-sts-api SeaBreeze)

add_executable(demo-sts-eeprom "demo-sts-eeprom.c" "util.h" "util.c")
target_link_libraries(demo-sts-eeprom SeaBreeze)

add_executable(demo-timeout "demo-timeout.c" "util.h" "util.c")
target_link_libraries(demo-timeout SeaBreeze)

add_executable(demo-timing "demo-timing.c" "util.h" "util.c")
target_link_libraries(demo-timing SeaBreeze)

add_executable(demo-unformatted-spectrum "demo-unformatted-spectrum.c" "util.h" "util.c")
target_link_libraries(demo-unformatted-spectrum SeaBreeze)

add_executable(seabreeze-util "seabreeze-util.c" "util.h" "util.c")
target_link_libraries(seabreeze-util SeaBreeze)

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
