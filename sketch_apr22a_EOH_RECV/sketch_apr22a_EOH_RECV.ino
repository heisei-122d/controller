//#include <Keyboard.h>
//#include <SoftwareSerial.h>
//SoftwareSerial Serial_s(10, 11);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Keyboard.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  char keyBValue;
  if (Serial.available() > 0) {
    keyBValue = Serial.read();
    if (keyBValue == 'S') {
      //Keyboard.write('S');
    }else if(keyBValue == 'H'){
      //Keyboard.write('H');
    }
    delay(1000);
  }
}
