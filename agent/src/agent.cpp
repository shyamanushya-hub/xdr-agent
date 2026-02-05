#include "xdr/agent/agent.h"

#include "xdr/common/log.h"

namespace xdr::agent {

void Agent::start() {
  running_ = true;
  common::log(common::LogLevel::Info, "Agent started");
}

void Agent::stop() {
  running_ = false;
  common::log(common::LogLevel::Info, "Agent stopped");
}

void Agent::publish(const common::Event& event) {
  if (!running_) {
    return;
  }
  for (auto& handler : handlers_) {
    handler(event);
  }
}

void Agent::on_event(EventHandler handler) {
  handlers_.push_back(std::move(handler));
}

}  // namespace xdr::agent
