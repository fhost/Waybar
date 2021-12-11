#pragma once

#include <fmt/format.h>
#include <fstream>
#include "ALabel.hpp"
#include "util/sleeper_thread.hpp"

namespace waybar::modules {

class Temperature : public ALabel {
 public:
  Temperature(const std::string&, const Json::Value&);
  ~Temperature() = default;
  auto update() -> void;

 private:
  float               getTemperature();

  int                 max_temperature_;
  std::string         file_path_;
  util::SleeperThread thread_;
};

}  // namespace waybar::modules
