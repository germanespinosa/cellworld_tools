#include <iostream>
#include <cell_world.h>
#include <cell_world_tools.h>

using namespace cell_world;
using namespace std;

Map_symbols ms;

struct Parameters : Parameters_builder{
    World world;
    Parameters_definitions({
        Add_web_resource(world, ({"world"}));
    })
};

int main(int argc, char **argv) {
    Parameters p;
    p.load(argc, argv);
    cout << "World Loaded successfully" << endl;
    cout << "connection_pattern: " << p.world.connection_pattern << endl;
    cout << "cells: " << p.world.size() << endl;
    cout << "occlusions: " << p.world.create_cell_group().occluded_cells().size() << endl;
    Map map (p.world.create_cell_group());
    Screen_map sm(map);
    cout << sm;
    return 0;
}
