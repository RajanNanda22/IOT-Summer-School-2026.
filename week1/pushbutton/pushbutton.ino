int buttonstate =0;
const int LED = 3;

void setup()
{
  pinMode(2, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LED, LOW);
}

void loop()
{
  buttonstate = digitalRead(2);
  //for()
  while(buttonstate == HIGH){
    digitalWrite(LED,HIGH);
    delay(200);
    digitalWrite(LED,LOW);
    Serial.print(buttonstate);
    delay(100);
    
    buttonstate = digitalRead(2);
  }
}
