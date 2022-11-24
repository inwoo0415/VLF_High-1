#define F_sensor 9
#define L_sensor 10
#define R_sensor 11

float flag_mazor_1 =0;

float robot_width = 200;	//로봇 크기
float mazor_width = 500;
float mazor_width_tolerance = 30;




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




void setup()
{
  pinMode(F_sensor, OUTPUT);
  pinMode(L_sensor, OUTPUT);
  pinMode(R_sensor, OUTPUT);
  Serial.begin(115200);
}

void loop()
{
  
  float F_distance =0;
  float L_distance =0;
  float R_distance =0;
  float measure_width =0;
  F_distance = sonar(F_sensor);
  L_distance = sonar(L_sensor);
  R_distance = sonar(R_sensor);
    
  

  Serial.print("\n F_Distance : ");
  Serial.print(F_distance);
  Serial.print("\n L_Distance : ");
  Serial.print(L_distance);
  Serial.print("\n R_Distance : ");
  Serial.print(R_distance);
  
  measure_width = L_distance + R_distance + robot_width;	//오른쪽 왼족 초믕파 센서 + 로봇 크기 ㄷ자형 지형 거리 파악
  
  
  //ㄷ자 거리 파악해서 우리가 지정한 거리 + 오차 보다 조금 크가나 작으면 감지해라 이거임 이곳으로 들어가라
  if ((measure_width >= (mazor_width - mazor_width_tolerance)) && (measure_width <= (mazor_width + mazor_width_tolerance)))
  {
   if(( F_distance > mazor_width)  && ((F_distance < mazor_width +400)))
   {
     flag_mazor_1 = 1;
   }
  }
  else
  {
    flag_mazor_1 =0;
  }
  
  
  
}