#include <WiFi.h>
#include <HTTPClient.h>

void connect_wifi()
{
	const char SSID[] = "122d-manabino";
	const char PASSWORD[] = "kennkunn";
	WiFi.begin(SSID, PASSWORD);
	Serial.print("無線LAN接続中");
	while (WiFi.status() != WL_CONNECTED) {
		Serial.print("*");
	delay(100);
	}
	Serial.println("接続完了");
}

bool post_to_slack(String msg)
{
	const String slack_hook_url = "https://hooks.slack.com/services/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";
  const String slack_username = "test_controller";
	const String slack_icon = ":稲穂:";
	const String slack_channel = "#random";
	const char* host = "hooks.slack.com";
	Serial.print("Connecting to ");
	Serial.println(host);

	// Use WiFiClient class to create TCP connections
	WiFiClientSecure client;
	const int port_https = 443;
	if (!client.connect(host, port_https)) {
	Serial.println("Connection failed :-(");
	return false;
	}

	// We now create a URI for the request

	Serial.print("Posting to URL: ");
	Serial.println(slack_hook_url);

	String postData = "payload={\"channel\": \"" + slack_channel + "\",  \"icon_emoji\": \"" + slack_icon + "\", \"username\": \"" + slack_username + "\", \"text\": \"" + msg + "\"}";

	// This will send the request to the server
	client.print(String("POST ") + slack_hook_url + " HTTP/1.1\r\n" +
				 "Host: " + host + "\r\n" +
				 "Content-Type: application/x-www-form-urlencoded\r\n" +
				 "Connection: close" + "\r\n" +
				 "Content-Length:" + postData.length() + "\r\n" +
				 "\r\n" + postData);
	Serial.println("Request sent");
	String line = client.readStringUntil('\n');
	Serial.printf("Response code was: ");
	Serial.println(line);
	if (line.startsWith("HTTP/1.1 200 OK")) {
	return true;
	} else {
	return false;
	}
}
