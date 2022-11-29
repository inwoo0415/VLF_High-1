
#define IN1 2// 1번째 모터
#define IN2 3// 1번째 모터
#define ENA 5// 1번째 모터  PWM제어

#define IN3 4   // 2번째 모터
#define IN4 7   // 2번째 모터
#define ENB 6   // 2번째 모터 PWM제어
int speed = 75;

int Motor_1(int direction, int speed)  //1번 후진 2번 전진 3번 정지
{
  switch(direction)
  {
   case 1:digitalWrite(IN1,LOW);
          digitalWrite(IN2,HIGH);
          analogWrite(ENA,speed);
          digitalWrite(IN3,LOW);
          digitalWrite(IN4,HIGH);
          analogWrite(ENB,speed);
          break;

    case 2:digitalWrite(IN1,HIGH);
          digitalWrite(IN2,LOW);
          analogWrite(ENA,speed);
          digitalWrite(IN3,HIGH);
          digitalWrite(IN4,LOW);
          analogWrite(ENB,speed);
          break;
          
    case 3:digitalWrite(IN1, LOW);
          digitalWrite(IN2, LOW);
          analogWrite(ENA, 0);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, LOW);
          analogWrite(ENB, 0);
          break;

   }
}

int Motor_2(int direction, int speed)  //1번 좌회전 2번 우회전
{
  switch(direction)
  {
   case 1:digitalWrite(IN1,HIGH);
          digitalWrite(IN2,LOW);
          analogWrite(ENA,speed+60);
          digitalWrite(IN3,HIGH);
          digitalWrite(IN4,LOW);
          analogWrite(ENB,20);
        ;
        
          break;

    case 2:digitalWrite(IN1,HIGH);
          digitalWrite(IN2,LOW);
          analogWrite(ENA,20);
          digitalWrite(IN3,HIGH);
          digitalWrite(IN4,LOW);
          analogWrite(ENB,speed+60);
          break;

  }       
}

/*************Motor Drvier**************/

/*************Motor Drvier**************/


void setup()
{
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    
}

void loop()

{
  Motor_1(2, speed); //전진
  delay(1500);
  Motor_1(1, speed);  //후진
  delay(1500);
    Motor_1(2, speed);  //전진
  delay(1500);
  Motor_2(1, speed);    //좌회전
  delay(1500);
  Motor_1(2, speed);  //전진
  delay(1500);
  Motor_2(2, speed);    //우회전
  delay(1500);
  Motor_1(2, speed);  //전진
    
}
