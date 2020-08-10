#include <iostream>
#include <cell_world.h>
#include <cell_world_tools.h>

using namespace cell_world;
using namespace std;

Map_symbols ms;

struct Parameters : Parameters_builder{
    World world;
    Cell_group_builder cell_group;
    Parameters_definitions({
       Add_web_resource(world, ({"world"}));
       Add_web_resource(cell_group, ({"world","cell_group"}));
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
    Cell_group cg = p.world.create_cell_group(p.cell_group);
    cout << "Cell_group Loaded successfully" << endl;
    cout << "cells: " << cg.size() << endl;
    Graph graph = p.world.create_graph();
    Map map (p.world.create_cell_group());
    Screen_map sm(map);
    sm.add_group(cg,ms.highlight.front(Red));
    cout << sm;
    return 0;
}
