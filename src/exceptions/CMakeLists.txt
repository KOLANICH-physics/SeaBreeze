buildAndPackageLib("SeaBreezeExceptions"
	COMPONENT "SeaBreezeExceptions"
	DESCRIPTION "The shared library having impls of exceptions needed by other libs"
	PRIVATE_INCLUDES ${INCLUDE_DIR}
	PRIVATE_LIBS ${LIBS_TO_LINK}
	USE_INCLUDES_FROM SeaBreeze
)
target_compile_definitions(SeaBreezeExceptions PRIVATE "-DBUILD_DLL")
