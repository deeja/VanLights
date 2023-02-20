#include <Arduino.h>

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
  
  // red pattern

  if (sensor < 25){
    int count = sensor / 5;
    //set X reds low


  } else if (sensor < 50) {
    int brightness = ((sensor - 25) * 10) + 5;
    // gives me brightness to apply to red leds
  } else if (sensor < 75){
    int count = (sensor - 50) / 5;
  } else if (sensor < 100){
    int brightness = ((sensor - 75) * 10) + 5;
    // gives me brightness to apply to white leds
  } else {
    // party time
  }

  
  for (size_t i = 0; i < 100; i++)
  {
    //Serial.print(".");
  }
  Serial.println();

  
  delay(100);
}