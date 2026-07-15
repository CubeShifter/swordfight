// sword_sender.ino
// Runs on each sword's ESP32/Xiao S3.
// Right now: sends a fake hit every 3 seconds so you can prove ESP-NOW
// connectivity works before the MPU6050 is wired in.
// Once the sensor is back in hand, replace the "FAKE HIT" block with
// real spike detection — the send call stays exactly the same.

#include <esp_now.h>
#include <WiFi.h>
#include <Wire.h>
#include "../espnow_message.h"

// ---- SET THIS: change to 1 or 2 depending on which sword this is ----
#define SWORD_ID 1

// ESP32-C3 Super Mini I2C pins (NOT the classic ESP32 default 21/22)
#define SDA_PIN 8
#define SCL_PIN 9

// LED strip data pin
#define LED_DIN_PIN 5

// ---- SET THIS: MAC address of the hub board ----
// Get it by flashing get_mac_address.ino to the hub first.
uint8_t hubAddress[] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};

esp_now_peer_info_t peerInfo;

void onDataSent(const uint8_t *macAddr, esp_now_send_status_t status) {
  Serial.print("Send status: ");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "OK" : "FAILED");
}

void setup() {
  Serial.begin(115200);

  // Must explicitly set pins on ESP32-C3 — Wire.begin() with no args
  // defaults to the classic ESP32's 21/22, which don't exist as SDA/SCL here.
  Wire.begin(SDA_PIN, SCL_PIN);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW init failed");
    return;
  }

  esp_now_register_send_cb(onDataSent);

  memcpy(peerInfo.peer_addr, hubAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add hub as peer");
    return;
  }

  Serial.println("Sword sender ready.");
}

void sendHit(float magnitude) {
  HitMessage msg;
  msg.swordId = SWORD_ID;
  msg.impactMagnitude = magnitude;
  msg.timestampMs = millis();

  esp_err_t result = esp_now_send(hubAddress, (uint8_t *) &msg, sizeof(msg));

  if (result == ESP_OK) {
    Serial.print("Sent hit, magnitude=");
    Serial.println(magnitude);
  } else {
    Serial.println("Send error");
  }
}

unsigned long lastFakeHit = 0;

void loop() {
  // ---- FAKE HIT (delete this block once MPU6050 is wired back in) ----
  if (millis() - lastFakeHit > 3000) {
    float fakeMagnitude = random(50, 100) / 10.0;  // random 5.0-10.0g
    sendHit(fakeMagnitude);
    lastFakeHit = millis();
  }
  // ---- END FAKE HIT ----

  // ---- REAL HIT DETECTION GOES HERE LATER ----
  // 1. read MPU6050 accel magnitude over I2C (Wire already begun on SDA_PIN/SCL_PIN above)
  // 2. if magnitude crosses threshold AND debounce window has passed:
  //      sendHit(magnitude);
  // 3. (later) drive WS2812B on LED_DIN_PIN for idle color / combo pulse / impact flash
}
