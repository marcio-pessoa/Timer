#include <Timer.h>

Timer period(1000);

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (period.check())
    Serial.println(millis());
}
