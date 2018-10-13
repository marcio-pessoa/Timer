#include <Timer.h>

bool ledState = false;
int period = 1000;
Timer blinker(period);

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  if (blinker.check()) {
    ledState = !ledState;
    digitalWrite(13, ledState);
    period -= 10;
    blinker.set(period);
  }
}
