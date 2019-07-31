#ifndef ALARM_H
#define ALARM_H

#include "Globals.h"
#include <Arduino.h>

static void alarm() {
  analogWrite(BUZZER, 100);
  delay(50);
  analogWrite(BUZZER, 130);
  delay(50);
  analogWrite(BUZZER, 160);
  delay(50);
  analogWrite(BUZZER, 200);
  delay(50);
  analogWrite(BUZZER, 230);
  delay(50);
  analogWrite(BUZZER, 50);
  delay(50);
}

#endif
