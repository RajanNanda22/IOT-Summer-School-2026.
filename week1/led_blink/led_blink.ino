```cpp
int blinkCount = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);

  blinkCount++;
  Serial.print("Blink count: ");
  Serial.println(blinkCount);
}
```
