#include <iostream>
#include <cell_world.h>
#include <cell_world_tools.h>

using namespace cell_world;
using namespace std;

Map_symbols ms;

struct Parameters : Parameters_builder{
    World world;
    Path_builder path_type;
    Coordinates destination;
    Parameters_definitions({
        Add_web_resource(world, ({"world"}));
        Add_web_resource_from_table(path_type, "paths", ({"world","path_type"}));
        Add_value(destination);
    })
};

int main(int argc, char **argv) {
    Parameters p;
    p.load(argc, argv);
    cout << "World Loaded successfully" << endl;
    cout << "name: " << p.world.name << endl;
    cout << "connection_pattern: " << p.world.connection_pattern << endl;
    cout << "cells: " << p.world.size() << endl;
    cout << "occlusions: " << p.world.create_cell_group().occluded_cells().size() << endl;
    Paths paths = p.world.create_paths(p.path_type);
    cout << "Paths loaded successfully" << endl;
    cout << "size: " << paths.moves.size() << endl;
    Graph graph = p.world.create_graph();
    Map map (p.world.create_cell_group());
    Screen_map sm(map);
    const Cell &destination = map[p.destination];
    for (const Cell &cell:map.cells.free_cells()) {
        sm.add_special_cell(cell, ms.get_direction(paths.get_move(cell,destination)));
    }
    sm.add_special_cell(destination,ms.goal.front(Red));
    cout << sm;
    return 0;
}
