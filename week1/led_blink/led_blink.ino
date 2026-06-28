```cpp
int blinkCount = 0;
int potPin = A0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int delayTime = map(analogRead(potPin), 0, 1023, 100, 1000);

  digitalWrite(LED_BUILTIN, HIGH);
  delay(delayTime);
  digitalWrite(LED_BUILTIN, LOW);
  delay(delayTime);

  blinkCount++;
  Serial.print("Blink count: ");
  Serial.println(blinkCount);
}
```
