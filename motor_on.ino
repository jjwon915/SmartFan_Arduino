int motor = 11;
int btn = 12;
int flag1 = 0;
int flag2 = 0;
int state = 0;

void setup() {
  pinMode(motor,OUTPUT);
  pinMode(btn,INPUT); 
  Serial.begin(9600);
}

void loop() {
  flag1 = digitalRead(btn);
  if((flag1 == HIGH) && (flag2 == LOW)){
    state = 1 - state;
    delay(10);
  }
  flag2 = flag1;
  
  if(state == 1){
    digitalWrite(motor,0);
    Serial.println("ON");
  }
  else{
    digitalWrite(motor,1);
    Serial.println("OFF");
  }
}
