#include <Keyboard.h>
 //the character we want to type, for two buttons, two keys
 char myKey2 = 'A';
 char myKey3 = 'B';

 // saving the state of the push button, default is high
 int buttonState2 = 1;
 int buttonState3 = 1;

 // time for avoinding noise
 int timeNoise = 10;
 
void setup() {
  // make pin 2 an 3 an input and turn on the
  // pullup resistor so it goes high unless
  // connected to ground:
  // button is on 2 and 3 pins
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  
  //start emulating keyboard
  Keyboard.begin();
  
  //start serial port for debug
  Serial.begin(9600);  
}

int simulateSwitch(int pinNumber, char keyPressed, int buttonState){
  //wait
    delay(timeNoise);
    //read it again
 
    //still different
    if(buttonState != digitalRead(pinNumber))
    {
      Serial.println("Stable state");
 
      //save on the buttonState variable
      buttonState = digitalRead(pinNumber);
 
      if(buttonState == LOW)
      {
        Keyboard.press(keyPressed);
        Serial.println("button pressed");
      }
      if(buttonState == HIGH)
      {
        Keyboard.release(keyPressed);
        Serial.println("button released");
      }
    }
    
    return buttonState;
}

 
void loop() {
 
  //something changed on button2
  if(buttonState2 != digitalRead(2))
  {
    buttonState2 = simulateSwitch(2, myKey2, buttonState2);
  }
  //something changed on button3
  if(buttonState3 != digitalRead(3))
  {
    buttonState3 = simulateSwitch(3, myKey3, buttonState3);
  }
}