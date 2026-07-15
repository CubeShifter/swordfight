// hub_receiver.ino
// Runs on the hub ESP32.
// Receives hit events from both swords, prints them to Serial.
// Scoring/combo logic goes in the marked section below once this
// basic receive path is confirmed working.

#include <esp_now.h>
#include <WiFi.h>
#include "../espnow_message.h"

void onDataRecv(const uint8_t *macAddr, const uint8_t *incomingData, int len) {
  HitMessage msg;
  memcpy(&msg, incomingData, sizeof(msg));

  Serial.print("Hit from sword ");
  Serial.print(msg.swordId);
  Serial.print(" | magnitude=");
  Serial.print(msg.impactMagnitude);
  Serial.print(" | t=");
  Serial.println(msg.timestampMs);

  // ---- SCORING LOGIC GOES HERE LATER ----
  // 1. buffer incoming hits briefly (~50ms window)
  // 2. if hits from both swordId 1 and 2 arrive within that window,
  //    treat as one clash — compare impactMagnitude, decide winner
  // 3. update combo/health state
  // 4. (later) push update to laptop dashboard over serial or WebSocket
}

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);

  // Print this board's own MAC address — you need this value to fill
  // into hubAddress[] in each sword_sender.ino
  Serial.print("Hub MAC address: ");
  Serial.println(WiFi.macAddress());

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW init failed");
    return;
  }

  esp_now_register_recv_cb(onDataRecv);

  Serial.println("Hub receiver ready.");
}

void loop() {
  // nothing needed here yet — all handled in onDataRecv callback
}
