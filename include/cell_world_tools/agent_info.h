#pragma once

#include <cell_world.h>

namespace cell_world {
    struct Agent_info : json_cpp::Json_object {
        Json_object_members (
        Add_member(coordinates);
        Add_member(location);
        Add_member(theta);
        Add_member(agent_name);
        );
        cell_world::Coordinates coordinates;
        cell_world::Location location;
        double theta;
        std::string agent_name;
    };
}

