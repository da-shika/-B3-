int ENA = 5;
int ENB = 6;
int IN1 = 7;
int IN2 = 8;
int IN3 = 12;
int IN4 = 13;
int Infrared_left = A2;
int Infrared_right = A3;
int IR_L;
int IR_R;
int Left_Speed_Hold = 65;
int Right_Speed_Hold = 65;


#define MOTOR_GO_FORWARD {digitalWrite(IN1,HIGH);digitalWrite(IN2,LOW);digitalWrite(IN3,LOW);digitalWrite(IN4,HIGH);}
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

void loop()
{
  IR_L = digitalRead(A2);
  IR_R = digitalRead(A3);
  Serial.println(IR_L);

  if((IR_L == HIGH)&&(IR_R == HIGH))
  {
    MOTOR_GO_STOP;
    }
  
  if((IR_L == HIGH)&&(IR_R == LOW))
  {
    MOTOR_GO_LEFT;
    }
  
  if((IR_L == LOW)&&(IR_R == HIGH))
  {
    MOTOR_GO_RIGHT;
    }

  if((IR_L == LOW)&&(IR_R == LOW))
  {
    MOTOR_GO_FORWARD;
    }
  }
