/*
  Six-servo control for Arduino UNO
  M1..M6 signal wires -> Arduino digital pins 2..7 respectively

  NOTES:
  - Servos are powered from the battery. Battery negative MUST be connected
    to Arduino GND (common ground).
*/

#include <Servo.h>

const uint8_t NUM_SERVOS = 6;

// M1, M2, M3, M4, M5, M6 -> pins 2, 3, 4, 5, 6, 7
const uint8_t SERVO_PINS[NUM_SERVOS] = {2, 3, 4, 5, 6, 7};

const int HOME_ANGLE = 90;
const int MIN_ANGLE  = 0;
const int MAX_ANGLE  = 180;
const int STEP_DELAY = 15;   // ms per degree (higher = slower, smoother)

Servo servos[NUM_SERVOS];
int currentAngle[NUM_SERVOS];

// Move one servo smoothly to a target angle
void moveServo(uint8_t index, int target) {
  target = constrain(target, MIN_ANGLE, MAX_ANGLE);
  int step = (target > currentAngle[index]) ? 1 : -1;

  while (currentAngle[index] != target) {
    currentAngle[index] += step;
    servos[index].write(currentAngle[index]);
    delay(STEP_DELAY);
  }
}

void homeAll() {
  for (uint8_t i = 0; i < NUM_SERVOS; i++) {
    moveServo(i, HOME_ANGLE);
  }
}

// Sweep each servo 90 -> 45 -> 135 -> 90, one after another
void demoSweep() {
  for (uint8_t i = 0; i < NUM_SERVOS; i++) {
    moveServo(i, 45);
    moveServo(i, 135);
    moveServo(i, HOME_ANGLE);
    delay(200);
  }
}

void setup() {
  for (uint8_t i = 0; i < NUM_SERVOS; i++) {
    servos[i].attach(SERVO_PINS[i]);
    currentAngle[i] = HOME_ANGLE;
    servos[i].write(HOME_ANGLE);
    delay(200);   // stagger start-up to limit inrush current
  }
  delay(1000);
}

void loop() {
  demoSweep();
  delay(1000);
}
