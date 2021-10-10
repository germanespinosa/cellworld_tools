#include <iostream>
#include <cell_world.h>
#include <cell_world_tools/parameters_builder.h>

using namespace cell_world;
using namespace std;

struct Parameters : Parameters_builder{
    World world;
    string path_type;
    Parameters_definitions({
        Add_web_resource(world, ({"world"}));
        Add_value(path_type);
    })
};

int main(int argc, char **argv) {
    Parameters p;
    p.load(argc, argv);
    Graph graph = p.world.create_graph();
    if (p.path_type == "euclidean") {
        cout << Paths::get_euclidean(graph);
    } else if (p.path_type == "manhattan"){
        cout << Paths::get_manhattan(graph);
    } else if (p.path_type == "astar") {
        cout << Paths::get_astar(graph);
    } else {
        cout << "wrong path type '" << p.path_type << "'" << endl;
    }
}