#pragma once
#include <any>
#include <vector>
#include <string>
#include <sstream>
#include <json_cpp.h>

struct Web_resource {
    static Web_resource from(const std::string);
    Web_resource &key(const std::string &);
    Web_resource &key(int);
    Web_resource &key(unsigned int);
    Web_resource &key(const char *);
    json_cpp::Json_web_response get();
    std::string url();
private:
    std::string _resource;
    std::vector<std::string> _keys;
    Web_resource () = default;
};