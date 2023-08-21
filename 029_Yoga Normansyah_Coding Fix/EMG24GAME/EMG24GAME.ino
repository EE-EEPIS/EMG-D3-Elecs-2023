#include <Keyboard.h>
#define THRESHOLD 100
#define THRESHOLD2 100
#define EMG_PIN A0
#define EMG_PIN2 A1
void setup() {
  // put your setup code here, to run once:
  Keyboard.begin();         // Inisialisasi library Keyboard
  
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(EMG_PIN);
  int value2 = analogRead(EMG_PIN2);
  // Pemetaan sinyal EMG dari 0-1023 ke 0-255
  byte mappedValue = map(value, 0, 1023, 0, 255);
  byte mappedValue2 = map(value2, 0, 1023, 0, 255);
  if (mappedValue >= THRESHOLD) {
    Keyboard.press(KEY_LEFT_ARROW);   // Tombol panah kiri ditekan
    delay(100);                        // Tunda selama 100 ms
    Keyboard.release(KEY_LEFT_ARROW);  // Tombol panah kiri dilepas
  } else if (mappedValue2 >= THRESHOLD2) {
    Keyboard.press(KEY_RIGHT_ARROW);   // Tombol panah kanan ditekan
    delay(100);                         // Tunda selama 100 ms
    Keyboard.release(KEY_RIGHT_ARROW);  // Tombol panah kanan dilepas
  }    
  Serial.print("kiri = ");   
  Serial.print(mappedValue); 
  Serial.print(" ");   
  Serial.print("kanan = ");   
  Serial.println(mappedValue2);
  delay(50); 
}
