#pragma once
#include <cell_world.h>

namespace cell_world {
    struct Random_agent : Stateless_agent {

        Random_agent(const Cell &start_cell, const Connection_pattern &connection_pattern):
            connections(connection_pattern){
            cells.add(start_cell);
        }

        Random_agent(const Cell_group &cells, const Connection_pattern &connection_pattern):
            cells(cells),
            connections(connection_pattern){
        }

        const Cell &start_episode() override {
            return cells.random_cell();
        };

        Move get_move(const Model_public_state &state) override {
            return connections.random_move();
        };

        Agent_status_code update_state(const Model_public_state &state) override {
            return Running;
        };

        Cell_group cells;
        const Connection_pattern &connections;
    };
}