#include <iostream>
#include <cell_world.h>
#include <cell_world_tools/parameters_builder.h>

using namespace cell_world;
using namespace std;
using namespace json_cpp;

struct Parameters : Parameters_builder{
    World world;
    unsigned int count;
    cell_world::Coordinates origin;
    unsigned int distance;
    unsigned int seed;
    Parameters_definitions({
                               Add_web_resource(world, ({"world"}));
                               Add_value(count);
                               Add_value(origin);
                               Add_value(distance);
                               Add_value(seed);
                           })
};

int main(int argc, char **argv) {
    Parameters p;
    p.load(argc, argv);
    srand(p.seed);
    Cell_group world_cells = p.world.create_cell_group().free_cells();
    Cell_group predator_locations;
    Coordinates_list predator_locations_coordinates;
    while (predator_locations.size()<p.count){
        auto &cell = world_cells.random_cell();
        if (cell.coordinates.manhattan(p.origin) >= p.distance) {
            if (predator_locations.add(cell)){
                predator_locations_coordinates.push_back(cell.coordinates);
            }
        }
    }
    cout << predator_locations_coordinates;
}
