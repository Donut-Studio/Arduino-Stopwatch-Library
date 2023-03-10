/*
  DonutStudioStopwatch.h - Library for creating a stopwatch with the millis()-function from the arduino.
  Created by Donut Studio, March 05, 2023.
  Released into the public domain.
*/

#ifndef DonutStudioStopwatch.h
#define DonutStudioStopwatch.h

#include "Arduino.h"


class Stopwatch
{
  /*
    --- PUBLIC ---
  */
  public:
    /*
      --- CONSTRUCTOR ---
    */

    // constructor for the class 
    Stopwatch(bool instantStart = false);


    /*
      --- METHODS ---
    */


    /*-- MAIN --*/

    // starts to count, if it is already counting it stops first
    void start();
    // stops counting
    void stop();
    // checks if the stopwatch is already counting
    bool isActive();


    /*-- ELAPSED TIME --*/

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


  /*
    --- PRIVATE ---
  */
  private:
    /*
      --- VARIABLES ---
    */

    bool _stopwatchStarted = false;
    unsigned long _stopwatchStartTimestamp = 0;
    unsigned long _stopwatchDuration = 0;
};
#endif