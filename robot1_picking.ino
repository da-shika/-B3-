#include<Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int pos1 = 150;
int pos2 = 120;
int pos4 = 0;

void setup() {
  servo1.attach(11);
  servo2.attach(2);
  servo3.attach(4);
  servo4.attach(3);

  servo1.write(pos1);
  servo2.write(pos2);
  servo4.write(pos4);
}

void up(){
  for(pos1 = 50; pos1 < 150; pos1++)
  {
    servo1.write(pos1);
    delay(50);
    }
  delay(1000);
  }

void down(){
  for(pos1 = 150; pos1 >=50; pos1--)
   {
    servo1.write(pos1);
    delay(50);
    }
  delay(1000);  
  }

void open(){
  for(pos4 = 85; pos4>0 ;pos4--)
  {
    servo4.write(pos4);
    delay(200);
    }
   delay(6000);
  }

void close(){
  for(pos4 = 0;pos4<85;pos4++)
  {
    servo4.write(pos4);
    delay(200);
    }
   delay(6000);
  }

void loop() {
  down();
  close();
  up();
  down();
  open();
  up();
}
