/* define_button_ps.h
 * K.A.I.GpioBlink@REMs
 * 
 * 3 APRIL 31 HEISEI
 */

#include <WiFi.h>
#include <PubSubClient.h>
#include "client_mqtt_config_network.h"
#include "define_button_xb.h"

const char* topic = "test";     // 送信先のトピック名
const char* subtopic = "test";  //受信するトピック名
char* payload;                   // 送信するデータ

void setup() {
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
		connectMqtt();
	}
	updateButton();
	mqttClient.loop();  
}

void updateButton()
{
	if(digitalRead(BUTTON_A))
	{
		sendMqtt(1);
	}
	else if (digitalRead(BUTTON_B))
	{
		sendMqtt(2);
	}
	else if (digitalRead(BUTTON_X))
	{
		sendMqtt(3);
	}
	else if (digitalRead(BUTTON_Y))
	{
		sendMqtt(4);
	}
	else if (digitalRead(BUTTON_UP))
	{
		sendMqtt(5);
	}
	else if (digitalRead(BUTTON_DOWN))
	{
		sendMqtt(6);
	}
	else if (digitalRead(BUTTON_LEFT))
	{
		sendMqtt(7);
	}
	else if (digitalRead(BUTTON_RIGHT))
	{
		sendMqtt(8);
	}
	else if (digitalRead(BUTTON_MENU))
	{
		sendMqtt(9);
	}
	else if (digitalRead(BUTTON_VIEW))
	{
		sendMqtt(10);
	}
}

void sendMqtt(int button_pushed)
{
	Serial.println("PUSHED BUTTON NUMBER:" + button_pushed);
	if(mqttClient.connected())
	{
		switch (button_pushed)
		{
			case 1:
				mqttClient.publish(topic, "A_XB");
				break;
			case 2:
				mqttClient.publish(topic, "B_XB");
				break;
			case 3:
				mqttClient.publish(topic, "X_XB");
				break;
			case 4:
				mqttClient.publish(topic, "Y_XB");
				break;
			case 5:
				mqttClient.publish(topic, "U_XB");
				break;
			case 6:
				mqttClient.publish(topic, "D_XB");
				break;
			case 7:
				mqttClient.publish(topic, "L_XB");
				break;
			case 8:
				mqttClient.publish(topic, "R_XB");
				break;
			case 9:
				mqttClient.publish(topic, "M_XB");
				break;
			case 10:
				mqttClient.publish(topic, "V_XB");
				break;
			default:
				break;
		}
	}
}
