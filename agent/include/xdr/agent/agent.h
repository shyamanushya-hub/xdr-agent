#pragma once

#include "xdr/common/event.h"

#include <functional>
#include <vector>

namespace xdr::agent {

using EventHandler = std::function<void(const common::Event&)>;

class Agent {
 public:
  void start();
  void stop();

  void publish(const common::Event& event);
  void on_event(EventHandler handler);

 private:
  bool running_ = false;
  std::vector<EventHandler> handlers_;
};

}  // namespace xdr::agent
