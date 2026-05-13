cmake_minimum_required(VERSION 3.10)
project(LoadingScreenCLib VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Library
add_library(loading_screen src/loading_screen.c)
target_include_directories(loading_screen PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Example demo
add_executable(loading_demo examples/demo.c)
target_link_libraries(loading_demo PRIVATE loading_screen)

# Installation
install(TARGETS loading_screen
    EXPORT LoadingScreenCLibTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(FILES include/loading_screen.h DESTINATION include)

# Export for find_package
install(EXPORT LoadingScreenCLibTargets
    FILE LoadingScreenCLibTargets.cmake
    NAMESPACE LoadingScreenCLib::
    DESTINATION lib/cmake/LoadingScreenCLib
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/LoadingScreenCLibConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/LoadingScreenCLibConfig.cmake
    INSTALL_DESTINATION lib/cmake/LoadingScreenCLib
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/LoadingScreenCLibConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/LoadingScreenCLibConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/LoadingScreenCLibConfigVersion.cmake
    DESTINATION lib/cmake/LoadingScreenCLib
)
