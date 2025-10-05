#define BLYNK_TEMPLATE_ID           "TMPL2cMa1zpxs"
#define BLYNK_TEMPLATE_NAME         "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "kB6RogjSf80r9YgmX8HCINyR_5fEJWzU"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#include "inventory.h"
#include "schedule.h"
#include "motor.h"
#include "buzzer.h"

char ssid[] = "";
char pass[] = "";

BlynkTimer timer;

BLYNK_WRITE(V0)
{
  int value = param.asInt();
  
  // Rotate to position
  
}

BLYNK_CONNECTED()
{
  
}

void tick()
{
  
}

void setup()
{
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Check schedule
  timer.setInterval(1000L, tick);
}

void loop()
{
  Blynk.run();
  timer.run();
}
