// weapon_actuator.ino - basic servo actuator with safety
#include <Servo.h>
Servo weapon;
const int SERVO_PIN = 6;
const int SAFETY_PIN = 7; // must be HIGH to allow weapon actuation

void setup(){
  weapon.attach(SERVO_PIN);
  pinMode(SAFETY_PIN, INPUT_PULLDOWN);
  Serial.begin(115200);
}

void loop(){
  if (digitalRead(SAFETY_PIN) == HIGH && Serial.available()){
    String cmd = Serial.readStringUntil('\n');
    if (cmd == "FIRE"){
      weapon.write(0); delay(200); weapon.write(90);
      Serial.println("FIRED");
    }
  }
}
