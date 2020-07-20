const int motor = 11;
const int  btn = 12;   

int btnCount = 0;   
int btnState = 0;         
int lastbtnState = 0;     

void setup() {
  pinMode(btn, INPUT);
  pinMode(motor, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  btnState = digitalRead(btn);

  if (btnState != lastbtnState) {
    if (btnState == HIGH) {
      btnCount++;
    } else {
    }
    delay(50);
  }
  lastbtnState = btnState;
  
  if (btnCount % 3 == 1) {
    analogWrite(motor, 100);
    Serial.println("speed 80");
  }
  else if(btnCount % 3 == 2) {
    analogWrite(motor, 20);
    Serial.println("speed 20");
  }
  else {
    digitalWrite(motor, HIGH);
    Serial.println("speed 0");
  }
}
