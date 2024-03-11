/*
  DonutStudioStopwatch.h - Arduino library for creating a stopwatch with the millis()-function.
  Created by Donut Studio, March 11, 2024.
  Released into the public domain.
*/

#ifndef DonutStudioStopwatch_h
#define DonutStudioStopwatch_h

#include <Arduino.h>


class Stopwatch
{
  /* --- PUBLIC --- */
  public:
    /* --- CONSTRUCTOR --- */

    // constructor for the class 
    Stopwatch(bool instantStart = false);

    /* --- METHODS --- */
    /* MAIN */

    // start to count from the time this method is called
    void start();
    // stop counting
    void stop();
    // returns true if the stopwatch is active
    bool isActive();
    // pause or resume the stopwatch
    void setPause(bool value);
    // returns true if the stopwatch is paused
    bool isPaused();

    /* ELAPSED TIME */

    // get the total elapsed milliseconds
    unsigned long getElapsedMilliseconds();
    // get the elapsed milliseconds (from 0-999)
    int getMilliseconds();
    // get the elapsed seconds (from 0-59)
    int getSeconds();
    // get the elapsed minutes (from 0-59)
    int getMinutes();
    // get the elapsed hours
    int getHours();

  /* --- PRIVATE --- */
  private:
    /* --- VARIABLES --- */

    bool _stopwatchStarted = false;
    unsigned long _stopwatchStartTimestamp = 0;
    unsigned long _stopwatchDuration = 0;

    bool _stopwatchPaused = false;
    unsigned long _stopwatchPauseTimestamp = 0;
    unsigned long _stopwatchPauseTime = 0;
};
#endif