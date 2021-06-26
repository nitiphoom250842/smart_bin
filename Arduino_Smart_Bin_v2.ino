
#include <Ultrasonic.h>

Ultrasonic Ultrasonic1(38,40); // (Trig PIN,Echo PIN)
Ultrasonic Ultrasonic2(26,28); // (Trig PIN,Echo PIN)
Ultrasonic Ultrasonic3(30,32); // (Trig PIN,Echo PIN)
Ultrasonic Ultrasonic4(34,36); // (Trig PIN,Echo PIN)
  
//1st Step motor
#define DIR_PIN1 2
#define STEP_PIN1 4

//2nd Step motor
#define DIR_PIN2 3
#define STEP_PIN2 5

//Control motor
#define MOTOR 6
#define PWM 7

#define SWITCH 8//Metal detect sensor

int last = 0;//last state of Control motor

void move_motor(int data){//control motor
    digitalWrite(MOTOR, (data == 0 || (data == 2 && last == 1))?HIGH:LOW);

    analogWrite(PWM,(data == 2)?90:((data == 0)?140:175
    ));
    delay(200);
    while(digitalRead(SWITCH) == 0);
    analogWrite(PWM,(data == 2)?30:130);
    delay(200);
    analogWrite(PWM,0);

    last = data;
}
/*
void move_motor(int data){//control motor
    digitalWrite(MOTOR, (data == 0 || (data == 2 && last == 1))?HIGH:LOW);

    analogWrite(PWM,(data == 2)?90:161);
    delay(200);
    while(digitalRead(SWITCH) == 0);
    analogWrite(PWM,(data == 2)?30:120);
    delay(200);
    analogWrite(PWM,0);

    last = data;
}*/

void steps(int dpin, //direction pin
           int spin, //step pin
           int steps, //how many step
           int delaytime //how long for one step
           ){//step motor
  //direction
  int dir = (steps>0)?LOW:HIGH;
  digitalWrite(dpin,dir); 

  //move step motor
  for(int i = 0;i < abs(steps);i++){
    digitalWrite(spin, HIGH); 
    delayMicroseconds(delaytime); 
    digitalWrite(spin, LOW); 
    delayMicroseconds(delaytime); 
  }
} 

void push(){//1.566 s
  int step = 940, 
      time = 700;
  steps(DIR_PIN1,STEP_PIN1,step,time);
  delay(250);
  steps(DIR_PIN1,STEP_PIN1,-1*step,time);
}

void release(){//1.73 s
  int step = 740, 
      time = 1000;
  steps(DIR_PIN2,STEP_PIN2,step,time);
  delay(250);
  steps(DIR_PIN2,STEP_PIN2,-1*step,time);
}

void working_in(String data){//control all motor
  /*
  data | type
  0    | can
  1    | pete
  2    | plastic
  3    | other
  */
  if(data == "3"){
    release();
  }
  else{
    int l = 1, r = 1;
    if(data == "0" || data == "1"){
      move_motor(1);
      (data == "1")? release():push();
    }
    else if(data == "2"){
      move_motor(0);
      release();
    }
    move_motor(2);   
  }
  
  String output = "{";
  output += "'ultra0':" + String(Ultrasonic1.Ranging(CM)) + ",";//bin 0 : trig 22, echo 24
  output += "'ultra1':" + String(Ultrasonic2.Ranging(CM)) + ",";//bin 1 : trig 26, echo 28
  output += "'ultra2':" + String(Ultrasonic3.Ranging(CM)) + ",";//bin 2 : trig 30, echo 32
  output += "'ultra3':" + String(Ultrasonic4.Ranging(CM)) + "}";//bin 3 : trig 34, echo 36
  /*
  String output = "{";
  output += "'ultra0':" + String(ultra(38, 40)) + ",";//bin 0 : trig 22, echo 24
  output += "'ultra1':" + String(ultra(26, 28)) + ",";//bin 1 : trig 26, echo 28
  output += "'ultra2':" + String(ultra(30, 32)) + ",";//bin 2 : trig 30, echo 32
  output += "'ultra3':" + String(ultra(34, 36)) + "}";//bin 3 : trig 34, echo 36
  */
  Serial.println(output);
}

long microsecondsToCentimeters(long microseconds){//distance for ultrasonic sensor
  return microseconds / 29 / 2;
}

int ultra(int trig,//trig pin
          int echo//echo pin
          ){//ultrasonic sensor working
  long duration, cm;

  pinMode(trig, OUTPUT);
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);
  
  pinMode(echo, INPUT);
  
  duration = pulseIn(echo, HIGH);
  
  cm = microsecondsToCentimeters(duration);
  
  return cm;
}

void setup() {
  Serial.begin(9600);

  pinMode(DIR_PIN1, OUTPUT);
  pinMode(DIR_PIN2, OUTPUT);

  pinMode(STEP_PIN1, OUTPUT);
  pinMode(STEP_PIN2, OUTPUT);

  pinMode(MOTOR,OUTPUT);
  pinMode(PWM,OUTPUT);

  pinMode(SWITCH,INPUT);
 
  analogWrite(PWM,0);

}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    //working_in(data);

    String output = "{";
    output += "'ultra0':" + String(Ultrasonic1.Ranging(CM)) + ",";//bin 0 : trig 22, echo 24
    output += "'ultra1':" + String(Ultrasonic2.Ranging(CM)) + ",";//bin 1 : trig 26, echo 28
    output += "'ultra2':" + String(Ultrasonic3.Ranging(CM)) + ",";//bin 2 : trig 30, echo 32
    output += "'ultra3':" + String(Ultrasonic4.Ranging(CM)) + "}";//bin 3 : trig 34, echo 36
    Serial.println(output);
  }
}
