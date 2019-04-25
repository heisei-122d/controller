#include <WiFi.h>
#include <PubSubClient.h>
#include "client_mqtt_config_network.h"


const char* topic = "test";     // 送信先のトピック名
const char* subtopic = "test";  //受信するトピック名
char* payload;                   // 送信するデータ


const int SW_BA = 34;
const int SW_BB = 35;
const int SW_BX = 32;
const int SW_BY = 33;
const int SW_BU = 34;
const int SW_BD = 35;
const int SW_BL = 32;
const int SW_BR = 33;
const int SW_BV = 32;
const int SW_BM = 33;
volatile int incomingByte = 0;
volatile int previousByte = 0;

void setup() {
    Serial.begin(38400);



    pinMode(SW_RED, INPUT);
    pinMode(SW_BLUE, INPUT);
    pinMode(SW_YELLOW, INPUT);
    pinMode(SW_GREEN, INPUT);
}

void loop() {
    // 送信処理 topic, payloadは適宜
    payload = "payload";
    //mqttClient.publish(topic, payload);
    updateButton();
    // WiFi
    if ( WiFi.status() == WL_DISCONNECTED ) {
        connectWiFi(); 
    }
    // MQTT
    if ( ! mqttClient.connected() ) {
        connectMqtt();
    }
    mqttClient.loop();  

}
/**
 * Interrupts
 */
void updateButton(){
  if(Serial.available() > 0) {
    previousByte = incomingByte;
    incomingByte = Serial.read();
    Serial.println(incomingByte);
    if(incomingByte != previousByte){
      if(incomingByte == 0x00 || incomingByte == '0') itrRed();
      else if(incomingByte == 0x01 || incomingByte == '1') itrBlue();
      else if(incomingByte == 0x02 || incomingByte == '2') itrYellow();
      else if(incomingByte == 0x03 || incomingByte == '3') itrGreen();
      //delay(1000);
    }
  }
}
void itrRed(){
  Serial.println("SEND 0");
  if(mqttClient.connected()){
    mqttClient.publish(topic, "0");
  }
}
void itrBlue(){
  Serial.println("SEND 1");
  if(mqttClient.connected()){
    mqttClient.publish(topic, "1");
  }
}
void itrGreen(){
  Serial.println("SEND 2");
  if(mqttClient.connected()){
    mqttClient.publish(topic, "2");
  }
}
void itrYellow(){
  Serial.println("SEND 3");
  if(mqttClient.connected()){
    mqttClient.publish(topic, "3");
  }
}