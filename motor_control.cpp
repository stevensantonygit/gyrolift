#include <Arduino.h>
#include "motor_control.h"

void setupMotor(int in1, int in2, int enPin, int pwmChannel, int freq, int resolution) {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  ledcSetup(pwmChannel, freq, resolution);
  ledcAttachPin(enPin, pwmChannel);
}

void driveMotor(int in1, int in2, int pwmChannel, bool forward) {
  digitalWrite(in1, forward ? HIGH : LOW);
  digitalWrite(in2, forward ? LOW : HIGH);
  ledcWrite(pwmChannel, 180);  // Adjust PWM speed if needed
}

void stopMotor(int in1, int in2, int pwmChannel) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  ledcWrite(pwmChannel, 0);
}