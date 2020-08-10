#include <cell_world_tools/screen_map.h>

using namespace std;

namespace cell_world{
    Screen_map::Screen_map(const Map &map) : map(map) , ms(){
        add_group(map.cells.free_cells(),ms.clear);
        add_group(map.cells.occluded_cells(),ms.occluded);
    }

    void Screen_map::add_group(const Cell_group &cg, Map_symbol m) {
        groups.push_back(cg);
        groups_symbols.push_back(m);
    }

    void Screen_map::add_special_cell(const Cell &c, Map_symbol m) {
        if (special_cells.add(c)) {
            special_cells_symbols.push_back(m);
        } else {
            special_cells_symbols[special_cells.find(c)] = m;
        }
    }

    std::ostream &operator<<(std::ostream &o, const Screen_map &sm) {
        for (int y=sm.map.coordinates[0].y; y<=sm.map.coordinates[1].y; y++){
            for (int x=sm.map.coordinates[0].x; x<=sm.map.coordinates[1].x; x++){
                Coordinates c{x,y};
                if (sm.map.find(c)==Not_found) {
                    o << '-';
                } else {
                    const Cell &cell = sm.map[c];
                    Map_symbol s;
                    for (unsigned int i=0;i<sm.groups.size();i++){
                        if (sm.groups[i].contains(cell)) s = sm.groups_symbols[i];
                    }
                    auto i = sm.special_cells.find(cell);
                    if (i != Not_found) {
                        s = sm.special_cells_symbols[i];
                    }
                    o << s;
                }
            }
            o << endl;
        }
        return o;
    }

    Screen_map::Screen_map(const Map &map, Map_symbols ms): map(map), ms(ms) { }

    void Screen_map::add_special_cell(const Coordinates &coord, Map_symbol m) {
        add_special_cell(map[coord],m);
    }

    void Screen_map::add_group(const Coordinates_list &l, Map_symbol m) {
        Cell_group cg;
        for (auto &c:l) cg.add(map[c]);
        add_group(cg,m);
    }
}