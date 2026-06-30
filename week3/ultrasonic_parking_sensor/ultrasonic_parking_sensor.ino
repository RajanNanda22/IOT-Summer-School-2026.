/*
  Ultrasonic Parking Sensor
  HC-SR04 Distance Alert System
  Uses millis() for non-blocking timing
*/

#define TRIG_PIN 9
#define ECHO_PIN 10

#define GREEN_LED 2
#define YELLOW_LED 3
#define RED_LED 4

#define BUZZER 5

unsigned long previousBuzzerMillis = 0;
unsigned long previousFlashMillis = 0;

bool buzzerState = false;
bool flashState = false;

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  pinMode(BUZZER, OUTPUT);
}

void loop() {

  // Trigger ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  // Distance formula
  float distance = (duration * 0.034) / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm - ");

  unsigned long currentMillis = millis();

  // SAFE (>50 cm)
  if (distance > 50) {

    Serial.println("SAFE");

    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);

    digitalWrite(BUZZER, LOW);

  }

  // CAUTION (20–50 cm)
  else if (distance > 20 && distance <= 50) {

    Serial.println("CAUTION");

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);

    if (currentMillis - previousBuzzerMillis >= 500) {
      previousBuzzerMillis = currentMillis;
      buzzerState = !buzzerState;
      digitalWrite(BUZZER, buzzerState);
    }

  }

  // WARNING (10–20 cm)
  else if (distance >= 10 && distance <= 20) {

    Serial.println("WARNING");

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);

    if (currentMillis - previousBuzzerMillis >= 200) {
      previousBuzzerMillis = currentMillis;
      buzzerState = !buzzerState;
      digitalWrite(BUZZER, buzzerState);
    }

  }

  // DANGER (<10 cm)
  else {

    Serial.println("STOP!");

    digitalWrite(BUZZER, HIGH);

    if (currentMillis - previousFlashMillis >= 100) {

      previousFlashMillis = currentMillis;

      flashState = !flashState;

      digitalWrite(GREEN_LED, flashState);
      digitalWrite(YELLOW_LED, flashState);
      digitalWrite(RED_LED, flashState);
    }

  }

}
