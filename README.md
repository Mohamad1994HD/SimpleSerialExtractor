# SimpleSerialExtractor
The main idea of SerialExtractor class to extract integer data sent through serial port to arduino. Since it's kind of tricky to extract that data and assure it's in correct form.For example you want to send number of pins to turn on, or angle for servo to rotate for,
on the serial monitor you can write 1:2:13X, which is the values 1,2,13 ended with end indicator in my example 'X'
and separated by delimeter in my example ':' (colon).

## Main functions  

* **SetCallBack(callback);** Takes a call back function (int a[], int size) as parameters
* **SetDelimeter(":");** Takes a const char* type as delimeters to segment the recieved data to integer values, default: ":"
* **SetEndIndicator('X');** Takes a character type as end indicator of the received data, default: '#'
* **Run();** The most important function in order to receive, fetch, segment the data from serial port

####Example:

```c 
#include "SerialExtractor.h"

SerialExtractor ser;
void callBack(int a[], int sz)
{
  for (int i=0; i<sz; i++)
  {
    Serial.println(a[i]);
  }
}

void setup() {
  // put your setup code here, to run once:
  ser.SetCallBack(callBack);
  ser.SetDelimeter(",");
  ser.SetEndIndicator('#');
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  ser.Run();
}
``` 
