#include <WiFi.h>
#include <PubSubClient.h>

#define LED_STATUS 23

// WiFi
const char ssid[] = "duck_wifi";
const char passwd[] = "duckduck";

// Pub/Sub
const char* mqttHost = "192.168.1.3"; // MQTTのIPかホスト名
const int mqttPort = 1883;       // MQTTのポート

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

/**
   Connect WiFi
*/
void connectWiFi()
{
  WiFi.begin(ssid, passwd);
  Serial.print("WiFi connecting...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }
  Serial.print(" connected. ");
  Serial.println(WiFi.localIP());
}
/**
   Connect MQTT
*/
void connectMqtt()
{
  mqttClient.setServer(mqttHost, mqttPort);
  //mqttClient.setCallback(callback);
  while ( ! mqttClient.connected() ) {
    Serial.println("Connecting to MQTT...");
    String clientId = "ESP32-" + String(random(0xffff), HEX);
    if ( mqttClient.connect(clientId.c_str()) ) {
      Serial.println("connected");
      //mqttClient.subscribe(subtopic);
    }
    delay(1000);
    randomSeed(micros());
  }
  digitalWrite(LED_STATUS, HIGH);
}

void initNetwork() {
  // Connect WiFi
  connectWiFi();

  // Connect MQTT
  connectMqtt();
}
