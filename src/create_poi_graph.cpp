#include <iostream>
#include <cell_world.h>
#include <cell_world_tools/parameters_builder.h>

using namespace cell_world;
using namespace std;
using namespace cell_world_tools;
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
    Cell_group pois = p.world.create_cell_group(Json_create<Cell_group_builder>(Web_resource::from("cell_group").key(p.world
            .name).key("pois").get()));
    Paths paths = p.world.create_paths(p.path_type);
    Cell_group free_cells = p.world.create_cell_group().free_cells();
    Map map = Map(free_cells);
    Graph pois_graph (free_cells);
    for (auto &cell:free_cells) {
        for (auto &poi: pois) {
            Cell current = cell;
            Cell_group trajectory;
            while(!pois.contains(current) && !trajectory.contains(current)) {
                trajectory.add(current);
                current = map[current.coordinates + paths.get_move(current,poi)];
            }
            if (current == poi) {
                pois_graph[cell].add(poi);
            }
        }
    }
    cout << pois_graph;
}
