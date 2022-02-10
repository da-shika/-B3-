int ENA = 5;
int ENB = 6;
int IN1 = 7;
int IN2 = 8;
int IN3 = 12;
int IN4 = 13;
int Left_Speed_Hold = 65;
int Right_Speed_Hold = 65;
int val = 0;

#define MOTOR_GO_FORWARD {digitalWrite(IN1,HIGH);digitalWrite(IN2,LOW);digitalWrite(IN3,LOW);digitalWrite(IN4,HIGH);}
#define MOTOR_GO_BACK {digitalWrite(IN1,LOW);digitalWrite(IN2,HIGH);digitalWrite(IN3,HIGH);digitalWrite(IN4,LOW);}
#define MOTOR_GO_RIGHT {digitalWrite(IN1,LOW);digitalWrite(IN2,HIGH);digitalWrite(IN3,LOW);digitalWrite(IN4,HIGH);}
#define MOTOR_GO_LEFT {digitalWrite(IN1,HIGH);digitalWrite(IN2,LOW);digitalWrite(IN3,HIGH);digitalWrite(IN4,LOW);}
#define MOTOR_GO_STOP {digitalWrite(IN1,LOW);digitalWrite(IN2,LOW);digitalWrite(IN3,LOW);digitalWrite(IN4,LOW);}

void setup()
{
  Serial.begin(9600);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  analogWrite(ENB,Left_Speed_Hold);
  analogWrite(ENA,Right_Speed_Hold);
  }

void loop(){
  MOTOR_GO_FORWARD;
  delay(1000);
  MOTOR_GO_BACK;
  delay(1000);
  if(Serial.available()){
    val = Serial.read();
    if(val == 49)
      MOTOR_GO_STOP;
      }
  delay(1); 
  }
