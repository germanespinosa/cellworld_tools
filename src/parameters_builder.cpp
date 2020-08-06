#include <cell_world_tools/parameters_builder.h>

using namespace std;
namespace cell_world_tools {
    bool Parameters_builder::load(int argc, char **argv) {
        if (cin.gcount()) {
            try {
                cin >> *this;
            } catch (exception ) {
                cerr << "error parsing pipe content" << endl;
                _show_help();
                exit(EXIT_FAILURE);
            }
        } else {
            cmd_parameters = Parameters_loader(argc, argv);
            json_cpp::Json_builder jb;
            json_set_builder(jb);
            if (_check_parameters()) {
                _show_help();
                exit(EXIT_FAILURE);
            }
            for (unsigned int i = 0; i < jb.members.size(); i++) {
                string name = jb.members[i].name;
                string value = cmd_parameters[name];
                //cout << "parsing parameter '" << name << "' with value '" << value << "'" << endl;
                if (_parameters_resources[i].empty()) {
                    auto &a = *(jb.members[i].ref);
                    if (_requires_quotes[i]) {
                        value = '"' + value + '"';
                    }
                    try {
                        value >> *(jb.members[i].ref);
                    } catch (exception ){
                        cerr << "error parsing parameter '" << name << "' with value '" << value << "'" << endl;
                        _show_help();
                        exit(EXIT_FAILURE);
                    }
                } else {
                    auto wr = Web_resource::from(_parameters_resources[i]);
                    for (auto &k: _parameters_keys[i]) wr.key(cmd_parameters[k]);
                    try {
                        jb.members[i].ref->json_parse(wr.get());
                    } catch (exception ){
                        cerr << "error parsing parameter '" << name << "' from url '" << wr.url() << "'" << endl;
                        _show_help();
                        exit(EXIT_FAILURE);
                    }
                }
            }
        }
        return true;
    }

    void
    Parameters_builder::_add_param(const string &param_name, bool require_quotes, const string &resource_name, const
    vector<string> &keys) {
        _parameters_names.emplace_back(param_name);
        _requires_quotes.push_back(require_quotes);
        _parameters_resources.push_back(resource_name);
        _parameters_keys.push_back(keys);
    }

    void Parameters_builder::_add_param(const string &param_name, bool require_quotes) {
        _parameters_names.emplace_back(param_name);
        _requires_quotes.push_back(require_quotes);
        _parameters_resources.emplace_back("");
        _parameters_keys.emplace_back();
    }

    void Parameters_builder::_show_help() {
        cerr << "Usage:" << endl
             << "\t" << cmd_parameters.program_name << " ";
        for (unsigned int i = 0; i < _parameters_names.size(); i++) {
            string p = _parameters_names[i];
            string k = _parameters_keys[i].empty() ? " value" : " key";
            cerr << "-" << p << " [" << p << k << "] ";
        }
        cerr << endl << "\t[pipe_generator] | " << cmd_parameters.program_name << endl;
        exit(EXIT_FAILURE);
    }

    bool Parameters_builder::_check_parameters() {
        if (cmd_parameters.empty()) return true;
        bool fail = false;
        for (auto &m:_parameters_names) {
            if (!cmd_parameters.contains(m)) {
                cerr << "missing parameter -" + m << endl;
                fail = true;
            }
        }
        return fail;
    }

    const string &Parameters_loader::operator[](const string &name) {
        for (unsigned int i = 0; i < _parameters_names.size(); i++) {
            if (_parameters_names[i] == name) return _parameters_value[i];
        }
        throw logic_error("parameter '" + name + "' not specified");
    }

    Parameters_loader::Parameters_loader(int argc, char **argv) {
        program_name = argv[0];
        for (int i = 1; i < argc - 1; i++) {
            string name(argv[i]);
            if (name[0] == '-') {
                name.erase(0, 1);
                _parameters_names.push_back(name);
                _parameters_value.emplace_back(argv[i + 1]);
            }
        }
    }

    bool Parameters_loader::contains(const string &name) const {
        for (unsigned int i = 0; i < _parameters_names.size(); i++) {
            if (_parameters_names[i] == name) return true;
        }
        return false;
    }

    bool Parameters_loader::empty() const {
        return _parameters_names.empty();
    }
}