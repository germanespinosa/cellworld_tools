#include <cmath>
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

Location get_location(const Coordinates &coord){
    double offset_x = 1.0 / 42.0 * double(coord.x) + .5;
    double offset_y = 1.0 / 22.0 * double(coord.y) + .5;
    return {offset_x,offset_y};
}

int main(int argc, char **argv) {
    Parameters p;
    p.load(argc, argv);
    for (auto &c:p.world.cells)
        c.location = get_location(c.coordinates);
    cout << p.world;
    return 0;
}

