#include <Keypad.h>


const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad
const byte maxInput = 4;
const String pass = "1409";

//keymap defines the key pressed according to the row and columns just as appears on the keypad
int count = 0;
String input = "";
boolean bloqueado = true;
char keymap[numRows][numCols]= 
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'B'}, 
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

//Code that shows the keypad connections to the arduino terminals
byte rowPins[numRows] = {9,8,7,6}; //Rows 0 to 3
byte colPins[numCols]= {5,4,3,2}; //Columns 0 to 3

//initializes an instance of the Keypad class
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

void setup()
{
Serial.begin(9600);
pinMode(13, OUTPUT);
}

//If key is pressed, this key is stored in 'keypressed' variable
//If key is not equal to 'NO_KEY', then this key is printed out
//if count=17, then count is reset back to 0 (this means no key is pressed during the whole keypad scan process
void loop()  {
  char keypressed = myKeypad.getKey();
  
  if ( count >= maxInput ){
    input = "";
    count = 0;
  }
  
  if (keypressed != NO_KEY)  {
    if (keypressed == '#' ){
      input = "";
      count = 0;
      return;
    }
    count += 1;   
    input = input + keypressed ;
    Serial.println(input);
  }
  
  if ( input == pass ) {
    if ( bloqueado == true ) {
      Serial.println("Desbloqueado");
      digitalWrite(13, HIGH);
      bloqueado = false; 
    }
    else {
      Serial.println("Bloqueado");
      digitalWrite(13, LOW);
      bloqueado = true; 
    }       
    input = "";
  }
}

