/* Timer.h - Real Time Library
 *
 * Copyright 2019-2024 Marcio Pessoa
 *
 * Author: Márcio Pessoa <marcio.pessoa@gmail.com>
 * Contributors: none
 */

#ifndef Timer_h
#define Timer_h

#include "Arduino.h"

enum class Type : byte {
  LOOP,
  COUNTDOWN,
  STOPWATCH
};

class Timer
{
  public:
    /**
     * @brief Construct a new Timer object
     * @param period The timer period in milliseconds
     * @param type The type of the timer (LOOP, COUNTDOWN, or STOPWATCH)
     */
    Timer(unsigned long period = 0, Type type = Type::LOOP);

    /**
     * @brief Set a new period for the timer
     * @param period The new period in milliseconds
     */
    void set(unsigned long period = 0);

    /**
     * @brief Read the configured period of the timer
     * @return The period in milliseconds
     */
    unsigned long read();

    /**
     * @brief Get the remaining time until the next event
     * @return The residual time in milliseconds
     */
    unsigned long residual();

    /**
     * @brief Get the elapsed time since the timer was started or reset
     * @return The elapsed time in milliseconds
     */
    unsigned long elapsed();

    /**
     * @brief Reset the timer
     */
    void reset();

    /**
     * @brief Enable the timer
     */
    void enable();

    /**
     * @brief Disable the timer
     */
    void disable();

    /**
     * @brief Check if the timer has reached its set period
     * @return True if the period has elapsed, false otherwise
     */
    bool check();

    /**
     * @brief Convert a duration in milliseconds to a human-readable string
     * @param milliseconds The duration to convert
     * @return A string representation of the time
     */
    static String human_time(unsigned long milliseconds);
  private:
    unsigned long _period;
    Type _type;
    unsigned long _counter;
    bool _enable;
};

#endif
