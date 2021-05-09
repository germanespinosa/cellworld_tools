#include <iostream>
#include <cell_world.h>
#include <cell_world_tools/parameters_builder.h>

using namespace cell_world;
using namespace std;
using namespace json_cpp;

struct Parameters : Parameters_builder{
    string world_name;
    float target_entropy;
    unsigned int seed;
    Parameters_definitions({
                               Add_value(world_name);
                               Add_value(target_entropy);
                               Add_value(seed);
                           })
};


int get_occlusion_count(double target_entropy, int count){
    if (target_entropy == 1) return count/2 ;
    vector<int> occlusion_vector (count,0);
    for (int i = 0; i <= count/2; i++){
        occlusion_vector[i] = 1;
        float e = entropy(histogram(occlusion_vector));
        if (target_entropy <= e) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char **argv) {
    Parameters p;
    p.load(argc, argv);
    srand(p.seed);
    World world;
    world.name = p.world_name;
    world.connection_pattern.push_back(Move(-2,0));
    world.connection_pattern.push_back(Move(2,0));
    world.connection_pattern.push_back(Move(-1,-1));
    world.connection_pattern.push_back(Move(1,1));
    world.connection_pattern.push_back(Move(-1,1));
    world.connection_pattern.push_back(Move(1,-1));

    for (int x = -20; x <= 20; x++) {
        for (int y = -10; y <= 10; y++) {
            if (abs(x) + abs(y) <= 20) {
                if ((abs(x) + abs(y)) % 2 == 0) {
                    Cell new_cell;
                    new_cell.cell_type = Circle;
                    new_cell.coordinates = Coordinates(x, y);
                    new_cell.location = Location(x * 110.0, y * 110.0);
                    new_cell.occluded = false;
                    world.add(new_cell);
                }
            }
        }
    }
    int occlusion_count = get_occlusion_count(p.target_entropy, world.size());
    Cell_group cell_group = world.create_cell_group();
    bool correct = false;
    while (!correct) {
        for (int i = 0; i < occlusion_count; i++) {
            while (true) {
                auto &cell = cell_group.random_cell();
                if (!cell.occluded && cell.coordinates != Coordinates(-10, -10) && cell.coordinates != Coordinates(10, 10)) {
                    world[cell.id].occluded = true;
                    break;
                }
            }
        }
        Map map(cell_group);
        auto graph = world.create_graph();
        if (graph.get_shortest_path(map[Coordinates(-20, 0)], map[Coordinates(20, 0)]).empty()) {
            for (auto &cell:world.cells) cell.occluded = false;
            continue;
        }
        correct = true;
        for (auto &cell:cell_group.free_cells()) {
            if (graph.get_shortest_path(cell, map[Coordinates(20, 0)]).empty()){
                world[cell.get().id].occluded = true;
            }
        }
    }
    cout << world;
}