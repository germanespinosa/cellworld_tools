#include <iostream>
#include <cell_world.h>
#include <cell_world_tools/parameters_builder.h>

using namespace cell_world;
using namespace std;

struct Parameters : Parameters_builder{
    World_configuration world_configuration;
    Cell_group occlusions;
    Coordinates_list extra_pois;
    Parameters_definitions({
       Add_web_resource(world_configuration, ({"world_configuration"}));
       Add_web_resource(occlusions, ({"cell_group","world_configuration","occlusions"}));
       Add_value(extra_pois);
   })
};

json_cpp::Json_vector<Connection_pattern> get_directions (Connection_pattern cp){
    json_cpp::Json_vector<Connection_pattern> directions;
    for (Move m: cp){
        bool found = false;
        for (Connection_pattern &direction: directions) {
            for (Move dm : direction) {
                if (dm == m) found = true;
            }
        }
        if (!found) {
            Connection_pattern direction;
            direction.push_back(m);
            direction.push_back(-m);
            directions.push_back(direction);
        }
    }
    return directions;
}

int main(int argc, char **argv) {
    Parameters p;
    p.load(argc, argv);
    World world (p.world_configuration);
    auto directions = get_directions(world.connection_pattern);
    Graph graph = world.create_graph();
    Cell_group group = world.create_cell_group();
    Map map(group);
    Cell_group extra_pois;
    for (auto c : p.extra_pois) extra_pois.add(map[c]);
    Cell_group pois;
    vector<double> connectivity (group.size(),0);
    for (const Cell &cell : world.cells) if (! cell.occluded) connectivity[cell.id] = graph[cell].size();
    for (const Cell &cell : world.cells) {
        if (cell.occluded) continue;
        if (extra_pois.contains(cell)) {
            pois.add(cell);
            continue;
        }
        auto c = cell.coordinates;
        double cell_connectivity = connectivity[cell.id];
        bool change_all_directions = true;
        for (auto p : directions){
            bool change_current_direction = false;
            for (auto cc: p.get_candidates(c)) {
                if (map.find(cc) == Not_found ) {
                    change_current_direction = true;
                    break;
                }
                auto &connected_cell = map[cc];
                if (connected_cell.occluded || connectivity[connected_cell.id]!=cell_connectivity) {
                    change_current_direction = true;
                    break;
                }
            }
            change_all_directions = change_all_directions && change_current_direction;
        }
        if (change_all_directions) pois.add(cell);
    }
    cout << pois;
    return 0;
}
