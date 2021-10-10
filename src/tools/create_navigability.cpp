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

//
//Graph create_graph(const Cell_group &cell_group) {
//    if (cell_group.empty()) return {};
//    Cell_group occlusions = cell_group.occluded_cells();
//    Cell_group free_cells = cell_group.free_cells(); // filters occluded
//    Graph vi(cell_group);
//    for (const Cell &source:free_cells) { //only not occluded
//        vi[source].add(source); //cell is visible to itself
//        for (const Cell &destination:free_cells) { //only not occluded
//            if( destination.id < source.id) continue;
//            bool blocked = false;
//            if (source!=destination) {
//                double dist = source.location.dist(destination.location); // distance between source & destination
//                for (const Cell &occlusion:occlusions) {
//                    if (occlusion.location.dist(source.location, destination.location) <=
//                        (occlusion.cell_type == Square ? 2 * .7072 : 2 * .5001) &&
//                        occlusion.location.dist(source.location) < dist &&
//                        occlusion.location.dist(destination.location) < dist) {
//                        blocked = true;
//                        break;
//                    }
//                }
//            }
//            if (!blocked) {
//                vi[source].add(destination);
//                vi[destination].add(source);
//            }
//        }
//    }
//    return vi;
//}

int main(int argc, char **argv) {
    Parameters p;
    p.load(argc, argv);
    if (p.world.connection_pattern.size()==4) {
        for (auto &cell: p.world.cells) cell.location = {(double)cell.coordinates.x, (double)cell.coordinates.y};
    } else {
        for (auto &cell: p.world.cells) cell.location = {(double)cell.coordinates.x * .5, (double)cell.coordinates.y * sqrt(.75)};
    }
//    Graph navigability= create_graph(p.world.create_cell_group());
//    cout << navigability;
    return 0;
}
