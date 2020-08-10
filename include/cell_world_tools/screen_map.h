#pragma once
#include <cell_world_tools/map_symbols.h>

namespace cell_world {
    struct Screen_map {
        explicit Screen_map(const cell_world::Map &);
        Screen_map(const cell_world::Map &, Map_symbols ms);
        void add_group( const Cell_group &, Map_symbol);
        void add_group( const Coordinates_list &, Map_symbol);
        void add_special_cell( const Cell &, Map_symbol);
        void add_special_cell( const Coordinates &, Map_symbol);
        std::vector<cell_world::Cell_group> groups;
        std::vector<Map_symbol> groups_symbols;
        cell_world::Cell_group special_cells;
        std::vector<Map_symbol> special_cells_symbols;
        const cell_world::Map &map;
        Map_symbols ms;
        friend std::ostream & operator << (std::ostream & , const Screen_map &);
    };
}