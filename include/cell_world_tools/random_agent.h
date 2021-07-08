#pragma once
#include <cell_world.h>

namespace cell_world {
    struct Random_agent : Stateless_agent {

        Random_agent(const Cell &start_cell) : start_cell(start_cell) {
            connections.load("{{\"x\"=0,\"y\"=-1},{\"x\"=0,\"y\"=1},{\"x\"=-1,\"y\"=0},{\"x\"=1,\"y\"=0}}");
        }

        const Cell &start_episode() override {
            return start_cell;
        };

        Move get_move(const Model_public_state &state) override {
            return connections.random_move();
        };

        Agent_status_code update_state(const Model_public_state &state) override {
            return Running;
        };

        Connection_pattern connections;
        const Cell &start_cell;
    };
}