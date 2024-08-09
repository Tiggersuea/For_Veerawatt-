int Read_map(){
  bool OnLine = false;
 
  uint32_t Avg = 0; 
  uint16_t Sum = 0;

  for (uint8_t i=0;i<SensorCount;i++){
    Sensor[i]=map(analogRead(i),35,350,0,1000);
    if (Sensor[i]<750)Sensor[i]=0;
    if (Sensor[i]>750)Sensor[i]=1000;
   
  }

  for (uint8_t i = 0; i <SensorCount; i++)
  {
    int Value = Sensor[i];
    if (Value > 200) { OnLine = true; }
    if (Value > 50)
    {
      Avg += (uint32_t)Value * (i * 1000);
      Sum += Value;
    }
  }
  if (!OnLine)
  {

    if (LastPosition < (SensorCount - 1) * 1000 / 2)
    {
      if(!turn) return (SensorCount - 1) * 1000;
      else return 0;
    }
    else
    { 
      if(!turn) return 0;
      else return (SensorCount - 1) * 1000;
    }
    
  }

  LastPosition = Avg / Sum;
  return LastPosition;
  
 
}
void RealsensorValues(){
 
for(int i=0;i<SensorCount;i++){
Serial.print(analogRead(i));
Serial.print('\t');


}
Serial.println();
delay(200);
}
void Read(){
  glcd(0,0,"%d",analog(0));
  glcd(1,0,"%d",analog(1));
  glcd(2,0,"%d",analog(2));
  glcd(3,0,"%d",analog(3));
  glcd(4,0,"%d",analog(4));
  glcd(5,0,"%d",analog(5));
  glcd(6,0,"%d",analog(6));
}

void Read_Map(){
  
  glcd(0,0,"%d",Sensor[0]);
  glcd(1,0,"%d",Sensor[1]);
  glcd(2,0,"%d",Sensor[2]);
  glcd(3,0,"%d",Sensor[3]);
  glcd(4,0,"%d",Sensor[4]);
  glcd(5,0,"%d",Sensor[5]);
  glcd(6,0,"%d",Sensor[6]);
  delay(600);
  glcdClear();
  }
