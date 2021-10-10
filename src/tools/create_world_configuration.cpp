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
    World_configuration world_configuration;
    for (auto &cell:p.world.cells) {
        world_configuration.cell_coordinates.push_back(cell.coordinates);
    }
    world_configuration.connection_pattern = p.world.connection_pattern;
    world_configuration.cell_descriptor = p.world.cell_descriptor;
    cout << world_configuration;
    return 0;
}
