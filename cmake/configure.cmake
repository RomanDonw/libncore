set(CONFIG_INSTALL_DIR ${CMAKE_INSTALL_LIBDIR}/cmake/libncore)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/libncoreConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/libncoreConfig.cmake"
    INSTALL_DESTINATION ${CONFIG_INSTALL_DIR}
)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/libncoreConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY ${VERSION_CHECK_METHOD}
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/libncoreConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/libncoreConfigVersion.cmake"
    DESTINATION ${CONFIG_INSTALL_DIR}
)