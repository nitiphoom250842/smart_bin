#define motor1 12
#define motor2 13
#define swl 8
#define swr 9

int last_ps = 2;
int center_time = 0;

void setup() {
  Serial.begin(9600);
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT); 

  pinMode(swl,INPUT);
  pinMode(swr,INPUT); 
  
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
}

void loop() {
 
}
