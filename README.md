# 🤖 Human Detection Security Robot
### 🔍 PIR + Ultrasonic Scanning Robot using Arduino + Servo + LCD

## 📌 Project Description
This project is a smart security robot that continuously scans its surroundings using a servo motor and detects:

✅ Human presence using a PIR sensor  
✅ Distance using an Ultrasonic Sensor  
✅ Alerts with Buzzer + LEDs  
✅ Shows real-time status on a 16x2 I2C LCD

Useful for **home security**, **intruder detection**, **surveillance**, and **robotics learning**.

---

## ⭐ Features
- Human detection (PIR sensor)
- Distance measurement (0–200 cm)
- LCD display for live updates
- Servo motor auto-scanning 0° → 180°
- Buzzer + LED Alerts
- Compact & beginner friendly build

---

## 🧩 Components Required

| Component | Qty | Description |
|----------|:---:|-------------|
| Arduino UNO | 1 | Main Controller |
| HC-SR04 Ultrasonic Sensor | 1 | Distance sensor |
| PIR Motion Sensor | 1 | Detects human movement |
| SG90 / MG90 Servo Motor | 1 | Rotational scanning |
| 16×2 LCD + I2C Module | 1 | Display readings |
| Red, Green, Yellow LEDs | 3 | Alert indicators |
| Buzzer | 1 | Alarm |
| Jumper Wires | — | Connections |

---

## 🔌 Pin Configuration (Wiring)

| Module | Arduino Pin |
|--------|-------------|
| Ultrasonic TRIG | D9 |
| Ultrasonic ECHO | D10 |
| PIR Sensor | D8 |
| Servo Motor Signal | D6 |
| Yellow LED | D2 |
| Green LED | D3 |
| Red LED | D4 |
| Buzzer | D5 |
| LCD SDA | A4 |
| LCD SCL | A5 |

📌 *Optional:* External 5V power recommended for servo to prevent jitter.

---

## 🧠 Working Principle
1️⃣ Servo sweeps the field from **0° → 180° → 0°**  
2️⃣ Ultrasonic sensor measures distance at each angle  
3️⃣ PIR detects human motion  
4️⃣ Components react:
- ✅ Object detected → Green LED ON
- 🚨 Human detected → Red LED + Buzzer + LCD Alert  
5️⃣ LCD shows:
- Current angle of scanning
- Detected distance in cm

---

## 🖥️ Output Display on LCD
| Condition | LCD Message | Action |
|----------|-------------|--------|
| Idle Scanning | Angle + Distance | Only green LED if object detected |
| Human Detected | HUMAN DETECTED! | Red LED + Buzzer ON |

---

## 📸 Screenshots / Demo Output  
![t](https://github.com/user-attachments/assets/c1cd4a43-b61d-44f1-a416-790096318291)



https://github.com/user-attachments/assets/56f9ac28-0171-4dd6-9682-65e109e57503


## 👤 Author
**Ayush Pandey**  
Robotics & Trading Enthusiast  

### 🌍 Connect with me:
- Instagram: https://instagram.com/ayushk2s  
- X (Twitter): https://x.com/ayushk2s  
- Threads: https://threads.net/ayushk2s  

---

## ⭐ Support & Contribution
If you like this project ❤️  
📌 Give a ⭐ on GitHub  
📌 Fork & contribute 🚀  
📌 Share with the community 🤝
