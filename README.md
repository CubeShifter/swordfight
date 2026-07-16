# Swordfight
An ESP32, a Xiao, and two MPU6040s. Swinging, clashing, and hitting makes the swords react.

<img width="6090" height="1649" alt="IMG_7681" src="https://github.com/user-attachments/assets/21b0fd78-d26e-4448-8050-42fb9201b96e" />


## Build/Hardware Overview:
The ESP32/RP2040 devboard is under the hilt on the grip, with wires connecting it to two batteries on top of the hilt, with the MPUs on the base of the blade to detect motion. The LED strip runs on the blade in a straight line, and wired to the devboard. A button rests close to the devboard for turning off the sword.

<img width="4519" height="6260" alt="IMG_7685" src="https://github.com/user-attachments/assets/ce4a50ee-0c2e-45f2-a8b4-b9e7f7be8f86" />
<img width="2630" height="4677" alt="IMG_7686 Background Removed" src="https://github.com/user-attachments/assets/364fbc0d-0a4d-4821-8533-2b7467827638" />
<img width="6088" height="3425" alt="IMG_7683" src="https://github.com/user-attachments/assets/84a4650b-36f0-4f30-9030-f9e2e65c4665" />

# WIRING INFORMATION: 
Board,Pin,Connects To,Wire From
Sword ESP32 DevKit V1,3V3,HW-123 VCC,Power
Sword ESP32 DevKit V1,GND,HW-123 GND,Ground
Sword ESP32 DevKit V1,GND,WS2812B GND,Ground
Sword ESP32 DevKit V1,D21,HW-123 SDA,I2C data
Sword ESP32 DevKit V1,D22,HW-123 SCL,I2C clock
Sword ESP32 DevKit V1,D5,WS2812B DIN,LED data
Sword ESP32 DevKit V1,VIN,Battery pack + (via 2 holders in series),Board power
Sword ESP32 DevKit V1,GND,Battery pack -,Board power ground
WS2812B,5V,"Battery pack + (same 6V line, no diode - test at moderate brightness)",LED power
Sword Xiao RP2040,3V3,HW-123 VCC,Power
Sword Xiao RP2040,GND,HW-123 GND,Ground
Sword Xiao RP2040,GND,WS2812B GND,Ground
Sword Xiao RP2040,D4,HW-123 SDA,I2C data
Sword Xiao RP2040,D5,HW-123 SCL,I2C clock
Sword Xiao RP2040,D2,WS2812B DIN,LED data
Sword Xiao RP2040,5V,Battery pack + (via 2 holders in series),Board power
Sword Xiao RP2040,GND,Battery pack -,Board power ground
Sword 2 WS2812B,5V,"Battery pack + (same 6V line, no diode - test at moderate brightness)",LED power

## Behavior/Programming:
The sword has an LED strip which displays different light depending on what is going on, has an MPU sensor to detect how fast it is going. The MPU sensor runs two different checks to detect something, rotation and acceleration. If the sword is rotating really fast and is moving a ton, the MPU will detect that and classify it for a swing. A simmilar process happens for detecting sudden stops.



## Light Behavior Overview:
The LEDs in the sword always have a gradient, and depending on how fast the sword is moving, the cycle moves faster. This is really noticable when you swing it. Additionally, if the sword has momentum and suddenly comes to a stop, it will flash white, indicating it hit something.

<img width="4231" height="4145" alt="IMG_7684" src="https://github.com/user-attachments/assets/621af47f-1d43-4794-b41c-6107c8def067" />


## Poster:

<img width="1414" height="2000" alt="3 ESP32s, 2 swords + 1 hub  you swing, you clash, the hub keeps score" src="https://github.com/user-attachments/assets/4a2db413-d683-4e40-a210-a28471e4c345" />

