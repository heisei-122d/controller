#include "tari_network.h"
void setup() {
  Serial.begin(9600);
  connect_wifi();
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
}
