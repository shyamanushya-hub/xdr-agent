#include "xdr/agent/agent.h"
#include "xdr/common/log.h"

#include <chrono>
#include <string>

int main() {
  xdr::common::init_logging(xdr::common::LogLevel::Info);

  xdr::agent::Agent agent;
  agent.on_event([](const xdr::common::Event& event) {
    xdr::common::log(xdr::common::LogLevel::Info, "Event received: " + event.details);
  });

  agent.start();

  xdr::common::Event event;
  event.type = xdr::common::EventType::ProcessStart;
  event.timestamp_ns = static_cast<std::uint64_t>(
      std::chrono::duration_cast<std::chrono::nanoseconds>(
          std::chrono::system_clock::now().time_since_epoch())
          .count());
  event.host = "localhost";
  event.process = "demo.exe";
  event.details = "pid=1234";
  agent.publish(event);

  agent.stop();
  return 0;
}
