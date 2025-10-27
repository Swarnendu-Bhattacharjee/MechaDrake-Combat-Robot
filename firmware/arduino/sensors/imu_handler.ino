// imu_handler.ino - read IMU via I2C and print orientation (placeholder)
#include <Wire.h>

void setup(){
  Wire.begin();
  Serial.begin(115200);
}

void loop(){
  // Placeholder: implement IMU driver (e.g., MPU6050)
  Serial.println("IMU: 0,0,0");
  delay(200);
}
