# Swordfight
An ESP32, a Xiao, and two MPU6040s. Swinging, clashing, and hitting makes the swords react.

<img width="6090" height="1649" alt="IMG_7681" src="https://github.com/user-attachments/assets/21b0fd78-d26e-4448-8050-42fb9201b96e" />


## Build/Hardware Overview:
The ESP32/RP2040 devboard is under the hilt on the grip, with wires connecting it to two batteries on top of the hilt, with the MPUs on the base of the blade to detect motion. The LED strip runs on the blade in a straight line, and wired to the devboard. A button rests close to the devboard for turning off the sword.

<img width="4519" height="6260" alt="IMG_7685" src="https://github.com/user-attachments/assets/ce4a50ee-0c2e-45f2-a8b4-b9e7f7be8f86" />
<img width="2630" height="4677" alt="IMG_7686 Background Removed" src="https://github.com/user-attachments/assets/364fbc0d-0a4d-4821-8533-2b7467827638" />
<img width="6088" height="3425" alt="IMG_7683" src="https://github.com/user-attachments/assets/84a4650b-36f0-4f30-9030-f9e2e65c4665" />

# WIRING INFORMATION: 


## Behavior/Programming:
The sword has an LED strip which displays different light depending on what is going on, has an MPU sensor to detect how fast it is going. The MPU sensor runs two different checks to detect something, rotation and acceleration. If the sword is rotating really fast and is moving a ton, the MPU will detect that and classify it for a swing. A simmilar process happens for detecting sudden stops.



## Light Behavior Overview:
The LEDs in the sword always have a gradient, and depending on how fast the sword is moving, the cycle moves faster. This is really noticable when you swing it. Additionally, if the sword has momentum and suddenly comes to a stop, it will flash white, indicating it hit something.

<img width="4231" height="4145" alt="IMG_7684" src="https://github.com/user-attachments/assets/621af47f-1d43-4794-b41c-6107c8def067" />


## Poster:

<img width="1414" height="2000" alt="3 ESP32s, 2 swords + 1 hub  you swing, you clash, the hub keeps score" src="https://github.com/user-attachments/assets/4a2db413-d683-4e40-a210-a28471e4c345" />

