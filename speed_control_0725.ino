const int motor = 11;
const int  btn = 12;   

int btnCount = 0;   
int btnState = 0;         
int lastbtnState = 0;     

void setup() {
  pinMode(motor, OUTPUT);
  pinMode(btn, INPUT);
  Serial.begin(9600);
}

void loop() {
  btnState = digitalRead(btn);
  
  if (btnState != lastbtnState) {
    if (btnState == HIGH) {
      btnCount++;
    } 
    else {
    }
    delay(50);
  }
  
  lastbtnState = btnState;
  
  if (btnCount %4 == 1) { 
    analogWrite(motor, 110); 
    Serial.println("weak wind");
  }
  else if(btnCount %4 == 2) {
    analogWrite(motor, 50);
    Serial.println("middle wind");
  }
    else if(btnCount %4 == 3) {
    analogWrite(motor, LOW);
    Serial.println("strong wind"); 
  }
  else {
    digitalWrite(motor, HIGH);
    Serial.println("stop");
  }  
}
