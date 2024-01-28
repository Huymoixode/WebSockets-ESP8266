#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WebSocketsClient.h> 
WebSocketsClient webSocket;
const char* ssid = "Nhan Nhi"; //Đổi thành wifi của bạn
const char* password = "0326023936"; //Đổi pass luôn
const char* ip_host = "192.168.1.7"; //Đổi luôn IP host của PC nha
const uint16_t port = 3000; //Port thích đổi thì phải đổi ở server nữa
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
    case WStype_TEXT:
      //Serial.printf("[WSc] get text: %s\n", payload);
      if (strcmp((char*)payload, "da tick") == 0) {   //so sanh 2 chuoi ki tu
        digitalWrite(LED, 0); // Khi client phát sự kiện "LED_ON" thì server sẽ bật LED
      } else if (strcmp((char*)payload, "chua tick") == 0) {
        digitalWrite(LED, 1); // Khi client phát sự kiện "LED_OFF" thì server sẽ tắt LED
      }
      
      Serial.printf("%s",payload);
      Serial.println(); // Xuống dòng sau khi hiển thị tin nhắn
      break;
    // ...

    case WStype_BIN:
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
  // static bool isPressed = false;
  // if (!isPressed && digitalRead(BTN) == 0) { //Nhấn nút nhấn GPIO0
  //   isPressed = true;
  //   webSocket.sendTXT("BTN_PRESSED");
  // } else if (isPressed && digitalRead(BTN)) { //Nhả nút nhấn GPIO0
  //   isPressed = false;
  //   webSocket.sendTXT("BTN_RELEASE");
  // }
}