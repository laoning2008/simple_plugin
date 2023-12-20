#pragma once
#include <symbol_visibility.hpp>
#include <plugin.hpp>

PLUGIN_API plugin* create_plugin();
PLUGIN_API void destroy_plugin(plugin* p);
