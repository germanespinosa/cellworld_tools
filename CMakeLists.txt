cmake_minimum_required( VERSION 3.13 )

set(CMAKE_CXX_STANDARD 17)

project( cellworld_tools
        VERSION 2019.1.0
        DESCRIPTION "Cellworld utilities"
        LANGUAGES CXX)

find_package(Cellworld CONFIG QUIET)

###
### MAIN LIBRARY SETUP
###

set(cellworld_tools_files
        src/parameters_builder.cpp
        src/web_resources.cpp)

add_library(cellworld_tools ${cellworld_tools_files})

set_target_properties(cellworld_tools
        PROPERTIES
        CXX_STANDARD 17
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

add_executable(cellworld_find_pois src/find_pois.cpp)
target_link_libraries( cellworld_find_pois PUBLIC cellworld_tools )

add_executable(cellworld_show_cell_group src/show_cell_group.cpp)
target_link_libraries( cellworld_show_cell_group PUBLIC cellworld_tools )

add_executable(cellworld_show_world src/show_world.cpp)
target_link_libraries( cellworld_show_world PUBLIC cellworld_tools )

add_executable(cellworld_show_graph src/show_graph.cpp)
target_link_libraries( cellworld_show_graph PUBLIC cellworld_tools )

add_executable(cellworld_create_paths src/create_paths.cpp)
target_link_libraries( cellworld_create_paths PUBLIC cellworld_tools )

add_executable(cellworld_create_poi_graph src/create_poi_graph.cpp)
target_link_libraries( cellworld_create_poi_graph PUBLIC cellworld_tools )

add_executable(cellworld_create_visibility src/create_visibility.cpp)
target_link_libraries( cellworld_create_visibility PUBLIC cellworld_tools )

add_executable(cellworld_show_paths src/show_paths.cpp)
target_link_libraries( cellworld_show_paths PUBLIC cellworld_tools )

add_executable(cellworld_map_symbols src/map_symbols.cpp)
target_link_libraries( cellworld_map_symbols PUBLIC cellworld_tools )

###
### TESTS
###
find_package(CatchTests CONFIG QUIET)

###
### LIBRARY INSTALLATION
###

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
### UTILITIES INSTALLATION
###

include(GNUInstallDirs)

install(TARGETS cellworld_show_cell_group
                cellworld_show_graph
                cellworld_show_world
                cellworld_find_pois
                cellworld_create_paths
                cellworld_show_paths
                cellworld_create_visibility
                cellworld_create_poi_graph
        RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})

find_package( Cellworld CONFIG QUIET )
