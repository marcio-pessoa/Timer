# Arduino Timer Library

A simple real-time library for Arduino for creating timers to schedule events. This library allows you to create timers that can be used to perform tasks at specific intervals without blocking the `loop()` function.

## Features

*   **Multiple Timer Types**: Supports `LOOP`, `COUNTDOWN`, and `STOPWATCH` timers.
*   **Non-Blocking**: Does not use `delay()`, allowing your main loop to run freely.
*   **Easy to Use**: Simple and intuitive API.
*   **Lightweight**: Minimal memory footprint.

## Installation

1.  Download the latest release from the [releases page](https://github.com/marcio-pessoa/Timer/releases).
2.  In the Arduino IDE, go to `Sketch > Include Library > Add .ZIP Library...` and select the downloaded ZIP file.
3.  You can now include the library in your sketch: `#include <Timer.h>`

## Usage

Here are some examples of how to use the different timer types.

### LOOP Timer

A `LOOP` timer runs continuously and fires an event at a regular interval. This is useful for tasks that need to be repeated, like blinking an LED.

```cpp
#include <Timer.h>

Timer blinker(500); // Create a timer that fires every 500ms
bool ledState = false;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (blinker.check()) {
    ledState = !ledState;
    digitalWrite(LED_BUILTIN, ledState);
  }
}
```

### COUNTDOWN Timer

A `COUNTDOWN` timer runs once for a specified duration and then stops. It's useful for tasks that should happen only once after a certain time.

```cpp
#include <Timer.h>

Timer countdown(5000, Timer::Type::COUNTDOWN); // Create a 5-second countdown timer

void setup() {
  Serial.begin(9600);
  Serial.println("Starting 5-second countdown...");
}

void loop() {
  if (countdown.check()) {
    Serial.println("Countdown finished!");
    // To restart the countdown, call countdown.reset()
  }
}
```

### STOPWATCH Timer

A `STOPWATCH` timer is used to measure elapsed time.

```cpp
#include <Timer.h>

Timer stopwatch(0, Timer::Type::STOPWATCH); // Create a stopwatch

void setup() {
  Serial.begin(9600);
  Serial.println("Stopwatch started. Press a key to see elapsed time.");
  stopwatch.reset();
}

void loop() {
  if (Serial.available() > 0) {
    Serial.read(); // consume the character
    unsigned long elapsedTime = stopwatch.elapsed();
    Serial.print("Elapsed time: ");
    Serial.print(elapsedTime);
    Serial.println(" ms");
  }
}
```

## API Reference

### `Timer(unsigned long period = 0, Type type = Type::LOOP)`
Constructor to create a new Timer object.
* `period`: The timer period in milliseconds.
* `type`: The type of timer. Can be `Type::LOOP`, `Type::COUNTDOWN`, or `Type::STOPWATCH`.

### `bool check()`
Checks if the timer has reached its set period.
* Returns `true` if the period has elapsed, `false` otherwise. For `STOPWATCH`, it always returns `false`.

### `void set(unsigned long period)`
Sets a new period for the timer.
* `period`: The new period in milliseconds.

### `void reset()`
Resets the timer. For `LOOP` and `COUNTDOWN`, it restarts the timer. For `STOPWATCH`, it resets the elapsed time to zero.

### `unsigned long read()`
Returns the configured period of the timer in milliseconds.

### `unsigned long residual()`
Returns the remaining time until the next event in milliseconds.

### `unsigned long elapsed()`
Returns the elapsed time since the timer was started or reset, in milliseconds.

### `void enable()`
Enables the timer.

### `void disable()`
Disables the timer.

### `static String Timer::human_time(unsigned long milliseconds)`
A static helper function to convert a duration in milliseconds to a human-readable string (e.g., "1 day, 02:30:00").
* `milliseconds`: The duration to convert.
