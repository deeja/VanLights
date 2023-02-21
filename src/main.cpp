#include <Arduino.h>

char pattern[5];
size_t oldSensor = 0;

void setup()
{
  Serial.begin(9600);
  // put your setup code here, to run once:

  Serial.println("START");
}

void loop()
{
  // put your main code here, to run repeatedly:
  size_t sensor = analogRead(A0) / 10;

  if (oldSensor == sensor)
  {
    delay(100);
    return;
  }
  oldSensor = sensor;

  // red pattern

  if (sensor >= 100)
  {
    // party time
  }

  if (sensor < 25)
  {
    size_t count = sensor / 5;

    // set X reds low
    for (size_t i = 0; i < 5; i++)
    {
      char value = count >= i ? 'r' : '_';
      pattern[i] = value;
    }
  }
  else if (sensor < 50)
  {
    int brightness = ((sensor - 25) * 10) + 5;
    // gives me brightness to apply to red leds
    // set X reds low
    for (size_t i = 0; i < 5; i++)
    {
      pattern[i] = 'R';
    }
  }
  else if (sensor < 75)
  {
    size_t count = (sensor - 50) / 5;

    // set X reds low
    for (size_t i = 0; i < 5; i++)
    {
      char value = count >= i ? 'w' : '_';
      pattern[i] = value;
    }
  }
  else if (sensor < 100)
  {
    int brightness = ((sensor - 75) * 10) + 5;
    // gives me brightness to apply to white leds
    // set X reds low
    for (size_t i = 0; i < 5; i++)
    {
      pattern[i] = 'W';
    }
  }

  Serial.print(sensor);
  Serial.print(" ");
  Serial.println(pattern);

  delay(100);
}