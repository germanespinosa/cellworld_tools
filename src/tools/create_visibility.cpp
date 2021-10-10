#include <iostream>
#include <cell_world.h>
#include <cell_world_tools/parameters_builder.h>

using namespace cell_world;
using namespace std;

struct Parameters : Parameters_builder{
    World world;
    Parameters_definitions({
        Add_web_resource(world, ({"world"}));
    })
};

int main(int argc, char **argv) {
    Parameters p;
    p.load(argc, argv);
    if (p.world.connection_pattern.size()==4) {
        for (auto &cell: p.world.cells) cell.location = {(double)cell.coordinates.x, (double)cell.coordinates.y};
    } else {
        for (auto &cell: p.world.cells) cell.location = {(double)cell.coordinates.x * .5, (double)cell.coordinates.y * sqrt(.75)};
    }
    Graph visibility=Visibility::create_graph(p.world.create_cell_group(),Cell_descriptor(6,.5001,0));
    cout << visibility;
    return 0;
}
