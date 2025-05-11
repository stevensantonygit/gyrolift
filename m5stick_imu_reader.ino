#include <M5StickCPlus2.h>
const float alpha = 0.98;
float pitch = 0.0;
float roll = 0.0;
unsigned long lastUpdate = 0;

void setup() {
  M5.begin();
  Serial.begin(115200);
  if (M5.Imu.Init() != 0) {
    Serial.println("IMU initialization failed!");
    while (1);
  } else {
    Serial.println("IMU initialized successfully.");
  }
  lastUpdate = millis();
}

void loop() {
  float accX, accY, accZ;
  float gyroX, gyroY, gyroZ;
  M5.Imu.getAccelData(&accX, &accY, &accZ);
  M5.Imu.getGyroData(&gyroX, &gyroY, &gyroZ);
  unsigned long now = millis();
  float dt = (now - lastUpdate) / 1000.0;
  lastUpdate = now;
  float accPitch = atan2(accY, sqrt(accX * accX + accZ * accZ)) * 180 / PI;
  float accRoll  = atan2(-accX, accZ) * 180 / PI;
  pitch = alpha * (pitch + gyroX * dt) + (1 - alpha) * accPitch;
  roll  = alpha * (roll + gyroY * dt) + (1 - alpha) * accRoll;
  Serial.print("Pitch: ");
  Serial.print(pitch);
  Serial.print(" °\tRoll: ");
  Serial.print(roll);
  Serial.println(" °");
  delay(10);
}