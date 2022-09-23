#include "rgb_demo.h"
#include "wifi_demo.h"
#include "eink_demo.h"

void setup()
{
  Serial.begin(115200);
  while (!Serial)
  {
    ;
    delay(10);
  }

  wifi_setup();
  eink_setup();
  rgb_setup();
}

void loop()
{
  wifi_loop();
  eink_loop();
  rgb_loop();
}
