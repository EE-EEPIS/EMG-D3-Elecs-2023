#include <Keyboard.h>

int button1 = 2;
int button2 = 3;
char rightKey = KEY_RIGHT_ARROW;
char leftKey  = KEY_LEFT_ARROW;

char upKey = KEY_UP_ARROW;
char downKey  = KEY_DOWN_ARROW;

void setup() {
  // put your setup code here, to run once:
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  Keyboard.begin();
}
void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(button1)) {
    Keyboard.release(leftKey);
    Keyboard.press(upKey);
  }
  else if (digitalRead(button2)) {
    Keyboard.release(rightKey);
    Keyboard.press(downKey);
  }
  else {
    Keyboard.releaseAll();
  }
}
