#pragma once
#include <json_cpp.h>
#include <iostream>
#include <cell_world_tools/web_resources.h>

#define Add_web_resource_from_table(PARAMETER, TABLE, KEYS) \
    _add_param(#PARAMETER, Json_needs_quotes(PARAMETER), TABLE, std::vector<std::string>KEYS); \
    Add_member(PARAMETER)

#define Add_web_resource(PARAMETER, KEYS) Add_web_resource_from_table (PARAMETER, #PARAMETER, KEYS)

#define Add_value(PARAMETER) \
    _add_param(#PARAMETER, Json_needs_quotes(PARAMETER)); \
    Add_member(PARAMETER)

#define Parameters_definitions(PARAMETERS) Json_object_members(PARAMETERS)

namespace cell_world {
    struct Parameters_loader : json_cpp::Json_dictionary {
        Parameters_loader() = default;
        Parameters_loader(int argc, char **argv);
        std::string program_name;
    };

    struct Parameters_builder : json_cpp::Json_object {
        bool load(int argc, char **argv);
        Parameters_loader cmd_parameters;

    protected:
        bool _check_parameters();
        void _show_help();
        void _add_param(const std::string &, bool);
        void _add_param(const std::string &, bool, const std::string &, const std::vector<std::string> &);
        void _add_param(const std::string &, bool) const {}
        void _add_param(const std::string &, bool, const std::string &, const std::vector<std::string> &) const {}

        std::vector<std::string> _parameters_names;
        std::vector<bool> _requires_quotes;
        std::vector<std::string> _parameters_resources;
        std::vector<std::vector<std::string>> _parameters_keys;
    };
}