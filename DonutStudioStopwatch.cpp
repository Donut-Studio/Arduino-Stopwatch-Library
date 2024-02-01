/*
  DonutStudioStopwatch.h - Arduino library for creating a stopwatch with the millis()-function.
  Created by Donut Studio, Febuary 01, 2024.
  Released into the public domain.
*/

#include <Arduino.h>
#include <DonutStudioStopwatch.h>


/* --- CONSTRUCTOR --- */

Stopwatch::Stopwatch(bool instantStart)
{
  if (instantStart)
    start();
}

/* --- METHODS --- */
/* MAIN */

void Stopwatch::start()
{
  _stopwatchStarted = true;
  _stopwatchPaused = false;
  _stopwatchPauseTime = 0;
  _stopwatchStartTimestamp = millis();
}
void Stopwatch::stop()
{
  _stopwatchDuration = getElapsedMilliseconds();
  _stopwatchStarted = false;
}
bool Stopwatch::isActive()
{
  return _stopwatchStarted;
}
void Stopwatch::setPause(bool value)
{
  if (_stopwatchPaused == value)
    return;

  _stopwatchPaused = value;
  if (value)
    _stopwatchPauseTimestamp = millis();
  else
    _stopwatchPauseTime += millis() - _stopwatchPauseTimestamp;
}
bool Stopwatch::isPaused()
{
  return _stopwatchPaused;
}

/* ELAPSED TIME */

unsigned long Stopwatch::getElapsedMilliseconds()
{
  if (!_stopwatchStarted)
    return _stopwatchDuration;

  unsigned long mil = millis();
  unsigned long elapsed = mil - _stopwatchStartTimestamp - _stopwatchPauseTime;

  if (_stopwatchPaused)
    return elapsed - mil + _stopwatchPauseTimestamp;
  return elapsed;
}
int Stopwatch::getMilliseconds()
{
  return (int)(getElapsedMilliseconds() % 1000);
}
int Stopwatch::getSeconds()
{
  return (int)((getElapsedMilliseconds() / 1000) % 60);
}
int Stopwatch::getMinutes()
{
  return (int)((getElapsedMilliseconds() / 1000 / 60) % 60);
}
int Stopwatch::getHours()
{
  return (int)(getElapsedMilliseconds() / 1000 / 3600);
}