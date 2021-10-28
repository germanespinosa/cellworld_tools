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
    cout << p.world.create_cell_group().occluded_cells();
    return 0;
}
