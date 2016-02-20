#include "SerialExtractor.h"

SerialExtractor ser;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ser.SetDelimeter(":");
  ser.SetEndIndicator('#');
}

void loop() {
  int a[10]={0};
  int siz = 0;
    ser.TryReadSerial();
  
    if (ser.SERIAL_RESULT == SUCCESS){
     // Serial.println("SUCCESS");
      ser.extractInfo(a, siz);
      for (int i=0;i<siz; i++)
      {
        Serial.println(a[i]);
      }
    }
    
    delay(10);
}
