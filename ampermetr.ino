/*
 * калибровка выполняется замером тока 1А через датчик тока, на дисплее будет показываться число
 * данное число необходимо будет вписать в переменную k (14 номер строки) заменив значение 100 на калибровочную
 * после этого  калибровку на 0 и прошить заново (13 строка)
*/

#include "TM1637Display.h"
#define hollaOUT  PB2
#define CLK  PB3   // CLK 
#define DIO  PB4   // DIO 
TM1637Display display(CLK, DIO);

float I;
#define calibration 1 // 1 вкл калибровку 0 - выкл  
int k = 100; //ЗАМЕНИТЬ

void setup() {
  display.setBrightness(0x02);     
  delay(1000);    
}
void loop() {
  // put your main code here, to run repeatedly:
  if(calibration == 1){
    display.showNumberDec(analogRead(hollaOUT), false);
  }else{
    I = (float)analogRead(hollaOUT)/k;
    display.showNumberDecEx(I);
  }
  delay(250);
}
