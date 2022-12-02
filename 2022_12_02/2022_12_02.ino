float F_distance =0;
float L_distance =0;
float R_distance =0;

#define IN1 2// 1번째 모터
#define IN2 3// 1번째 모터
#define ENA 5// 1번째 모터  PWM제어

#define IN3 4   // 2번째 모터
#define IN4 7   // 2번째 모터
#define ENB 6   // 2번째 모터 PWM제어

int speed = 75;
      

#define F_sensor 8
#define L_sensor 10
#define R_sensor 11
      
      
float sonar(int a)
{
                            
    float duration, distance;
    pinMode(a,OUTPUT);
    digitalWrite(a,LOW);
    digitalWrite(a,HIGH);
    delay(10);
    digitalWrite(a,LOW);
    pinMode(a,INPUT);
    duration = pulseIn(a,HIGH);
    distance=(duration *340.0)/2.0/1000.0; 
    return distance;
                      
}



int Motor_1(int direction, int speed)  //1번 후진 2번 전진 3번 정지
{
  switch(direction)
  {
   case 1:digitalWrite(IN1,HIGH);
          digitalWrite(IN2,LOW);
          analogWrite(ENA,speed);
          digitalWrite(IN3,HIGH);
          digitalWrite(IN4,LOW);
          analogWrite(ENB,speed);
          break;

    case 2:digitalWrite(IN1,LOW);
          digitalWrite(IN2,HIGH);
          analogWrite(ENA,speed);
          digitalWrite(IN3,LOW);
          digitalWrite(IN4,HIGH);
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
   case 1:digitalWrite(IN1,LOW);
          digitalWrite(IN2,HIGH);
          analogWrite(ENA,speed);
          digitalWrite(IN3,HIGH);
          digitalWrite(IN4,LOW);
          analogWrite(ENB,speed);
           if( F_distance < 200 && L_distance)
          {
          break;
          }       
    
    case 2:digitalWrite(IN1,HIGH);
          digitalWrite(IN2,LOW);
          analogWrite(ENA,speed);
          digitalWrite(IN3,LOW);
          digitalWrite(IN4,HIGH);
          analogWrite(ENB,speed);
          if( F_distance < 200 && R_distance)
          {
          break;
          }
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
     Serial.begin(115200);
}

void loop()

{
  F_distance = sonar(F_sensor);
  L_distance = sonar(L_sensor);
  R_distance = sonar(R_sensor);


  Serial.print("\n F_Distance : ");
  Serial.print(F_distance);

  Serial.print("\n L_Distance : ");
  Serial.print(L_distance);

  Serial.print("\n R_Distance : ");
  Serial.print(R_distance);

    delay(50);          
  Serial.print("A Ping : ");
  Serial.print(sonar[0].ping_cm());
  Serial.println("cm");
                              
                                
                                
  if (F_distance < 250)   // 정면물체 감지
  {
      Motor_1(3, speed);   //기동부 정지
      delay(1550);         //일시정지
      if ( L_distance < R_distance )    //왼쪽이 오른쪽보다 감지거리가 크다면
      {                                 
        Motor_2(2,speed);               //좌회전
        delay(1300);                    
        Motor_1(2, speed);              //전진
      }
      else if (R_distance < L_distance)    //오른쪽이 왼보다 감지거리가 크다면
      {
        Motor_2(1,speed);                 //우회전
        delay(1300);
        Motor_1(2, speed);                //전진
      }
    }
    
  else
  {
    Motor_1(2, speed);    //감지가 안될시 전진
  }
                               
  } 
