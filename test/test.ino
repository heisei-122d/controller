#include "tari_network.h"
void setup() {
  Serial.begin(9600);
  connect_wifi();
  pinMode(34, INPUT);
  pinMode(35, INPUT);
  pinMode(32, INPUT);
  pinMode(33, INPUT);
  pinMode(25, INPUT);
  pinMode(26, INPUT);
}

void loop() {
  String str;
  char tmp[50];
  int count = 0;
  int flag = 0;
  while (Serial.available() > 0) {
    tmp[count] = Serial.read();
    flag = 1;
    count++;
  }
  str = tmp;
  if (flag == 1) {
    post_to_slack(str);
  }
  button();
}

void button(){
  if(digitalRead(34)){
    post_to_slack("Wherever UART!!");
  }else if(digitalRead(35)){
    post_to_slack("Button B Pressed");
  }else if(digitalRead(32)){
    post_to_slack("Button X Pressed");
  }else if(digitalRead(33)){
    post_to_slack("Button Y Pressed");
  }else if(digitalRead(25)){
    post_to_slack("Button Menu Pressed");
  }else if(digitalRead(26)){
    post_to_slack("Button View Pressed");
  }
}
