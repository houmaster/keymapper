
#include "Settings.h"
#include <cstdio>

bool interpret_commandline(Settings& settings, int argc, char* argv[]) {
  for (auto i = 1; i < argc; i++) {
    const auto argument = std::string(argv[i]);
    if (argument == "-u" || argument == "--update") {
      settings.auto_update_config = true;
    }
    else if (argument == "-c" || argument == "--config") {
      if (++i >= argc)
        return false;
      settings.config_file_path = argv[i];
    }
    else {
      return false;
    }
  }
  return true;
}

void print_help_message(const char* arg0) {
  const auto version =
#include "../../_version.h"
  ;
  std::printf(
    "keymapper %s (c) 2019 by Albert Kalchmair\n"
    "\n"
    "Usage: %s [-options]\n"
    "  -c, --config <path>  configuration file.\n"
    "  -u, --update         reload configuration file when it changes.\n"
    "\n"
    "All Rights Reserved.\n"
    "This program comes with absolutely no warranty.\n"
    "See the GNU General Public License, version 3 for details.\n"
    "\n", version, arg0);
}