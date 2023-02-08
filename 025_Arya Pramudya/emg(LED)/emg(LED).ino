int EMGPin = A1;
int EMGVal = 0;
int led = 13;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  EMGVal = analogRead(EMGPin);
  Serial.println(EMGVal);

  if (EMGVal >= 600)
  {
    digitalWrite(led, HIGH);
    count = 1;
    delay (1000);
  }
  else
  {
    digitalWrite(led, LOW);
    count = 0;
    delay (1000);
  }
}
