#include <iostream>
#include <cell_world.h>
#include <cell_world_tools/parameters_builder.h>

using namespace cell_world;
using namespace std;

struct Parameters : Parameters_builder{
    World world;
    Cell_descriptor cell_descriptor;
    Parameters_definitions({
                               Add_web_resource(world, ({"world"}));
                               Add_web_resource(cell_descriptor,({"cell_descriptor"}));
                 })
};

int main(int argc, char **argv) {
    Parameters p;
    p.load(argc, argv);
    p.world.cell_descriptor = p.cell_descriptor;
    cout << p.world;
}