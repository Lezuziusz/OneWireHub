/*
 *    track program-size development
 *
 *    7350 // 470 bytes v1.1.0 without gpio- and serial-debug (basic ds18b20-thermometer-sketch)
 *    5280 // 439 bytes without blinking-code and float-temp-operations
 *    4222 // 212 bytes without serial
 *    3856 // 172 bytes just 1 instead of 3 ds18b20
 *
 *    5150 // 181 bytes switch to branch with automatic timing calibration
 *
 *
 */

#include "OneWireHub.h"
#include "DS18B20.h"  // Digital Thermometer, 12bit

constexpr uint8_t pin_onewire   { 8 };

auto hub    = OneWireHub(pin_onewire);

auto ds18b20 = DS18B20(DS18B20::family_code, 0x00, 0x02, 0x0B, 0x08, 0x01, 0x0D);    // Digital Thermometer


void setup()
{
    // Setup OneWire
    hub.attach(ds18b20);

    // Set const temperature
    const int16_t temperature = 21;
    ds18b20.setTemp(temperature);
};

void loop()
{
    // following function must be called periodically
    hub.poll();
    // this part is just for debugging (USE_SERIAL_DEBUG in OneWire.h must be enabled for output)
    if (hub.getError()) hub.printError();

}