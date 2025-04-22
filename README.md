# 4DOF Robotic Arm Kit using Arduino UNO + Servo Motors

🎥 **Watch the tutorial:** [YouTube Shorts](https://youtube.com/shorts/wb3r6qS_1Ko?feature=share)

This project demonstrates how to control a 4 Degrees of Freedom (DOF) robotic arm using two joysticks and an Arduino UNO. The setup uses three servo motors for X, Y, and Z movement—each mapped to joystick input for smooth, real-time control.

---

## 🚀 Features

- Smooth movement with dead zone filtering  
- Real-time servo control using analog joystick input  
- Simple and beginner-friendly Arduino code  
- Expandable for more DOF or gripper control

---

## 🛠 Hardware Required

- Arduino UNO  
- 3x Servo Motors (SG90 or MG996R recommended)  
- 2x Analog Joysticks  
- Breadboard + Jumper Wires  
- 5V Power Supply (with sufficient current for servos)  
- 4DOF Robotic Arm Kit  

---

## 🔌 Wiring Overview

| Component | Arduino Pin |
|----------|-------------|
| Joystick 1 X-Axis | A0 |
| Joystick 1 Y-Axis | A1 |
| Joystick 2 X-Axis | A2 |
| Servo X (Base Rotation) | D9 |
| Servo Y (Shoulder Lift) | D10 |
| Servo Z (Elbow Movement) | D7 |

Ensure that the servo motors are powered properly, especially if you're using high-torque motors (external power source recommended).

---

## 🧠 Code Overview

The core logic reads analog values from the joysticks, maps them to servo angles (0-180°), and gradually moves each servo towards its target to ensure smooth motion.

```cpp
#include <Servo.h>

// Servo definitions and initial positions
Servo servoX, servoY, servoZ;
int currentX = 90, currentY = 90, currentZ = 90;

// Joystick pins
int joyX1 = A0, joyY1 = A1, joyX2 = A2;

// Motion tuning
int deadZone = 4;
int stepDelay = 5;

void setup() {
  servoX.attach(9);
  servoY.attach(10);
  servoZ.attach(7);
  servoX.write(currentX);
  servoY.write(currentY);
  servoZ.write(currentZ);
}

void loop() {
  int valX1 = analogRead(joyX1);
  int valY1 = analogRead(joyY1);
  int valX2 = analogRead(joyX2);

  int targetX = map(valX1, 0, 1023, 0, 180);
  int targetY = map(valY1, 0, 1023, 0, 180);
  int targetZ = map(valX2, 0, 1023, 0, 180);

  if (abs(targetX - currentX) > deadZone) currentX += (targetX > currentX) ? 1 : -1;
  if (abs(targetY - currentY) > deadZone) currentY += (targetY > currentY) ? 1 : -1;
  if (abs(targetZ - currentZ) > deadZone) currentZ += (targetZ > currentZ) ? 1 : -1;

  servoX.write(currentX);
  servoY.write(currentY);
  servoZ.write(currentZ);

  delay(stepDelay);
}
```

---

## 🧩 Next Steps

- Add a 4th DOF or gripper with another joystick axis or button control  
- Implement inverse kinematics for precise arm positioning  
- Add OLED/LED feedback for joystick direction or servo angles

---

## 📢 Connect

If you found this project helpful, don’t forget to like, comment, and subscribe on [YouTube](https://youtube.com/shorts/wb3r6qS_1Ko?feature=share)!

📸 Follow me on Instagram for more robotics content: [@nada_robotics](https://instagram.com/nada_robotics)  
Have questions? Feel free to DM or comment—I'm always excited to see your builds!

---

