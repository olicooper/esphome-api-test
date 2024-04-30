#pragma once

#include <functional>
#include <memory>
#include <map>
#include <queue>
#include <stdint.h>
#include <string>
#include <utility>
#include <vector>

#include "esphome/core/defines.h"
#include "esphome/core/component.h"
#include "esphome/core/log.h"
#include "esphome/components/api/api_server.h"
#include "esphome/components/api/custom_api_device.h"

namespace esphome {
namespace api_test {

class APITest : public Component, public api::CustomAPIDevice {
public:
  APITest();
  void setup() override;
  void loop() override;

  // void subscribe_homeassistant_state(void (APITest::*callback)(std::string, std::string, std::string), const std::string &entity_id,
  //                                    const std::string &attribute) {
  //   auto f = std::bind(callback, this, entity_id, attribute, std::placeholders::_1);
  //   api::global_api_server->subscribe_home_assistant_state(entity_id, optional<std::string>(attribute), f);
  // }
  
  void on_entity_state_update_(std::string entity_id, std::string state);
  
  void on_entity_state_attr_update_(std::string entity_id, std::string state, std::string attribute);

protected:
};

}
}