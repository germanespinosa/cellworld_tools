#pragma once

#include <json_cpp.h>
#include <cell_world.h>

namespace cell_world::vr {
    struct Episode_data_point : json_cpp::Json_object {
        Json_object_members(
                Add_member(time_stamp);
                Add_member(agent_name);
                Add_member(frame);
                Add_member(coordinates);
                Add_member(location);
                );
        double time_stamp;
        std::string agent_name;
        unsigned int frame;
        Coordinates coordinates;
        Location location;
    };
    struct Episode : json_cpp::Json_object {
        Json_object_members(
                Add_member(start_time);
                Add_member(time_stamp);
                Add_member(end_time);
                Add_member(trajectories);
                );
        json_cpp::Json_date start_time;
        double time_stamp;
        json_cpp::Json_date end_time;
        json_cpp::Json_vector<Episode_data_point> trajectories;
    };
    struct Experiment : json_cpp::Json_object {
        Json_object_members(
                Add_member(name);
                Add_member(duration);
                Add_member(start_time);
                Add_member(episodes);
                );
        std::string name;
        unsigned int duration;
        std::string start_time;
        json_cpp::Json_vector<Episode> episodes;
    };
 }