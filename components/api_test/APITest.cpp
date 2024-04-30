#include "APITest.h"

#include "esphome/core/application.h"
#include "esphome/core/helpers.h"
#include "esphome/core/util.h"

namespace esphome {
namespace api_test {

static const char *const TAG = "api_test";

APITest::APITest() {
}

void APITest::setup() {
  // state provides the information for the icon
  // this->subscribe_homeassistant_state(
  //   &APITest::on_entity_state_attr_update_, "timer.test_timer", "duration");

  // auto f = std::bind(&APITest::on_entity_state_update_, this, "timer.test_timer", std::placeholders::_1);
  // api::global_api_server->subscribe_home_assistant_state("timer.test_timer", optional<std::string>("duration"), f);

  // auto f = std::bind(&APITest::on_entity_state_attr_update_, this, "timer.test_timer", std::placeholders::_1);
  // api::global_api_server->subscribe_home_assistant_state("timer.test_timer", optional<std::string>("duration"), f);

  bool test = api::global_api_server->is_connected();
}

void APITest::loop() {
}

void APITest::on_entity_state_update_(std::string entity_id, std::string state) {
  ESP_LOGI(TAG, "%s -- %s", entity_id.c_str(), state.c_str());
}

void APITest::on_entity_state_attr_update_(std::string entity_id, std::string attribute, std::string state) {
  ESP_LOGI(TAG, "%s -- %s -- %s", entity_id.c_str(), attribute.c_str(), state.c_str());
}

}
}