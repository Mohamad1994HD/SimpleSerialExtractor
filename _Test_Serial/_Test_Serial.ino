#include "SerialExtractor.h"

SerialExtractor ser;
void call_back(int a[], int sz)
{
  for (int i=0; i<sz; i++)
  {
    Serial.println(a[i]);
  }
}

void setup() {
  // put your setup code here, to run once:
  ser.SetCallBack(call_back);
  ser.SetDelimeter(",");
  ser.SetEndIndicator('#');
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  ser.Run();
}
