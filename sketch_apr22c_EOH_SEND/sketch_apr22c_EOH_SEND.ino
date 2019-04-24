#include <Keyboard.h>
void setup() {
  // put your setup code here, to run once:
  pinMode(13, INPUT);
  pinMode(12, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int keyBValue1= digitalRead(13);
  int keyBValue2= digitalRead(12);
  if (keyBValue1) {
    Keyboard.print('S');
  }else if(keyBValue2){
    Keyboard.print('H');
  }
}
