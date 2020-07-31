#pragma once
#include <json_cpp.h>
#include <iostream>
#include <cell_world_tools/web_resources.h>

#define Add_web_resource(PARAMETER, KEYS) \
    _add_param(#PARAMETER, #PARAMETER, std::vector<std::string>KEYS); \
    Add_member(PARAMETER)
#define Add_web_resource_from_table(PARAMETER, TABLE, KEYS) \
    _add_param(#PARAMETER, TABLE, std::vector<std::string>KEYS); \
    Add_member(PARAMETER)
#define Add_value(PARAMETER) \
    _add_param(#PARAMETER); \
    Add_member(PARAMETER)

#define Parameters_definitions(PARAMETERS) Json_object_members(PARAMETERS)

namespace cell_world_tools {
    struct Parameters_loader {
        Parameters_loader() = default;

        Parameters_loader(int argc, char **argv);

        const std::string &operator[](const std::string &);

        bool contains(const std::string &) const;

        bool empty() const;

        std::string program_name;
    private:
        std::vector<std::string> _parameters_names;
        std::vector<std::string> _parameters_value;
    };

    struct Parameters_builder : json_cpp::Json_object {
        bool load(int argc, char **argv);

    protected:
        bool _check_parameters();

        void _show_help();

        void _add_param(const std::string &);

        void _add_param(const std::string &, const std::string &, const std::vector<std::string> &);

        void _add_param(const std::string &) const {}

        void _add_param(const std::string &, const std::string &, const std::vector<std::string> &)
        const {}

        Parameters_loader _cmd_parameters;
        std::vector<std::string> _parameters_names;
        std::vector<std::string> _parameters_resources;
        std::vector<std::vector<std::string>> _parameters_keys;
    };
}