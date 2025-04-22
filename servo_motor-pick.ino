#include <Servo.h>

Servo servoX;
Servo servoY;
Servo servoZ;

int joyX1 = A0;
int joyY1 = A1;
int joyX2 = A2; // جويستيك الثاني (محور X فقط)

int currentX = 90;
int currentY = 90;
int currentZ = 90;

int deadZone = 4;
int stepDelay = 5;

void setup() {
  servoX.attach(9);
  servoY.attach(10);
  servoZ.attach(7);  // السيرفو الثالث

  servoX.write(currentX);
  servoY.write(currentY);
  servoZ.write(currentZ);
}

void loop() {
  int valX1 = analogRead(joyX1);
  int valY1 = analogRead(joyY1);
  int valX2 = analogRead(joyX2);  // قراءة الجويستيك الثاني

  int targetX = map(valX1, 0, 1023, 0, 180);
  int targetY = map(valY1, 0, 1023, 0, 180);
  int targetZ = map(valX2, 0, 1023, 0, 180);

  // حركة السيرفو X
  if (abs(targetX - currentX) > deadZone) {
    currentX += (targetX > currentX) ? 1 : -1;
    servoX.write(currentX);
  }

  // حركة السيرفو Y
  if (abs(targetY - currentY) > deadZone) {
    currentY += (targetY > currentY) ? 1 : -1;
    servoY.write(currentY);
  }

  // حركة السيرفو Z
  if (abs(targetZ - currentZ) > deadZone) {
    currentZ += (targetZ > currentZ) ? 1 : -1;
    servoZ.write(currentZ);
  }

  delay(stepDelay);
}
