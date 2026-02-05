#include "xdr/common/log.h"

#include <iostream>
#include <mutex>

namespace xdr::common {

namespace {
std::mutex g_lock;
LogLevel g_level = LogLevel::Info;

const char* to_string(LogLevel level) {
  switch (level) {
    case LogLevel::Trace:
      return "TRACE";
    case LogLevel::Debug:
      return "DEBUG";
    case LogLevel::Info:
      return "INFO";
    case LogLevel::Warn:
      return "WARN";
    case LogLevel::Error:
      return "ERROR";
  }
  return "UNKNOWN";
}

bool enabled(LogLevel level) {
  return static_cast<int>(level) >= static_cast<int>(g_level);
}
}  // namespace

void init_logging(LogLevel level) {
  std::lock_guard<std::mutex> lock(g_lock);
  g_level = level;
}

void log(LogLevel level, std::string_view message) {
  if (!enabled(level)) {
    return;
  }
  std::lock_guard<std::mutex> lock(g_lock);
  std::cout << "[" << to_string(level) << "] " << message << std::endl;
}

}  // namespace xdr::common
