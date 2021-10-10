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

int main(int argc, char **argv) {
    Parameters p;
    p.load(argc, argv);
    Location start_vertex{2149,790};
    Location end_vertex{427,1775};
    double distance = end_vertex.dist(start_vertex);
    double intercell_distance = distance / (21.0 + 1.0/3.0);
    double col_distance = intercell_distance / 2;
    double row_distance = sqrt( intercell_distance * intercell_distance - intercell_distance * intercell_distance / 4 );
    double padding = intercell_distance / 6;
    Location v = end_vertex - start_vertex;
    double theta = atan2(v.y, v.x);
    Location xChange = Location{cos(theta),sin(theta)} * col_distance;
    double thetay = theta - M_PI / 2.0;
    Location yChange = Location{cos(thetay),sin(thetay)} * row_distance;
    Location origin = (end_vertex + start_vertex) * .5;

    for (auto &c:p.world.cells){
        double x = c.coordinates.x;
        double y = c.coordinates.y;
        c.location = origin + xChange * (double)x + yChange * (double)y;
    }
    cout << p.world;
    return 0;
}

