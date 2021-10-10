#include <iostream>
#include <cell_world.h>
#include <cell_world_tools/parameters_builder.h>

using namespace cell_world;
using namespace std;
using namespace json_cpp;

struct Parameters : Parameters_builder{
    World world;
    Path_builder path_type;
    Parameters_definitions({
                               Add_web_resource(world, ({"world"}));
                               Add_web_resource_from_table(path_type, "paths", ({"world","path_type"}));
                           })
};

int main(int argc, char **argv) {
    Parameters p;
    p.load(argc, argv);
    Cell_group pois = p.world.create_cell_group(Json_create<Cell_group_builder>(Web_resource::from("cell_group").key(p.world.name).key("pois").get()));
    Paths paths = p.world.create_paths(p.path_type);
    Cell_group cells = p.world.create_cell_group();
    Map map = Map(cells);
    Graph pois_graph (cells);
    Cell_group free_cells = cells.free_cells();
    for (const Cell& cell:free_cells) {
        for (const Cell& poi: pois) {
            Cell current = cell;
            if (current != poi) {
                Cell_group trajectory;
                while ( !trajectory.contains(current) &&
                        (cell == current || !pois.contains(current))) {
                    trajectory.add(current);
                    Move move = paths.get_move(current, poi);
                    current = map[current.coordinates + move];
                }
            }
            if (current == poi) {
                pois_graph[cell].add(poi);
            }
        }
    }
    cout << pois_graph;
}
