#include <SoftwareSerial.h>// import the serial library

SoftwareSerial Bt(10, 11); // RX, TX
const byte BTstatus = 8;
const int RELE1ON = 1;
const int RELE1OFF = 0;
const int RELE2ON = 2;
const int SETTIMER = 20;

boolean BTconectado = false;

int rele1=12;
int rele2=9; 
int BluetoothData; // the data given from Computer

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  Bt.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  pinMode(rele1,OUTPUT);
  pinMode(rele2,OUTPUT);
  digitalWrite(rele1,HIGH);
  digitalWrite(rele2,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if ( digitalRead(BTstatus)==LOW ) {
    digitalWrite(rele1,HIGH);
    digitalWrite(rele2,HIGH);
    digitalWrite(13, LOW);
    delay(100);
  }
  else {
    digitalWrite(13, HIGH);
    if ( Bt.available() ){
      BluetoothData=Bt.read();
      
      switch ( BluetoothData ){
        case RELE1ON :
          digitalWrite(rele1,LOW);
          Bt.println("  Rele1 ON");
          break;
    
        case RELE1OFF :
          digitalWrite(rele1,HIGH);
          Bt.println("  Rele1 OFF");
          break;
          
        case RELE2ON :
          digitalWrite(rele2,LOW);
          Bt.println("  Rele2 ON");
          break;
    
        case RELE2OFF :
          digitalWrite(rele2,HIGH);
          Bt.println("  Rele2 OFF");
          break;
          
        case SETTIMER :
          while ( 1 ){
            digitalWrite(13, LOW);
            delay(1000);
            digitalWrite(13, HIGH);
            if ( Bt.available() ){
              BluetoothData=Bt.read();
            }
          }
          
          Bt.println(BluetoothData);
          break;       
      }
     }
  }
    
  delay(100);// prepare for next data ...
}
