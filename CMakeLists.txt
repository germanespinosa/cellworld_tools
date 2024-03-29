cmake_minimum_required( VERSION 3.10 )

set(CMAKE_CXX_STANDARD 20)

project( cellworld_tools
        VERSION 2019.1.0
        DESCRIPTION "Cellworld utilities"
        LANGUAGES CXX)

find_package(Cellworld REQUIRED)

###
### MAIN LIBRARY SETUP
###

set(cellworld_tools_files
        src/parameters_builder.cpp
        src/web_resources.cpp
        src/map_symbols.cpp
        )

add_library(cellworld_tools ${cellworld_tools_files})

set_target_properties(cellworld_tools
        PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED On
        CXX_EXTENSIONS Off
        VERSION ${PROJECT_VERSION})

if(MSVC)
    target_compile_options(cellworld_tools PRIVATE /W4)
else(MSVC)
    target_compile_options(cellworld_tools PRIVATE -Wall -Wextra -pedantic)
endif(MSVC)

target_include_directories(cellworld_tools
        SYSTEM INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

target_include_directories(cellworld_tools
        PRIVATE
        include )

target_link_libraries( cellworld_tools
        PUBLIC
        ${CELLWORLD_LIBRARIES})


###
### UTILITIES SETUP
###

include_directories( include )

add_executable(cellworld_find_pois src/tools/find_pois.cpp)
target_link_libraries( cellworld_find_pois PUBLIC cellworld_tools )

add_executable(cellworld_create_paths src/tools/create_paths.cpp)
target_link_libraries( cellworld_create_paths PUBLIC cellworld_tools )

add_executable(cellworld_create_predator_locations src/tools/create_predator_locations.cpp)
target_link_libraries( cellworld_create_predator_locations PUBLIC cellworld_tools )

add_executable(cellworld_create_poi_graph src/tools/create_poi_graph.cpp)
target_link_libraries( cellworld_create_poi_graph PUBLIC cellworld_tools )

add_executable(cellworld_create_visibility src/tools/create_visibility.cpp)
target_link_libraries( cellworld_create_visibility PUBLIC cellworld_tools )

add_executable(cellworld_create_occlusions src/tools/create_occlusions.cpp)
target_link_libraries( cellworld_create_occlusions PUBLIC cellworld_tools )

###
### TESTS
###
find_package(CatchTests CONFIG QUIET)

###
### LIBRARY INSTALLATION
###

#if (CMAKE_BUILD_TYPE MATCHES Release)

    include(GNUInstallDirs)

    install(TARGETS cellworld_tools EXPORT Cellworld_toolsConfig
            ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
            LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
            RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})

    install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

    install(EXPORT Cellworld_toolsConfig
            DESTINATION ${CMAKE_INSTALL_DATADIR}/cmake/Cellworld_tools
            EXPORT_LINK_INTERFACE_LIBRARIES)

    export(TARGETS cellworld_tools FILE Cellworld_toolsConfig.cmake)
    install(CODE "FILE(APPEND ${CMAKE_INSTALL_FULL_DATADIR}/cmake/Cellworld_tools/Cellworld_toolsConfig.cmake \"find_package(Cellworld REQUIRED)\n\") ")
    install(CODE "FILE(APPEND ${CMAKE_INSTALL_FULL_DATADIR}/cmake/Cellworld_tools/Cellworld_toolsConfig.cmake \"set(CELLWORLD_TOOLS_LIBRARIES cellworld_tools ${CELLWORLD_LIBRARIES})\n\") ")


    ###
    ### SCRIPT TOOLS INSTALLATION
    ###

    install(DIRECTORY scripts/tools/
            USE_SOURCE_PERMISSIONS
            DESTINATION ${CMAKE_INSTALL_BINDIR})

    ###
    ### UTILITIES INSTALLATION
    ###

    include(GNUInstallDirs)

    install(TARGETS cellworld_find_pois
                    cellworld_create_paths
                    cellworld_create_visibility
                    cellworld_create_poi_graph
                    cellworld_create_predator_locations
                    cellworld_create_occlusions
            RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})

#endif()