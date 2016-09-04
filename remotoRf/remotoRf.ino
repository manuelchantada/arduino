void setup()
   {  Serial.begin (9600);
      pinMode (13, OUTPUT) ;
      pinMode (12, OUTPUT) ;
      for (int i = 7 ; i < 12 ; i++)
           pinMode(i, INPUT) ;
   }


void loop() 
   {   
      if (digitalRead(7) )     // Si hay dato validoM
         {  Serial.print("Valid trans. \t");
            if (digitalRead(8)) 
                Serial.print( "Boton C, pulsado");
            if (digitalRead(9)) 
                Serial.print( "Boton B, pulsado");
            if (digitalRead(10)) 
                Serial.print( "Boton A, pulsado");
            if (digitalRead(11))
                Serial.print( "Boton D, pulsado");
            Serial.println("\t");
            delay (1000) ;
         } 
   }
