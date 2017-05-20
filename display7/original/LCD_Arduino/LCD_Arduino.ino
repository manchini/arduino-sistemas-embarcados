#include <LiquidCrystal.h>

int sensorPin0 = A0;
int sensorPin1 = A1;
int v_A0;
int v_A1;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  //Inicia LCD tamanho 16x2
  lcd.begin(16, 2);
  Serial.begin(9600);
 
}

void loop() {

  lcd.setCursor(0, 0);
  lcd.print(Serial.readString());

  v_A0 = analogRead(sensorPin0);
  lcd.setCursor(0, 1);
  lcd.print(mapfloat(v_A0,0,1023,0,5));
  lcd.print("v");

  v_A1 = analogRead(sensorPin1);
  lcd.setCursor(7, 1);
  lcd.print((float(analogRead(v_A1))*5/(1023))/0.01);
  lcd.print("C");

  delay(100);
  
}





float mapfloat(long x, long in_min, long in_max, long out_min, long out_max)
{
 return (float)(x - in_min) * (out_max - out_min) / (float)(in_max - in_min) + out_min;
}

