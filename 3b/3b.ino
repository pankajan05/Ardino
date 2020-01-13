char a;
int ledPin1 = 13;
int ledPin2 = 8;
int ledPin3 = 4;

void setup() {
  Serial.begin(9600); //it for connect the plotter
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  
}

void loop() {
  input();
  check();
   
}

void input(){
   if(Serial.available()> 0){
    a = Serial.read();
   }
}

void check(){
  switch(a){
    case 'b':
    case 'B':
    digitalWrite(ledPin1, HIGH);
    break;
    case 'r':
    case 'R':
    digitalWrite(ledPin2, HIGH);
    break;
    case 'g':
    case 'G':
    digitalWrite(ledPin3, HIGH);
    break;
    
  }
  
}
