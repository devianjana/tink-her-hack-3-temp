#include <Servo.h>

#define Trig 9               // Ultrasonic Trigger Pin
#define Echo 8              // Ultrasonic Echo Pin
#define LEFT_LIMIT_SWITCH 3   // Left limit switch pin
#define RIGHT_LIMIT_SWITCH 2  // Right limit switch pin
#define LEFT_SERVO_PIN 4     // Left Servo pin (sweeper)
#define RIGHT_SERVO_PIN 6     // Right Servo pin (sweeper)

Servo leftBroom;  // Left servo for broom
Servo rightBroom; // Right servo for broom

const int in21 = 7;   // Motor control pin 1
const int in22 = 10;  // Motor control pin 2
const int in23 = 13;  // Motor control pin 3
const int in24 = 12;  // Motor control pin 4
const int enA = 11;   // Motor enable pin A
const int enB = 5;    // Motor enable pin B (changed to pin 2)

void setup() {
    pinMode(Trig, OUTPUT);        // Set the ultrasonic Trig pin as output
    pinMode(Echo, INPUT);         // Set the ultrasonic Echo pin as input

    pinMode(LEFT_LIMIT_SWITCH, INPUT_PULLUP);  // Left limit switch
    pinMode(RIGHT_LIMIT_SWITCH, INPUT_PULLUP); // Right limit switch
    
    leftBroom.attach(LEFT_SERVO_PIN);  // Attach left servo
    rightBroom.attach(RIGHT_SERVO_PIN);  // Attach right servo

    leftBroom.write(0);  // Set broom to initial position
    rightBroom.write(0); // Set broom to initial position

    pinMode(in21, OUTPUT);
    pinMode(in22, OUTPUT);
    pinMode(in23, OUTPUT);
    pinMode(in24, OUTPUT);
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    bool leftPressed = digitalRead(LEFT_LIMIT_SWITCH) == LOW;  // Check left switch
    bool rightPressed = digitalRead(RIGHT_LIMIT_SWITCH) == LOW; // Check right switch

    if (leftPressed) {
        Serial.println("Left limit switch triggered! Sweeping...");
        sweepLeft();
        return;  // Skip other checks until sweep is done
    } 

    if (rightPressed) {
        Serial.println("Right limit switch triggered! Sweeping...");
        sweepRight();
        return;  // Skip other checks until sweep is done
    }

    // Ultrasonic sensor to detect obstacles ahead
    digitalWrite(Trig, HIGH);
    delayMicroseconds(10);  // Send pulse
    digitalWrite(Trig, LOW);

    unsigned int impulseTime = pulseIn(Echo, HIGH); // Measure pulse duration
    unsigned int distance_sm = impulseTime / 58;     // Convert pulse time to distance (cm)

    Serial.print("Distance: ");
    Serial.println(distance_sm);

    if (distance_sm > 25) {  // If obstacle is far away (more than 25 cm)
        moveForward();
    } else {  // If obstacle is nearby
        Serial.println("Obstacle detected! Turning...");
        turnRight();
    }

    delay(50);
}

// Move the robot forward
void moveForward() {
    digitalWrite(in21, LOW);
    digitalWrite(in22, HIGH);
    analogWrite(enA, 60);

    digitalWrite(in23, HIGH);
    digitalWrite(in24, LOW);
    analogWrite(enB, 70);
}

// Sweep with left servo
void sweepLeft() {
    stopAndReverse();  // Reverse a little bit first

    leftBroom.write(180);  // Sweep down with left broom
    delay(400);  // Wait while sweeping
    
    leftBroom.write(0);  // Reset broom position
    delay(400);  // Pause before moving again

    moveForward();  // Resume movement
}

// Sweep with right servo
void sweepRight() {
    stopAndReverse();  // Reverse a little bit first

    rightBroom.write(180);  // Sweep down with right broom
    delay(400);  // Wait while sweeping
    
    rightBroom.write(0);  // Reset broom position
    delay(400);  // Pause before moving again

    moveForward();  // Resume movement
}

// Stop and reverse the robot for a short time
void stopAndReverse() {
    // digitalWrite(in21, LOW);
    // digitalWrite(in22, LOW);
    // digitalWrite(in23, LOW);
    // digitalWrite(in24, LOW);
    // delay(400);

    digitalWrite(in21, HIGH);
    digitalWrite(in22, LOW);
    digitalWrite(in23, LOW);
    digitalWrite(in24, HIGH);
    analogWrite(enA, 100);
    analogWrite(enB, 100);
    delay(200);
    digitalWrite(in21, LOW);
    digitalWrite(in22, LOW);
    digitalWrite(in23, LOW);
    digitalWrite(in24, LOW);
}

// Turn Right
void turnRight() {
    digitalWrite(in21, HIGH);
    digitalWrite(in22, LOW);
    digitalWrite(in23, HIGH);
    digitalWrite(in24, LOW);
    analogWrite(enA, 100);
    analogWrite(enB, 100);
    delay(400);
}
