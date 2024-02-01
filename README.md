# STOPWATCH LIBRARY README
Welcome!
This is my solution for using the millis function to create a stopwatch.
Keep in mind that the oscillator of the arduino is not very preciced and will differ after a few hours.
If you count for over 49 days an overflow will occur and the stopwatch will restart from 0.
Feel free to use it anywere in your projects.
Cheers, Donut Studio!


***
# Features
- start/stop and pause/resume counting
- get the elapsed time


***
# Installation
1. download the `DonutStudioStopwatch` folder and extract it into the libraries folder of the Arduino Software
2. start your arduino ide and open the example sketch at `File/Examples/DonutStudioStopwatch/StopwatchTest.ino`
3. upload the sketch and watch


***
# Usage
To use the library you have to include it in your sketch and create one or multiple objects of the Stopwatch class. 
Then you can call functions to start and stop counting or get the elapsed time.
Sample code:
```cpp
// include the libraray
#include <DonutStudioStopwatch.h>

// create an object of the stopwatch class
Stopwatch sw1 = Stopwatch(); 
// create an object of the stopwatch class and start counting
Stopwatch sw2 = Stopwatch(true); 

// start the first stopwatch
sw1.start();
// stop the second stopwatch
sw2.stop();

// check if the first stopwatch is counting
sw1.isActive();

// get the milliseconds from 0 to 999 from the second stopwatch object
int ms = sw2.getMilliseconds();
// get the milliseconds from 0 to 999 from the first stopwatch object
int s = sw1.getSeconds();
```


***
# Documentation
CONSTRUCTOR
- `Stopwatch(bool instantStart = false);` => constructor for the class 

MAIN
- `void start();` => start to count from the time this method is called
- `void stop();` => stop counting
- `bool isActive();` => returns true if the stopwatch is active
- `void setPause(bool value);` => pause or resume the stopwatch
- `bool isPaused();` => returns true if the stopwatch is paused

ELAPSED TIME
- `unsigned long getElapsedMilliseconds();` => get the total elapsed milliseconds
- `int getMilliseconds();` => get the elapsed milliseconds (from 0-999)
- `int getSeconds();` => get the elapsed seconds (from 0-59)
- `int getMinutes();` => get the elapsed minutes (from 0-59)
- `int getHours();` => get the elapsed hours


***
# Credits
DonutStudioStopwatch.h - Arduino library for creating a stopwatch with the millis()-function.
Created by Donut Studio, Febuary 01, 2024.
Released into the public domain.