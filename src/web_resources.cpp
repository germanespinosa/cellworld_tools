#include <cell_world_tools/web_resources.h>
#include <string>
#include <json_cpp.h>

using namespace std;
namespace cell_world_tools {
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

    std::istream &Web_resource::get() {
        string cfn = "." + _resource + "." + _file_name();
        ifstream cache(cfn);
        if (cache.good()) {
            _resource_stream = std::move(cache);
            return _resource_stream;
        }
        { // time to download the resource
            ofstream cache_file;
            cache_file.open(cfn);
            auto wr = Json_web_get(url());
            cache_file << wr.get_string();
            cache_file.close();
        }
        return _resource_stream = ifstream(cfn);
    }

    std::string Web_resource::url() {
        string url = "https://raw.githubusercontent.com/germanespinosa/cellworld_data/master/" + _resource + "/" +
                     _file_name();
        return url;
    }

    std::string Web_resource::_file_name() {
        string fn;
        bool first = true;
        for (auto &k : _keys) {
            if (!first) fn += '.';
            first = false;
            fn += k;
        }
        return fn;
    }
}