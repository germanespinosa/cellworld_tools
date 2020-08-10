#pragma once
#include <cell_world.h>
#include <json_cpp.h>


namespace cell_world {

    enum Map_symbol_color{
        Black = 30,
        Red,
        Green,
        Yellow,
        Blue,
        Magenta,
        Cyan,
        White,
    };

    struct Map_symbol : json_cpp::Json_object {
        Map_symbol() = default;
        explicit Map_symbol (int);
        Map_symbol (int, Map_symbol_color);
        Map_symbol (int, Map_symbol_color, Map_symbol_color);
        unsigned int symbol = 0;
        unsigned int fg = 0;
        unsigned int bg = 0;
        friend std::ostream & operator << (std::ostream & , const Map_symbol &);
        Map_symbol front(Map_symbol_color);
        Map_symbol back(Map_symbol_color);
    };

    struct Map_symbols : json_cpp::Json_object {
        Map_symbol clear{9608};
        Map_symbol occluded{9617};
        Map_symbol goal{9678};
        Map_symbol N{9650};
        Map_symbol W{9664};
        Map_symbol S{9660};
        Map_symbol E{9658};
        Map_symbol NE{9701};
        Map_symbol NW{9700};
        Map_symbol SE{9698};
        Map_symbol SW{9699};
        Map_symbol highlight{9618};

        Json_object_members({
            Add_member(clear);
            Add_member(occluded);
            Add_member(N);
            Add_member(W);
            Add_member(S);
            Add_member(E);
            Add_member(NE);
            Add_member(NW);
            Add_member(SE);
            Add_member(SW);
            Add_member(highlight);
            Add_member(goal);
        })

        Map_symbol get_direction(const cell_world::Move &) const;
    };
}