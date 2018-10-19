/* Timer.h - Real Time Library
 * 
 * Author: Márcio Pessoa <marcio.pessoa@gmail.com>
 * Contributors: none
 * 
 * Methods
 *   Timer(unsigned long period, byte type = LOOP)
 *     Instantiates a Timer object with a set interval in milliseconds.
 *     Optionally can set Timer type:
 *       LOOP (default)
 *         Count to time limit and restart automaticaly when limit is reached
 *       COUNTDOWN
 *         Count to time limit and set OK when limit is reached.
 *         The counter must be restarted manually to continue.
 *       STOPWATCH
 *         Just a stopwatch, counts infinitely.
 *   bool check()
 *     Returns true if the interval has lapsed. Returns false if not.
 *   void set(unsigned long period)
 *     Changes the interval in milliseconds.
 *   void reset()
 *     Restarts/resets the Timer. Often a good idea if you change the interval.
 *   void enable()
 *     Enable Timer, by default it is enabled.
 *   void disable()
 *     Disble Timer.
 * 
 * Change log
 * 2015-10-04
 *         * check
 *         Bug fix on COUNTDOWN timer. Now counter stop decreasing after
 *         reaches 0.
 * 
 * 2015-09-27
 *         * residual
 *         Added residual method.
 * 
 * 2014-11-16
 *         * Timer
 *         Changed (int period) to (unsigned long period).
 *         * set
 *         Changed (int period) to (unsigned long period).
 * 
 * 2014-07-06
 *         Experimental version.
 */

#ifndef Timer_h
#define Timer_h

#include "Arduino.h"

#define LOOP 0
#define COUNTDOWN 1
#define STOPWATCH 2

class Timer
{
  public:
    Timer(unsigned long period = 0, byte type = LOOP);
    void set(unsigned long period = 0);
    unsigned long read();
    unsigned long residual();
    void reset();
    void enable();
    void disable();
    bool check();
  private:
    unsigned long _period;
    byte _type;
    unsigned long _counter;
    bool _enable;
};

String human_time(unsigned long milliseconds);

#endif
