# LiveVitals - IoT Health Monitor Device

This project is an **IoT-based health monitoring system** developed using **NodeMCU (ESP8266)** and **Arduino IDE**. The system monitors **heart rate (BPM)** and **body temperature**, displays the data on an I2C LCD screen, and transmits it to **ThingSpeak** for remote monitoring and analysis.

## 💡 Features

- Real-time monitoring of:
  - **Heart Rate (BPM)** using a pulse sensor
  - **Body Temperature** using an LM35 temperature sensor
- Live data displayed on a **16x2 I2C LCD**
- Sends data to **ThingSpeak** every 10 seconds
- Wi-Fi enabled for wireless transmission

---

## 🛠️ Hardware Requirements

- NodeMCU (ESP8266)
- LM35 Temperature Sensor
- Pulse Sensor (analog)
- I2C 16x2 LCD Display
- Jumper Wires
- Breadboard
- Micro USB Cable
- Wi-Fi Connection

---

## 🔌 Pin Connections

| Component         | NodeMCU Pin |
|------------------|-------------|
| LM35 Sensor       | D4 (GPIO2)  |
| Pulse Sensor      | A0          |
| I2C LCD (SDA/SCL) | D2 (SDA), D1 (SCL) |

---

## 📡 ThingSpeak Setup

1. Create an account on [ThingSpeak](https://thingspeak.com/)
2. Create a new channel with at least **2 fields**:
   - Field 1: Heart Rate (BPM)
   - Field 2: Temperature (°C)
3. Note your **Channel ID** and **Write API Key**
4. Replace them in the code:
   ```cpp
   const unsigned long THINGSPEAK_CHANNEL_ID = YOUR_CHANNEL_ID;
   const char* THINGSPEAK_API_KEY = "YOUR_API_KEY";

---

## 🔐 Wi-Fi Configuration

Replace the below lines in the code with your Wi-Fi credentials:

```cpp
const char* WIFI_SSID = "Your_SSID";
const char* WIFI_PASSWORD = "Your_Password";
```

---

## 💻 Software Requirements

### Arduino IDE  
Make sure you have the Arduino IDE installed.

### ESP8266 Board Manager  
Install the ESP8266 Board Manager in the Arduino IDE.

### Required Libraries
- `ESP8266WiFi.h`
- `ThingSpeak.h`
- `Wire.h`
- `LiquidCrystal_I2C.h`

### 📦 To Install Libraries
1. Open Arduino IDE.
2. Go to **Sketch > Include Library > Manage Libraries**.
3. Search for each of the above libraries and install them as needed.

---

## 🚀 How It Works

1. **NodeMCU connects to Wi-Fi.**
2. **It reads analog data** from the pulse sensor and LM35.
3. **Converts analog data** to meaningful BPM and temperature values.
4. **Displays the data** on the LCD screen.
5. **Sends the data** to ThingSpeak every 10 seconds.
6. **View the data online** in graphs or **download it** from your ThingSpeak channel.

---

## 📷 Sample Output

### 🖥️ LCD Display:
BPM: 78
TMP (C): 36.5

### 📟 Serial Monitor:
BPM: 78
Tmp(C): 36.5
Channel update successful!!

---

## 📌 Future Improvements

- Integrate with mobile notifications (e.g., via Blynk or Twilio)
- Add SPO2 sensor for oxygen saturation
- Add data logging feature (e.g., SD card)
- Use battery power for portability

---

## 🧑‍💻 Developed By

**Harshvardhan Singh Bisht**  
Computer Science Undergraduate

---

## 📄 License

This project is open-source under the [MIT License](https://opensource.org/licenses/MIT).