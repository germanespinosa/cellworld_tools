#include <iostream>
#include <cell_world.h>
#include <cell_world_tools.h>

using namespace cell_world;
using namespace std;

Map_symbols ms;

struct Parameters : Parameters_builder{
    World world;
    Graph_builder graph;
    Coordinates source;
    Parameters_definitions({
        Add_web_resource(world, ({"world"}));
        Add_web_resource(graph, ({"world","graph"}));
        Add_value(source);
    })
};

int main(int argc, char **argv) {
    Parameters p;
    p.load(argc, argv);
    cout << "World Loaded successfully" << endl;
    cout << "connection_pattern: " << p.world.connection_pattern << endl;
    cout << "cells: " << p.world.size() << endl;
    cout << "occlusions: " << p.world.create_cell_group().occluded_cells().size() << endl;
    Graph graph = p.world.create_graph(p.graph);
    Map map (p.world.create_cell_group());
    const Cell &source = map[p.source];
    cout << "source connections: " << graph[source].size() << endl;
    Screen_map sm (map);
    sm.add_group(graph[source],ms.highlight.front(Red));
    sm.add_special_cell(source, ms.goal.front(Blue));
    cout << sm;
    return 0;
}
