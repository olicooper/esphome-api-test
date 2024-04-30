import esphome.config_validation as cv
import esphome.codegen as cg
import logging

from esphome.components import uart
from esphome.const import (
    CONF_ID
)

DEPENDENCIES = ["wifi", "api", "esp32"]

api_test_ns = cg.esphome_ns.namespace("api_test")
APITest = api_test_ns.class_("APITest", cg.Component)

CONFIG_SCHEMA = cv.All(
    cv.Schema({
        cv.GenerateID(): cv.declare_id(APITest),
    })
    .extend(cv.COMPONENT_SCHEMA),
    cv.only_on_esp32
)

def validate_config(config):
    return config

async def to_code(config):
    conf_id = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(conf_id, config)
    cg.add_define("USE_API_TEST")
    cg.add_global(api_test_ns.using)