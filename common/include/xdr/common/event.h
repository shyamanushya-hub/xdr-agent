#pragma once

#include <cstdint>
#include <string>

namespace xdr::common {

enum class EventType : std::uint8_t {
  ProcessStart,
  ProcessExit,
  FileCreate,
  FileWrite,
  FileDelete,
  NetworkConnect,
  Unknown
};

struct Event {
  EventType type{EventType::Unknown};
  std::uint64_t timestamp_ns{0};
  std::string host;
  std::string process;
  std::string path;
  std::string details;
};

}  // namespace xdr::common
