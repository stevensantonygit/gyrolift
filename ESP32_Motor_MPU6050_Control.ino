#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;


#define M1_IN1  14
#define M1_IN2  27
#define M1_EN   26

#define M2_IN1  25
#define M2_IN2  33
#define M2_EN   32

#define M3_IN1  18
#define M3_IN2  19
#define M3_EN   21

const int freq = 3000;
const int resolution = 8;
const int pwmChannel1 = 0;
const int pwmChannel2 = 1;
const int pwmChannel3 = 2;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  Serial.println("Initializing MPU6050...");
  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed!");
    while (1);
  } else {
    Serial.println("MPU6050 connected.");
  }

  pinMode(M1_IN1, OUTPUT); pinMode(M1_IN2, OUTPUT);
  pinMode(M2_IN1, OUTPUT); pinMode(M2_IN2, OUTPUT);
  pinMode(M3_IN1, OUTPUT); pinMode(M3_IN2, OUTPUT);

  ledcSetup(pwmChannel1, freq, resolution);
  ledcAttachPin(M1_EN, pwmChannel1);

  ledcSetup(pwmChannel2, freq, resolution);
  ledcAttachPin(M2_EN, pwmChannel2);

  ledcSetup(pwmChannel3, freq, resolution);
  ledcAttachPin(M3_EN, pwmChannel3);
}

void loop() {
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  Serial.print("Accel: ");
  Serial.print(ax); Serial.print(", ");
  Serial.print(ay); Serial.print(", ");
  Serial.print(az); Serial.print(" | Gyro: ");
  Serial.print(gx); Serial.print(", ");
  Serial.print(gy); Serial.print(", ");
  Serial.println(gz);

  if (ay > 10000) {
    motorForward(M1_IN1, M1_IN2);
    motorForward(M2_IN1, M2_IN2);
    motorForward(M3_IN1, M3_IN2);
    ledcWrite(pwmChannel1, 180);
    ledcWrite(pwmChannel2, 180);
    ledcWrite(pwmChannel3, 180);
  } else if (ay < -10000) {
    motorReverse(M1_IN1, M1_IN2);
    motorReverse(M2_IN1, M2_IN2);
    motorReverse(M3_IN1, M3_IN2);
    ledcWrite(pwmChannel1, 180);
    ledcWrite(pwmChannel2, 180);
    ledcWrite(pwmChannel3, 180);
  } else {
    stopMotor(M1_IN1, M1_IN2, pwmChannel1);
    stopMotor(M2_IN1, M2_IN2, pwmChannel2);
    stopMotor(M3_IN1, M3_IN2, pwmChannel3);
  }

  delay(200);
}

void motorForward(int in1, int in2) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void motorReverse(int in1, int in2) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void stopMotor(int in1, int in2, int pwmChannel) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  ledcWrite(pwmChannel, 0);
}
