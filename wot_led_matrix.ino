#include <Pixel.h>
#include <SPI.h>
#include <boards.h>
#include <RBL_nRF8001.h>
#include <services.h>

Pixel pixel(7, 6, 5);

void setup()
{
  ble_set_name("LedMatrix");
  ble_begin();
}

void loop()
{
  int key = 0;
  int value = 0;
  ble_do_events();

  if (ble_available())
  {
    while (ble_available()) {
      key = ble_read() + 1;
      value = ble_read();
      pixel.sendCommand(key, value);
    }
  }
}

