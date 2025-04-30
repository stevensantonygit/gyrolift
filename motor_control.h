#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

void setupMotor(int in1, int in2, int enPin, int pwmChannel, int freq, int resolution);
void driveMotor(int in1, int in2, int pwmChannel, bool forward);
void stopMotor(int in1, int in2, int pwmChannel);

#endif