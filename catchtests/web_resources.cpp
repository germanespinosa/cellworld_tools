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

TEST_CASE("CACHE FOLDER"){
    CHECK(!Web_resource::cache_folder().empty());
}
