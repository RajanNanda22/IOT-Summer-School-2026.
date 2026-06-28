#include <Adafruit_LiquidCrystal.h>

int temp = 0;

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  lcd_1.begin(16, 2);
}

void loop()
{
  temp = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -20, 120);
  Serial.println(temp);
  lcd_1.setCursor(0, 0);
  lcd_1.print("Temp Value=");
  lcd_1.setCursor(12, 0);
  lcd_1.print(temp);
  delay(10);
}
