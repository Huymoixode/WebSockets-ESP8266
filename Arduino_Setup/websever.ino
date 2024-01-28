#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WebSocketsClient.h> 
WebSocketsClient webSocket;
const char* ssid = "VAICUC"; //change your ssid
const char* password = "0326023936"; //your password
const char* ip_host = "192.168.1.7"; /Local IP 
const uint16_t port = 3000; //Port same with Server 
const int LED = 2;

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
  switch (type) {
    case WStype_DISCONNECTED:
      Serial.printf("[WSc] Disconnected!\n");
      break;
    case WStype_CONNECTED:
      {
        Serial.printf("[WSc] Connected to url: %s\n", payload);
      }
      break;
    case WStype_TEXT: // when client received message with TEXT
      //Serial.printf("[WSc] get text: %s\n", payload);
      if (strcmp((char*)payload, "da tick") == 0) {   //compare String 
        digitalWrite(LED, 0); //  "LED_ON" thì server sẽ bật LED
      } else if (strcmp((char*)payload, "chua tick") == 0) {
        digitalWrite(LED, 1); // "LED_OFF" thì server sẽ tắt LED
      }
      
      Serial.printf("%s",payload);
      Serial.println(); // Show message 
      break;
    // ...

    case WStype_BIN:when client received message with BIN
      Serial.printf("[WSc] get binary length: %u\n", length);
      break;
  }
}
void setup() {
  pinMode(LED, OUTPUT);
 Serial.setDebugOutput(true);

  Serial.begin(9600);
  Serial.println("ESP8266 Websocket Client");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  webSocket.begin(ip_host, port);
  webSocket.onEvent(webSocketEvent);
}
void loop() {
  webSocket.loop();
  webSocket.sendTXT("hello");
  delay(500);
  
}
