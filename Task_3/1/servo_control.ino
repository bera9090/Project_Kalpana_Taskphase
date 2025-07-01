#include <Servo.h>

Servo servo_9;
int angle = 0;

void setup() {
  Serial.begin(9600);
  servo_9.attach(9); 
  servo_9.write(0);
  Serial.println("Enter angle between 0 and 180:");
}

void loop() {
  if (Serial.available()) {
    angle = Serial.parseInt();  // Read integer value from Serial

    // Validate input
    if (angle >= 0 && angle <=180) {
      // Sweep from 0 to angle
      for (int pos = 0; pos <= angle; pos++) {
        servo_9.write(pos);
        delay(15);
      }

      // Sweep back from angle to 0
      for (int pos = angle; pos >= 0; pos--) {
        servo_9.write(pos);
        delay(15);
      }

      Serial.println("Done. Enter next angle:");
    } else {
      Serial.println("Invalid input. Enter value between 0 and 180.");
    }
  }
}
