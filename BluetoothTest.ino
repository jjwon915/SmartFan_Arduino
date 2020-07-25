#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(5, 6);
long int data;

int motor = 11;
long int weak = 110;
long int middle = 50;
long int strong = 0;
long int stop_ = 1;

char state = 0;

void setup() {
  pinMode(motor, OUTPUT);
  digitalWrite(motor, HIGH);
  Serial.begin(9600);
  Bluetooth.begin(9600);
}

void loop() {
  while(Bluetooth.available() == 0);

  if(Bluetooth.available() > 0){
    data = Bluetooth.parseInt();
  }
  delay(400);

  if(data == strong) {
    analogWrite(motor, LOW);
    Serial.println("motor ON");
  }
  if(data == stop_) {
    digitalWrite(motor, HIGH);
    Serial.println("motor OFF");
  }
}
