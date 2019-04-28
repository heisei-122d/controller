/* define_button_ps.h
 * K.A.I.GpioBlink@REMs
 * 
 * 3 APRIL 31 HEISEI
 */

#include <WiFi.h>
#include <PubSubClient.h>
#include "client_mqtt_config_network.h"
#include "define_button_fc.h"

char* payload;                   // 送信するデータ

void setup() {
  digitalWrite(LED_STATUS, HIGH);
  delay(2000);
  digitalWrite(LED_STATUS, LOW);
	Serial.begin(38400);
	initNetwork();
}

void loop()
{
	// 送信処理 topic, payloadは適宜
	payload = "payload";
	// WiFi
	if ( WiFi.status() == WL_DISCONNECTED )
	{
		connectWiFi(); 
	}
	// MQTT
	if ( ! mqttClient.connected() )
	{
    digitalWrite(LED_STATUS, LOW);
		connectMqtt();
	}
	updateButton();
	mqttClient.loop();  
}
