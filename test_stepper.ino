#include <AccelStepper.h>

// Define stepper motor connections
#define stepPin 2
#define dirPin 3
#define enablePin 8

// Define microstepping pins (example, replace with your actual pins)
#define microstepPin1 9
#define microstepPin2 10
#define microstepPin3 11

// Create a new instance of the AccelStepper class
AccelStepper stepper(AccelStepper::DRIVER, stepPin, dirPin);

void setup() {
  // Set up the motor driver and pins
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW); // Enable the motor driver

  pinMode(microstepPin1, OUTPUT);
  pinMode(microstepPin2, OUTPUT);
  pinMode(microstepPin3, OUTPUT);

  // Initialize Serial Monitor
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Stepper Motor Testing");

  // Run the microstepping test
  microstepTest();
}

void loop() {
  // Your main loop code (if needed)
}

void setMicrostep(int microsteps) {
  switch (microsteps) {
    case 1:
      // Full step (Waveform: 1010)
      digitalWrite(microstepPin1, HIGH);
      digitalWrite(microstepPin2, LOW);
      digitalWrite(microstepPin3, HIGH);
      break;
    case 2:
      // Half step (Waveform: 1000, 1100, 0100, 0110, 0010, 0011, 0001, 1001)
      digitalWrite(microstepPin1, HIGH);
      digitalWrite(microstepPin2, LOW);
      digitalWrite(microstepPin3, LOW);
      break;
    case 4:
      // 1/4 step (Waveform: 1000, 1100, 0100, 0110, 0010, 0011, 0001, 1001)
      digitalWrite(microstepPin1, HIGH);
      digitalWrite(microstepPin2, HIGH);
      digitalWrite(microstepPin3, LOW);
      break;
    case 8:
      // 1/8 step (Custom waveform, adjust as needed)
      // Example: setSinusoidalWaveform();
      break;
    case 16:
      // 1/16 step (Trapezoidal waveform)
      // Example: setTrapezoidalWaveform();
      break;
    // Add cases for other microstep values
  }
}

void microstepTest() {
  // Test with different microstepping values
  for (int microsteps = 1; microsteps <= 16; microsteps *= 2) {
    setMicrostep(microsteps);

    Serial.print("Testing with ");
    Serial.print(microsteps);
    Serial.print(" microsteps: ");

    // Move the stepper motor forward for 200 steps
    for (int i = 0; i < 200; i++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(2000); // Adjust as needed
      digitalWrite(stepPin, LOW);
      delayMicroseconds(2000); // Adjust as needed
    }

    delay(1000); // Pause for 1 second
  }

  Serial.println("Microstepping test complete");
}
