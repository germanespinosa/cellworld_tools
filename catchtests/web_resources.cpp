#include<catch.h>
#include <web_resources.h>
#include <cell_world.h>

using namespace std;
using namespace cell_world;
using namespace json_cpp;

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
//    World w;
//    auto wr = Web_resource::from("world");
//
//    wr.key("world_0_0").get() >> w;
}
