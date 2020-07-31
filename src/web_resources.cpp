#include <web_resources.h>
#include <string>

using namespace std;

Web_resource Web_resource::from(const string resource) {
    Web_resource wr;
    wr._resource = resource;
    return wr;
}

Web_resource &Web_resource::key(const string &k) {
    _keys.push_back(k);
    return *this;
}

Web_resource &Web_resource::key(int k) {
    return key(to_string(k));
}

Web_resource &Web_resource::key(unsigned int k) {
    return key(to_string(k));
}

Web_resource &Web_resource::key(const char *k) {
    return key(string(k));
}

json_cpp::Json_web_response Web_resource::get() {
    return Json_web_get(url());
}

std::string Web_resource::url() {
    string url = "https://raw.githubusercontent.com/germanespinosa/cellworld_data/master/" + _resource + "/";
    bool first = true;
    for (auto &k : _keys) {
        if (!first) url +='.';
        first = false;
        url += k;
    }
    return url;
}
