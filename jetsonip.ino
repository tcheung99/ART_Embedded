/* This sketch waits for incoming serial data to be present
   and then sends a message serially.
   
   After Serial.println() is a call to Serial.read() to remove
   the received byte from the input queue. If you send more than 
   one byte to the Arduino, you'll get more than one response sent
   back at you.
*/
#include <LiquidCrystal.h>
#define rs 12
#define en 11
#define d4 5
#define d5 4
#define d6 3
#define d7 2
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
}

void loop()
{
  char incoming_byte[2];
  int i = 1;
  int cond = 0;
  while(Serial.available()>0){
    if (i==1){
      lcd.setCursor(0,0);
      lcd.clear();
    }
    
    while (cond != 1){
      if (incoming_byte[0]!=Serial.read()){
        incoming_byte[1] = Serial.read();
        cond = cond + 1;
      }
      else{
        incoming_byte[0] = Serial.read();
        cond = 0;
      }
    }
    lcd.print(incoming_byte[0]);
    lcd.setCursor(i,0);
    lcd.print(incoming_byte[1]);
    lcd.setCursor(i,1);
    i++;
  }
  delay(30);
  /*if (Serial.available() > 0)
  {
    int i = Serial.read();
    lcd.print(i,DEC);
    delay(1000);
    lcd.clear();  
  }*/
}
