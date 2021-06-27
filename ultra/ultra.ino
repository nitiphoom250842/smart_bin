void setup() {
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(ultra(34,36));//0
  Serial.print(" ");
  Serial.print(ultra(30,32));//1
  Serial.print(" ");
  Serial.print(ultra(38,40));//2
  Serial.print(" ");
  Serial.println(ultra(26,28));//3
  delay(500);
}

int ultra(int pingPin, int inPin){
  long duration, cm;

  pinMode(pingPin, OUTPUT);
  
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  
  pinMode(inPin, INPUT);
  
  duration = pulseIn(inPin, HIGH);
  
  cm = microsecondsToCentimeters(duration);
  
  return cm;
}

long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
}