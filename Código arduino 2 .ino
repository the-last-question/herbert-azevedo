#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <string.h>

SoftwareSerial serial(0,1); //(rx, tx)

String distancia;

LiquidCrystal lcd(2,3,4,5,6,7);

void setup()
{
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop()
{
  	if(Serial.available())
    {
    distancia = Serial.readString();
    Serial.flush();
    lcd.print(distancia);
    delay(2000);
    lcd.clear();
    }
}
