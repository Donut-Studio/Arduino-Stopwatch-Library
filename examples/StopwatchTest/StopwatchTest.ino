/*
  DonutStudioStopwatch.h - Library for creating a stopwatch with the millis()-function from the arduino.
  Created by Donut Studio, March 02, 2023.
  Released into the public domain.
*/

// include the libraray
#include "DonutStudioStopwatch.h"

// create an object of the Stopwatch class
Stopwatch sw = Stopwatch(); 

void setup() 
{
  // start the serial port
  Serial.begin(9600);

  // print the current time
  printStopwatch();

  // start the stopwatch
  sw.start();
}
void loop() 
{
  printStopwatch();
}

void printStopwatch()
{
  Serial.print("total:  ");
  Serial.print(sw.getElapsedHours());
  Serial.print(" ");
  Serial.print(sw.getElapsedMinutes());
  Serial.print(" ");
  Serial.print(sw.getElapsedSeconds());
  Serial.print(" ");
  Serial.println(sw.getElapsedMilliseconds());
  
  Serial.print("elapsed:  ");
  Serial.print(sw.getElapsedHours());
  Serial.print(":");
  Serial.print(sw.getMinutes());
  Serial.print(":");
  Serial.print(sw.getSeconds());
  Serial.print(":");
  Serial.println(sw.getMilliseconds());

  Serial.println();
}