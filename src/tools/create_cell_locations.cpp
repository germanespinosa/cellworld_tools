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
    Location_list cell_locations;
    for (auto &cell:p.world.cells) {
        cell_locations.push_back(cell.location);
    }
    cout << cell_locations;
    return 0;
}
