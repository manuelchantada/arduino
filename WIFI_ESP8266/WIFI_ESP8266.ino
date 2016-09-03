#include <SoftwareSerial.h>
SoftwareSerial WF1(3, 2); // RX | TX

void setup()
  {  Serial.begin(115200);
     WF1.begin(115200);
  }

void loop()
  {  String B= "." ;
     if (WF1.available())
         { char c = WF1.read() ;
           Serial.print(c);
         }
     if (Serial.available())
         {  char c = Serial.read();
            WF1.print(c);
         }
   }
