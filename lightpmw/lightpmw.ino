

int sensorPin = A0;
int led=9;

void setup() {
Serial.begin(9600);
  
}

void loop() {int sensorValue,y;
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);    
  Serial.println(sensorValue);
  y=sensorValue;
  y=map(y,100,1000,0,255);
  Serial.println(y);
  analogWrite(led,y);
  delay(500);                  
}
