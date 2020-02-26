#include <Stepper.h> 

// Define connection pins:
#define buzzerPin 5
#define pirPin 2
#define ledPin 13

//Define the Motor inputpins
int in1Pin = 8;
int in2Pin = 9;
int in3Pin = 10;
int in4Pin = 11;
const int stepsPerRevolution = 2048;// Update the number of steps per revolution required for your motor
// Create a stepper object 
// Note: We are using 28BYJ-48 5VDC Stepper Motor, for this motor, we need to set wiring sequence to (1-3-2-4) instead of (1-2-3-4)
Stepper motor(stepsPerRevolution, in1Pin, in3Pin, in2Pin, in4Pin); 

// Create variables:
int val = 0;
bool motionState = false; // We start with no motion detected.

void setup() {
  // Configure the pins as input or output:
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  
  int user_speed=10;   // Read entered integer value and store it in a variable
  motor.setSpeed(user_speed);  // Set stepper motor speed to user defined speed

  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);
}

void loop() {
  for(int AngleDivision=0; AngleDivision<4; AngleDivision++){
      Serial.println("clockwise"); // print text on serial monitor
      motor.step(stepsPerRevolution/4); // rotate motor in clockwise direction for one revolution
      delay(500);
       for(int checkTime=0; checkTime<20;checkTime++){
          check();
       }
  }
  for(int AngleDivision=0; AngleDivision<4; AngleDivision++){
      Serial.println("clockwise"); // print text on serial monitor
      motor.step(-stepsPerRevolution/4); // rotate motor in clockwise direction for one revolution
      delay(500);
       for(int checkTime=0; checkTime<20;checkTime++){
          check();
       }
  }
}


//function to check the animal is there or not
void check(){
   // Read out the pirPin and store as val:
  val = digitalRead(pirPin);

  // If motion is detected (pirPin = HIGH), do the following:
  if (val == HIGH) {
    digitalWrite(ledPin, HIGH); // Turn on the on-board LED.
    alarm(500, 2000);  // Call the alarm(duration, frequency) function.
    delay(150);

    // Change the motion state to true (motion detected):
    if (motionState == false) {
      Serial.println("Motion detected!");
      motionState = true;
    }
  }

  // If no motion is detected (pirPin = LOW), do the following:
  else {
    digitalWrite(ledPin, LOW); // Turn off the on-board LED.
    noTone(buzzerPin); // Make sure no tone is played when no motion is detected.
    delay(150);

    // Change the motion state to false (no motion):
    if (motionState == true) {
      Serial.println("Motion ended!");
      motionState = false;
    }
  }
}

// Function to create a tone with parameters duration and frequency:
void alarm(long duration, int freq) {
  tone(buzzerPin, freq);
  delay(duration);
  noTone(buzzerPin);
}
