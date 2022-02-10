int ENA = 5;
int ENB = 6;
int IN1 = 7;
int IN2 = 8;
int IN3 = 12;
int IN4 = 13;
int val = 0;

#define MOTOR_GO_FORWARD {digitalWrite(IN1,HIGH);digitalWrite(IN2,LOW);digitalWrite(IN3,LOW);digitalWrite(IN4,HIGH);}
#define MOTOR_GO_BACK {digitalWrite(IN1,LOW);digitalWrite(IN2,HIGH);digitalWrite(IN3,HIGH);digitalWrite(IN4,LOW);}
#define MOTOR_GO_RIGHT {digitalWrite(IN1,LOW);digitalWrite(IN2,HIGH);digitalWrite(IN3,LOW);digitalWrite(IN4,HIGH);}
#define MOTOR_GO_LEFT {digitalWrite(IN1,HIGH);digitalWrite(IN2,LOW);digitalWrite(IN3,HIGH);digitalWrite(IN4,LOW);}
#define MOTOR_GO_STOP {digitalWrite(IN1,LOW);digitalWrite(IN2,LOW);digitalWrite(IN3,LOW);digitalWrite(IN4,LOW);}

void setup() {
  Serial.begin(9600);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  delay(30000);
}

void loop() {
  if(Serial.available()){
    val = Serial.read();
    if(val == 48){
      MOTOR_GO_LEFT;
      }
    else if(val == 49){
      MOTOR_GO_RIGHT;
      }
    if (val == 50){
      MOTOR_GO_FORWARD;
      }
    else if(val == 51){
      MOTOR_GO_BACK;
      }
  }
  else{
    MOTOR_GO_STOP;
    }
  delay(100);
}
