/* Timer.cpp - Real Time Library
 *
 * Copyright 2019-2024 Marcio Pessoa
 *
 */

#include "Arduino.h"
#include "Timer.h"

/* Timer
 *
 * Description
 *   Timers used to build real time applications.
 *
 *   Timer (int period, int type)
 *
 * Parameters
 *   pin: Arduino LED pin
 *   type: Possible values: LOOP (default)
 *                          COUNTDOWN
 *                          STOPWATCH
 *
 * Returns
 *   void
 */
Timer::Timer(unsigned long period, Type type) {
  _period = period;
  _type = type;
  _counter = millis();
  _enable = true;
}

/* check
 *
 * Description
 *   Check timer status.
 *
 *   timer.check()
 *
 * Parameters
 *   period: Timer period
 *
 * Returns
 *   bool: True if error, false if OK
 */
bool Timer::check() {
  switch (_type) {
    default:
    case Type::LOOP: {
      if (millis() - _counter >= _period) {
        _counter += _period;
        return true;
      }
      break;
    }
    case Type::COUNTDOWN: {
      if (millis() - _counter >= _period) {
        _enable = false;
        return true;
      }
      break;
    }
    case Type::STOPWATCH: {
      return false;
    }
  }
  return false;
}

/* set
 *
 * Description
 *  Set timer period.
 *
 *  timer.set()
 *
 * Parameters
 *  period: Timer period
 *
 * Returns
 *  void
 */
void Timer::set(unsigned long period) {
  _period = period;
  reset();
}

/* reset
 *
 * Description
 *   Reset timer.
 *
 *   timer.reset()
 *
 * Parameters
 *   none
 *
 * Returns
 *   void
 */
void Timer::reset() {
  _enable = true;
  _counter = millis();
}

/* read
 *
 * Description
 *   Read defined time period.
 *
 *   timer.read()
 *
 * Parameters
 *   none
 *
 * Returns
 *   unsigned long: defined time period
 */
unsigned long Timer::read() {
  return _period;
}

/* residual
 *
 * Description
 *   Return residual time amount.
 *
 *   timer.residual()
 *
 * Parameters
 *   none
 *
 * Returns
 *   unsigned long: residual time period
 */
unsigned long Timer::residual() {
  if (_enable) return _period - (millis() - _counter);
  else return 0;
}

/* elapsed
 *
 * Description
 *   Return elapsed time amount.
 *
 *   timer.elapsed()
 *
 * Parameters
 *   none
 *
 * Returns
 *   unsigned long: elapsed time period
 */
unsigned long Timer::elapsed() {
  return millis() - _counter;
}

/* enable
 *
 * Description
 *   Enable timer.
 *
 *   timer.enable()
 *
 * Parameters
 *   none
 *
 * Returns
 *   void
 */
void Timer::enable() {
  _enable = true;
}

/* disable
 *
 * Description
 *   Disable timer.
 *
 *   timer.disable()
 *
 * Parameters
 *   none
 *
 * Returns
 *   void
 */
void Timer::disable() {
  _enable = false;
}

/* human_time
 *
 * Description
 *   Show nice output formatted time.
 *
 *   human_time(unsigned long milliseconds)
 *
 * Parameters
 *   unsigned long: milliseconds
 *
 * Returns
 *   String: Formated time, like: "9 days, 15:14:03"
 */
String Timer::human_time(unsigned long milliseconds) {
  String time = "";
  byte s = (milliseconds / 1000) % 60;     // Seconds
  byte m = (milliseconds / 60000) % 60;    // Minutes
  byte h = (milliseconds / 3600000) % 24;  // Hours
  byte d = (milliseconds / 86400000);      // Days
  // Day
  if (d) {
    time += String(d) + " day";
    if (d > 1) time += "s";
    time += ", ";
  }
  // Hour
  if (h < 10) time += "0";
  time += String(h) + ":";
  // Minute
  if (m < 10) time += "0";
  time += String(m) + ":";
  // Second
  if (s < 10) time += "0";
  time += String(s);
  return time;
}
