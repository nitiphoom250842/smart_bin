
int enA = 9;
int in1 = 2;
int in2 = 3;

void setup(){
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);


  analogWrite(enA,200);
  digitalWrite(in2,HIGH);
  digitalWrite(in1,LOW);
}

void loop(){
}
