#include <Servo.h>
#define THRESHOLD 250
#define EMG_PIN 0
#define SERVO_PIN 9
Servo SERVO_1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  SERVO_1.attach(SERVO_PIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(EMG_PIN);
    if(value>=THRESHOLD){
      SERVO_1.write(SERVO_1.read()+5);
    }
    else{
      SERVO_1.write(SERVO_1.read()-5);
    }    
    Serial.println(value);    
}
