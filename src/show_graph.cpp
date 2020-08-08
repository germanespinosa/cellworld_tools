#include <iostream>
#include <cell_world.h>
#include <cell_world_tools/map_symbols.h>
#include <cell_world_tools/parameters_builder.h>

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
    cout << "name: " << p.world.name << endl;
    cout << "connection_pattern: " << p.world.connection_pattern << endl;
    cout << "cells: " << p.world.size() << endl;
    cout << "occlusions: " << p.world.create_cell_group().occluded_cells().size() << endl;
    Graph graph = p.world.create_graph(p.graph);
    Map map (p.world.create_cell_group());
    const Cell &source = map[p.source];
    cout << "source connections: " << graph[source].size() << endl;
    for (int y=map.coordinates[0].y; y<=map.coordinates[1].y; y++){
        for (int x=map.coordinates[0].x; x<=map.coordinates[1].x; x++){
            Coordinates c{x,y};
            if (map.find(c)==Not_found) {
                cout << '-';
            } else {
                const Cell &cell = map[c];
                if (cell.occluded) {
                    cout << ms.occluded ;
                } else {
                    if (cell.coordinates == p.source){
                        cout << ms.goal;
                    } else {
                        if (graph[source].contains(cell)){
                            cout << ms.highlight;
                        } else {
                            cout << ms.clear;
                        }
                    }
                }
            }
        }
        cout << endl;
    }
    return 0;
}
