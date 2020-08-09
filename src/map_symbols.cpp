#include <json_cpp.h>
#include <cell_world_tools/map_symbols.h>


using namespace std;
using namespace cell_world;

std::string Map_symbols::get_direction(const Move &c) {
    if (c.x > 0){
        if (c.y == 0) return E;
        if (c.y < 0) return NE;
        if (c.y > 0) return SE;
    }
    if (c.x < 0) {
        if (c.y == 0) return W;
        if (c.y < 0) return NW;
        if (c.y > 0) return SW;
    }
    if (c.y < 0) return N;
    if (c.y > 0) return S;

    return highlight;
}
