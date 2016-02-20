# SimpleSerialExtractor
The main idea of SerialExtractor class to extract integer data sent through serial port to arduino. Since it's kind of tricky to extract that data and assure it's in correct form.For example you want to send number of pins to turn on, or angle for servo to rotate for,
on the serial monitor you can write 1:2:13#, which is the values 1,2,13 ended with end indicator in my example '#'
and separated by delimeter in my example ':' (colon).

