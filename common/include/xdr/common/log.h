#pragma once

#include <string_view>

namespace xdr::common {

enum class LogLevel {
  Trace = 0,
  Debug = 1,
  Info = 2,
  Warn = 3,
  Error = 4
};

void init_logging(LogLevel level);
void log(LogLevel level, std::string_view message);

}  // namespace xdr::common
