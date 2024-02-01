/*
  DonutStudioStopwatch.h - Arduino library for creating a stopwatch with the millis()-function.
  Created by Donut Studio, Febuary 01, 2024.
  Released into the public domain.
*/

// include the libraray
#include <DonutStudioStopwatch.h>

// connect GND and pin 2 to toggle pausing
#define BUTTON 2

// create an object of the Stopwatch class
Stopwatch sw = Stopwatch(); 

void setup() 
{
  Serial.begin(9600);

  pinMode(BUTTON, INPUT_PULLUP);

  printStopwatch();

  sw.start();
}
void loop() 
{
  printStopwatch();

  if (digitalRead(BUTTON) == 0)
  {
    while (digitalRead(BUTTON) == 0);
    sw.setPause(!sw.isPaused());
    Serial.println("toggled pause...");
  }
}

void printStopwatch()
{
  Serial.print(sw.getHours());
  Serial.print(":");
  Serial.print(sw.getMinutes());
  Serial.print(":");
  Serial.print(sw.getSeconds());
  Serial.print(":");
  Serial.println(sw.getMilliseconds());
}