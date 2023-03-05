/*
  DonutStudioStopwatch.h - Library for creating a stopwatch with the millis()-function from the arduino.
  Created by Donut Studio, March 05, 2023.
  Released into the public domain.
*/

#include "Arduino.h"
#include "DonutStudioStopwatch.h"

/*
  --- --- CONSTRUCTOR --- ---
*/

Stopwatch::Stopwatch(bool instantStart)
{
  // check if the stopwatch should count instantly
  if (instantStart)
    start();
}


/*
  --- --- METHODS --- ---
*/

/*
  --- MAIN ---
*/

void Stopwatch::start()
{
  // set the stopwatch boolean
  _stopwatchStarted = true;
  // set the start timestamp
  _stopwatchStartTimestamp = millis();
}
void Stopwatch::stop()
{
  // reset the boolean to false
  _stopwatchStarted = false;
  // set the duration
  _stopwatchDuration = millis() - _stopwatchStartTimestamp;
}
bool Stopwatch::isActive()
{
  // return the boolean which indicates the state
  return _stopwatchStarted;
}


/*
  --- ELAPSED TIME ---
*/

unsigned long Stopwatch::getElapsedMilliseconds()
{
  // if the stopwatch is still active, calculate and return the current time (prevents millis overflow)
  if (isActive())
    return millis() - _stopwatchStartTimestamp;
  // if the stopwatch was stopped, return the duration
  return _stopwatchDuration;
}
int Stopwatch::getMilliseconds()
{
  // returns the elapsed milliseconds from 0 to 999
  return (int)(getElapsedMilliseconds() % 1000);
}
int Stopwatch::getSeconds()
{
  // returns the elapsed seconds from 0 to 59
  return (int)((getElapsedMilliseconds() / 1000) % 60);
}
int Stopwatch::getMinutes()
{
  // returns the elapsed minutes from 0 to 59
  return (int)((getElapsedMilliseconds() / 1000 / 60) % 60);
}
int Stopwatch::getHours()
{
  // returns the elapsed hours
  return (int)(getElapsedMilliseconds() / 1000 / 3600);
}