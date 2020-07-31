cmake_minimum_required( VERSION 3.13 )
project( tools CXX )

set(CMAKE_CXX_STANDARD 17)

find_package( Cellworld CONFIG QUIET )

add_library(tools
        src/parameters_builder.cpp
        src/web_resources.cpp)

target_link_libraries( tools PUBLIC cellworld )

include_directories( include )

add_executable(cellworld_find_pois src/find_pois.cpp)
target_link_libraries( cellworld_find_pois PUBLIC tools )

add_executable(cellworld_show_cell_group src/show_cell_group.cpp)
target_link_libraries( cellworld_show_cell_group PUBLIC tools )

add_executable(cellworld_show_world src/show_world.cpp)
target_link_libraries( cellworld_show_world PUBLIC tools )

add_executable(cellworld_show_graph src/show_graph.cpp)
target_link_libraries( cellworld_show_graph PUBLIC tools )

add_executable(cellworld_create_paths src/create_paths.cpp)
target_link_libraries( cellworld_create_paths PUBLIC tools )

add_executable(cellworld_create_visibility src/create_visibility.cpp)
target_link_libraries( cellworld_create_visibility PUBLIC tools )

add_executable(cellworld_show_paths src/show_paths.cpp)
target_link_libraries( cellworld_show_paths PUBLIC tools )

add_executable(cellworld_map_symbols src/map_symbols.cpp)
target_link_libraries( cellworld_map_symbols PUBLIC tools )

add_custom_target(cellworld_default_map)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/map_symbols.json ${CMAKE_CURRENT_BINARY_DIR}/map_symbols.json COPYONLY)

###
### TESTS
###
find_package(CatchTests CONFIG QUIET)

include(GNUInstallDirs)

install(TARGETS cellworld_show_cell_group
                cellworld_show_graph
                cellworld_show_world
                cellworld_find_pois
                cellworld_create_paths
                cellworld_show_paths
                cellworld_create_visibility
        RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})

find_package( Cellworld CONFIG QUIET )