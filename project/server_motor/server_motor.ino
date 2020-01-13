// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 3; 
int a = 0;
// Create a servo object 
Servo Servo1; 
void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin); 
}

void loop(){ 
  rotate(+45);
  rotate(-45);
}

void rotate(int x){
  // Make servo go to 0 degrees 
  Servo1.write(0);
  int i=0;
  while(i<4){
    Servo1.write(a);
    a = a+x;
    delay(1000);
    i++;
  }
}
