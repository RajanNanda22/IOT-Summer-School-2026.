#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <ESP32Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo doorServo;

#define SERVO_PIN 18

// HC-05 wired to ESP32 UART2 (TX2=17 -> HC-05 RXD, RX2=16 <- HC-05 TXD)
#define HC05_RX 16
#define HC05_TX 17
HardwareSerial HC05(2);

const byte ROWS = 4, COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'}, {'4','5','6','B'},
  {'7','8','9','C'}, {'*','0','#','D'}
};
byte rowPins[ROWS] = {13, 12, 14, 27};
byte colPins[COLS] = {26, 25, 33, 32};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String userID = "", otp = "", inputOTP = "";
bool otpSent = false, doorOpen = false;
unsigned long otpStartTime = 0, doorOpenTime = 0;
const unsigned long OTP_TIMEOUT = 30000;
const unsigned long DOOR_HOLD = 3000;

// ---------- OTP ----------
String makeOTP() {
  String c = "";
  for (int i = 0; i < 6; i++) c += String(random(0, 9));
  return c;
}

void sendOTPBT(String code) {
  HC05.println("Your OTP: " + code);
}

// ---------- Door ----------
void unlockDoor() {
  Serial.println("ACCESS GRANTED - Door Unlocked");
  lcd.clear(); lcd.print("ACCESS GRANTED");
  doorServo.write(90);
  doorOpen = true;
  doorOpenTime = millis();
}

void updateDoor() {
  if (doorOpen && millis() - doorOpenTime >= DOOR_HOLD) {
    doorServo.write(0);
    doorOpen = false;
    logAttempt(true);
  }
}

// ---------- Reset / Logging ----------
void logAttempt(bool success) {
  Serial.println("----------------------");
  Serial.println(success ? "LOG: SUCCESS ENTRY" : "LOG: FAILED ENTRY");
  userID = ""; inputOTP = ""; otp = ""; otpSent = false;
  lcd.clear();
}

// ---------- Setup ----------
void setup() {
  Serial.begin(115200);
  HC05.begin(9600, SERIAL_8N1, HC05_RX, HC05_TX); // default HC-05 baud is 9600

  doorServo.attach(SERVO_PIN);
  doorServo.write(0);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0); lcd.print("Smart Door Lock");
  lcd.setCursor(0, 1); lcd.print("System Start");
  delay(1500);
  lcd.clear();

  Serial.println("System Ready");
}

// ---------- Loop ----------
void loop() {
  char key = keypad.getKey();
  updateDoor();

  if (doorOpen) return; // servo currently holding open, skip input handling

  // STEP 1: Enter ID
  if (!otpSent) {
    lcd.setCursor(0, 0); lcd.print("Enter ID (4 digit)");

    if (key && key >= '0' && key <= '9') {
      userID += key;
      lcd.setCursor(userID.length() - 1, 1); lcd.print("*");
      Serial.print("*");

      if (userID.length() == 4) {
        Serial.println("\nID Entered: " + userID);
        otp = makeOTP();
        Serial.println("OTP GENERATED: " + otp);
        sendOTPBT(otp);

        lcd.clear();
        lcd.setCursor(0, 0); lcd.print("OTP Sent!");
        lcd.setCursor(0, 1); lcd.print("Check Phone");

        otpSent = true;
        otpStartTime = millis();
        Serial.println("Enter OTP:");
      }
    }
  }

  // STEP 2: Enter OTP
  else {
    if (millis() - otpStartTime > OTP_TIMEOUT) {
      Serial.println("OTP EXPIRED!");
      lcd.clear(); lcd.print("OTP Expired");
      logAttempt(false);
      return;
    }

    lcd.setCursor(0, 0); lcd.print("Enter OTP:");

    if (key && key >= '0' && key <= '9') {
      inputOTP += key;
      lcd.setCursor(inputOTP.length() - 1, 1); lcd.print("*");
      Serial.print("*");

      if (inputOTP.length() == 6) {
        Serial.println("\nOTP ENTERED: " + inputOTP);

        if (inputOTP == otp) {
          unlockDoor(); // door auto-relocks + logs via updateDoor()/logAttempt()
        } else {
          Serial.println("ACCESS DENIED");
          lcd.clear(); lcd.print("ACCESS DENIED");
          logAttempt(false);
        }
      }
    }
  }
}
