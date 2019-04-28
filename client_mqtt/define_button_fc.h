/* define_button_ps.h
   tari@Shinchoku_Home122d

   28 APRIL 31 HEISEI
*/

void updateButton(void);
void sendMqtt(int);
//DEFINE number_pin
#define BUTTON_A 25
#define BUTTON_B 26
#define BUTTON_LEFT 32
#define BUTTON_RIGHT 33
#define BUTTON_START 27


const char* topic = "test";     // 送信先のトピック名
const char* subtopic = "test";  //受信するトピック名


void init_pin() {
  pinMode(BUTTON_A, INPUT);
  pinMode(BUTTON_B, INPUT);
  pinMode(BUTTON_LEFT, INPUT);
  pinMode(BUTTON_RIGHT, INPUT);
  pinMode(BUTTON_START, INPUT);
}

void updateButton()
{
  if (digitalRead(BUTTON_A))
  {
    sendMqtt(1);
  }
  else if (digitalRead(BUTTON_B))
  {
    sendMqtt(2);
  }
  else if (digitalRead(BUTTON_LEFT))
  {
    sendMqtt(3);
  }
  else if (digitalRead(BUTTON_RIGHT))
  {
    sendMqtt(4);
  }
  else if (digitalRead(BUTTON_START))
  {
    sendMqtt(5);
  }
}

void sendMqtt(int button_pushed)
{
  Serial.println("PUSHED BUTTON NUMBER:" + button_pushed);
  if (mqttClient.connected())
  {
    switch (button_pushed)
    {
      case 1:
        mqttClient.publish(topic, "1_fc");
        break;
      case 2:
        mqttClient.publish(topic, "2_fc");
        break;
      case 3:
        mqttClient.publish(topic, "3_fc");
        break;
      case 4:
        mqttClient.publish(topic, "4_fc");
        break;
      case 5:
        mqttClient.publish(topic, "5_fc");
        break;
      default:
        break;
    }
  }
}
