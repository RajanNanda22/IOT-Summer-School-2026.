const int RLED = 3;
const int GLED = 5;
const int BLED = 6;

const int buttonPin = 2;

unsigned long startTime;
unsigned long reactionTime;

void setup() {
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  pinMode(buttonPin, INPUT);

  Serial.begin(9600);
  randomSeed(analogRead(A0));

  Serial.println("Reaction Time Game");
  Serial.println("Wait for the GREEN LED and press the button!");
}

void loop(){
  //led off
  digitalWrite(RLED, LOW);
  digitalWrite(GLED, LOW);
  digitalWrite(BLED, LOW);

  Serial.println("\nNew Round Starting...");
  delay(2000);

  //random led blinking
  for (int i = 0; i < 10; i++) {

    int ledChoice = random(0, 3);
    int randomDelay = random(200, 1001);

    switch (ledChoice) {
      case 0:
        digitalWrite(RLED, HIGH);
        delay(randomDelay);
        digitalWrite(RLED, LOW);
        break;

      case 1:
        digitalWrite(BLED, HIGH);
        delay(randomDelay);
        digitalWrite(BLED, LOW);
        break;

      case 2:
        digitalWrite(GLED, HIGH);
        delay(randomDelay);
        digitalWrite(GLED, LOW);
        break;
    }
  }
    
  //add random delay
  delay(random(500, 2000));
  Serial.println("GO!");
  digitalWrite(GLED, HIGH);
  startTime = millis();
  
  //button press
  while (digitalRead(buttonPin) == HIGH) {
  }
  delay(20);
  //button release
  while (digitalRead(buttonPin) == LOW) {
  }

  reactionTime = millis() - startTime;
  digitalWrite(GLED, LOW);

  Serial.print("Reaction Time: ");
  Serial.print(reactionTime);
  Serial.println(" ms");

  delay(3000);
}
