#define motor 6
#define pwm 7

#define sw 8

String last = "";

void setup() {
  Serial.begin(9600);
  pinMode(motor,OUTPUT);
  pinMode(pwm,OUTPUT); 
  pinMode(sw,INPUT);
  analogWrite(pwm,0);

}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    digitalWrite(motor, (data == "0" || (data == "2" && last == "1"))?HIGH:LOW);

    analogWrite(pwm,(data == "2")?45:135);
    delay(200);
    while(digitalRead(sw) == 0);
    Serial.println("com");
    analogWrite(pwm,(data == "2")?22:67);
    delay(200);
    analogWrite(pwm,0);

    last = data;
  }
  /*if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    digitalWrite(motor, (data.toInt() == 0)?HIGH:LOW);
    if (data.toInt() == 2){
      analogWrite(pwm,0);
      data = String(last);
    }
    else if (data.toInt() == 3){
      analogWrite(pwm, (last == 0)?45:32);
      digitalWrite(motor, (last == 0)?LOW:HIGH);
    }
    else
      analogWrite(pwm,(data.toInt() == 0)?120:130);
    last = data.toInt();
  }*/
}