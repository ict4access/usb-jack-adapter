#include <Keyboard.h>
void setup() {
  // make pin 2 an 3 an input and turn on the
  // pullup resistor so it goes high unless
  // connected to ground:
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  
  if (digitalRead(2) == LOW) {
    // do nothing until pin 2 goes low
    // send the key code you want
    Keyboard.press(KEY_F12);
    delay(90);
  }
  
  if (digitalRead(3) == LOW) {
    Keyboard.press(KEY_RETURN);
    delay(90);
  }
  delay(100);
  Keyboard.releaseAll();
}
