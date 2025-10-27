// bluetooth_remote.ino - placeholder for BLE or Classic SPP control
#include <BluetoothSerial.h>
BluetoothSerial SerialBT;

void setup(){
  Serial.begin(115200);
  SerialBT.begin("MechaDrakeCTRL");
}

void loop(){
  if (SerialBT.available()){
    String s = SerialBT.readStringUntil('\n');
    Serial.println("BT:" + s);
  }
}
