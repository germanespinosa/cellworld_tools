#include <iostream>
#include <cell_world.h>
#include <cell_world_tools/map_symbols.h>
#include <cell_world_tools/parameters_builder.h>

using namespace cell_world;
using namespace std;
using namespace cell_world_tools;

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

string get_arrow(Move c){
    if (c.x > 0){
        if (c.y == 0) return ms.E;
        if (c.y < 0) return ms.NE;
        if (c.y > 0) return ms.SE;
    }
    if (c.x < 0) {
        if (c.y == 0) return ms.W;
        if (c.y < 0) return ms.NW;
        if (c.y > 0) return ms.SW;
    }
    if (c.y < 0) return ms.N;
    if (c.y > 0) return ms.S;

    return ms.highlight;
}

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
    const Cell &destination = map[p.destination];
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
                    cout << get_arrow(paths.get_move(cell,destination));
                }
            }
        }
        cout << endl;
    }
    return 0;
}
