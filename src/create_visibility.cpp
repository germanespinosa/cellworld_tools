#include <iostream>
#include <cell_world.h>
#include <parameters_builder.h>

using namespace cell_world;
using namespace std;

struct Parameters : Parameters_builder{
    World world;
    Parameters_definitions({
        Add_web_resource(world, "worlds", ({"world"}));
    })
};

int main(int argc, char **argv) {
    Parameters p;
    p.load(argc, argv);
    Graph visibility=Visibility::create_graph(p.world.create_cell_group());
    cout << visibility;
    return 0;
}
