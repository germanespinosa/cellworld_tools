#pragma once
#include <json_cpp.h>
namespace cell_world {
    struct Map_symbols : json_cpp::Json_object {
        std::string clear = "\033[7m\u2000\033[0m";
        std::string occluded = "\033[7m\u2588\033[0m";
        std::string goal = "\033[7m\u25CE\033[0m";
        std::string N = "\033[7m\u25B2\033[0m";
        std::string W = "\033[7m\u25C0\033[0m";
        std::string S = "\033[7m\u25BC\033[0m";
        std::string E = "\033[7m\u25B6\033[0m";
        std::string NE = "\033[7m\u25E5\033[0m";
        std::string NW = "\033[7m\u25E4\033[0m";
        std::string SE = "\033[7m\u25E2\033[0m";
        std::string SW = "\033[7m\u25E3\033[0m";
        std::string highlight = "\033[7m\u2592\033[0m";

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
    };
}