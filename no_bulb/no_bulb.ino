int a;
int ledPin = 13;

void setup() {
  Serial.begin(9600); //it for connect the plotter
  pinMode(ledPin, OUTPUT);
  
}

void loop() {
  input();
  check();
   
}

void input(){
   if(Serial.available()> 0){
    a = Serial.parseInt();
   }
}

void check(){
  if(a==1){
    digitalWrite(ledPin, HIGH);
    delay(1000);
   }
   else{
    digitalWrite(ledPin, LOW);
   }
}
