#include<catch.h>
#include <cell_world.h>
#include <cell_world_tools.h>

using namespace std;
using namespace json_cpp;
using namespace cell_world;

TEST_CASE("key tests"){
    auto wr = Web_resource::from("cell_group");
    CHECK(wr.url() == "https://raw.githubusercontent.com/germanespinosa/cellworld_data/master/cell_group/");
    wr.key("world_0_0");
    CHECK(wr.url() == "https://raw.githubusercontent.com/germanespinosa/cellworld_data/master/cell_group/world_0_0");
    wr.key("pois");
    CHECK(wr.url() == "https://raw.githubusercontent"
                      ".com/germanespinosa/cellworld_data/master/cell_group/world_0_0.pois");
}

TEST_CASE("get_world"){
    CHECK_NOTHROW(Json_create<World>(Web_resource::from("world").key("world_0_0").get()));
}

TEST_CASE("get_cell_group"){
    CHECK_NOTHROW(Json_create<Cell_group>(Web_resource::from("world").key("world_0_0").key("pois").get()));
}

TEST_CASE("path_builder"){
    CHECK_NOTHROW(Json_create<Path_builder>(Web_resource::from("paths").key("world_0_0").key("astar").get()));
}

TEST_CASE("get_graph"){
    CHECK_NOTHROW(Json_create<Graph_builder>(Web_resource::from("graph").key("world_0_0").key("pois").key("astar").get()));
}

TEST_CASE("CACHE FOLDER"){
    CHECK(!Web_resource::cache_folder().empty());
}


TEST_CASE("create shortest paths"){
    Json_vector<Json_vector<Json_vector<unsigned int>>> shortest_paths;
    for (int s = 0; s < 20; s++){
        Json_vector<Json_vector<unsigned int>> e_sp;
        for (int e = 0; e < 10; e ++){
            Json_vector<unsigned int> sp;
            stringstream ss;
            ss << "world_" << s << "_" << e;
            string world_name = ss.str();
            auto world = Json_create<World>(Web_resource::from("world").key(world_name).get());
            auto path_builder = Json_create<Path_builder>(Web_resource::from("paths").key(world_name).key("astar").get());
            auto paths = world.create_paths(path_builder);
            auto cells = world.create_cell_group();
            Map map (cells);
            auto moves = paths.get_moves(map[{0,-7}],map[{0,7}]);
            for (auto m:moves) {
                if ( m == Move{0,1} ) sp.push_back(1);
                else if ( m == Move{1,0} ) sp.push_back(2);
                else if ( m == Move{0,-1} ) sp.push_back(3);
                else if ( m == Move{-1,0} ) sp.push_back(4);
            }
            e_sp.push_back(sp);
        }
        shortest_paths.push_back(e_sp);
    }
    cout << shortest_paths << endl;
    shortest_paths.save("shortest_paths.json");
}