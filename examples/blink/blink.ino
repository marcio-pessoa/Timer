#include <Timer.h>

bool ledState = false;
Timer blinker(500);

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  if (blinker.check())
    ledState = !ledState;
  digitalWrite(13, ledState);
}
