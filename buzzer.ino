#include <SoftwareSerial.h>

SoftwareSerial bluetooth(8, 9); // 8번 TX, 9번 RX
int buttonA = 4;
int buttonB = 3;
int piezo = 11;
int numTones = 3;
int tones[] = {261, 294, 330};
int tones2[] = {330, 294, 261};
void setup()

{
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(buttonA, INPUT_PULLUP);
  pinMode(buttonB, INPUT_PULLUP);
  pinMode(5, OUTPUT); // BUZZER OUTPUT
  
}

void loop()
{
  if(bluetooth.available()){
     char var = bluetooth.read();
     if(var == '4'){
      
        for(int i=0; i<numTones;i++){
          tone(piezo, tones[i]);
          delay(1000);    
        }
        
        noTone(piezo);
     }
     else if(var == '3'){
        for(int i=0; i<numTones;i++){
          tone(piezo, tones2[i]);
          delay(1000);    
        }
        noTone(piezo);
     }
   }


  if (digitalRead(buttonA) == LOW){
      Serial.write("Send Signal A");
      bluetooth.println(buttonA);   
      delay(1000); 
  }

  if (digitalRead(buttonB) == LOW){
      Serial.write("Send Signal B");
      bluetooth.println(buttonB);   
      delay(1000); 
  }
}
