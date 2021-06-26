#define DIR_PIN1 2
#define DIR_PIN2 3

#define STEP_PIN1 5
#define STEP_PIN2 6

void setup() { 
  Serial.begin(9600);
  pinMode(DIR_PIN1, OUTPUT);
  pinMode(DIR_PIN2, OUTPUT);

  pinMode(STEP_PIN1, OUTPUT);
  pinMode(STEP_PIN2, OUTPUT);
} 

 

void loop(){ 
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    if(data.toInt() == 1)
      push();
    else if(data.toInt() == 2)
      release();
  }
}

void steps(int dpin, int spin,int steps, int delaytime){ 
  int dir = (steps>0)?LOW:HIGH;
  digitalWrite(dpin,dir); 

  for(int i = 0;i < abs(steps);i++){
    digitalWrite(spin, HIGH); 
    delayMicroseconds(delaytime); 
    digitalWrite(spin, LOW); 
    delayMicroseconds(delaytime); 
  }
} 

void push(){
  int step = 940, 
      time = 700;
  steps(DIR_PIN1,STEP_PIN1,step,time);
  delay(250);
  steps(DIR_PIN1,STEP_PIN1,-1*step,time);
}

void release(){
  int step = 740, 
      time = 1000;
  steps(DIR_PIN2,STEP_PIN2,step,time);
  delay(250);
  steps(DIR_PIN2,STEP_PIN2,-1*step,time);
}