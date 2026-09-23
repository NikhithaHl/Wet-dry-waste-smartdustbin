Wet & Dry Waste Separator

📌 Project Overview

This project is an automatic wet and dry waste segregation system using Arduino.

The system detects the presence of waste using an ultrasonic sensor and checks its moisture level using a soil moisture sensor. Based on the moisture value, a servo motor directs the waste into the wet or dry waste section.

🎯 Objective

The main objective of this project is to automatically separate wet and dry waste with minimum human effort.

🔧 Components Used

- Arduino
- Ultrasonic Sensor (HC-SR04)
- Soil Moisture Sensor
- Servo Motor
- Jumper Wires
- Breadboard
- Power Supply

⚙️ Working Principle

1. The ultrasonic sensor detects whether waste is present.
2. When waste is detected within the specified distance, the soil moisture sensor measures its moisture level.
3. Multiple moisture readings are taken and averaged.
4. The Arduino compares the moisture value with a predefined threshold.
5. If the moisture value is above the threshold, the waste is classified as wet.
6. If the moisture value is below the threshold, the waste is classified as dry.
7. The servo motor rotates to the corresponding direction.
8. After sorting, the servo returns to its center position.

🔌 Sensor and Servo Connections

Component| Arduino Pin
Ultrasonic Trig| D12
Ultrasonic Echo| D11
Soil Moisture Sensor| A0
Servo Motor| D8

🧠 Decision Logic

Waste detected?
       ↓
   Yes
       ↓
Read moisture
       ↓
Calculate average
       ↓
Moisture > threshold?
    ↙ ↘
  Yes No
   ↓ ↓
Wet Waste Dry Waste
   ↓ ↓
Servo 170° Servo 10°
       ↘ ↙
        Servo 90°

💻 Arduino Code

The Arduino source code is available in the "Arduino_Code" folder.

📷 Project Images

Complete Project

"Complete Project" (Images/project.jpg)

Circuit

"Circuit" (Images/circuit.jpg)

📊 Output

The Serial Monitor displays the moisture percentage and the detected distance.

Example:

Humidity: 65% Distance: 8 cm ==> WET Waste

or

Humidity: 2% Distance: 8 cm ==> Dry Waste

🚀 Future Improvements

- Add multiple waste categories.
- Use a conveyor belt for automatic movement of waste.
- Add an LCD/OLED display.
- Add IoT monitoring.
- Improve moisture detection accuracy.
- Add a larger waste collection mechanism.

👩‍💻 Project

Wet & Dry Waste Separator

Built using Arduino, ultrasonic sensing, moisture sensing, and servo-based sorting.
