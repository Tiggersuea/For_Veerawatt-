int Read_map()
{
  for (uint8_t i = 0; i < SensorCount; i++) {
    Sensor[i] = analogRead(i);
    if (Sensor[i] < 400) Sensor[i] = 1000;  // สีดำ
    else if (Sensor[i] > 500) Sensor[i] = 0;  // สีขาว
    else Sensor[i] = map(Sensor[i], 70, 100, 1000, 0); // ระหว่างสีขาวและดำ
  }

   
  
  uint32_t Avg = 0; 
  uint16_t Sum = 0;
  bool OnLine = false;

 for (uint8_t i = 0; i < SensorCount; i++) {
    int Value = Sensor[i];
    if (Value < 1000) { OnLine = true; } // ค่าที่ไม่ใช่สีขาว (พื้นที่ที่มีเส้น)
    if (Value > 0) {
        Avg += (uint32_t)Value * (i * 1000);
        Sum += Value;
    }
 }

  if (!OnLine) {
    if (LastPosition < (SensorCount - 1) * 1000 / 2) {
        return (SensorCount - 1) * 1000;
    } else {
        return 0;
    }
  }

  if (Sum > 0) {
    LastPosition = Avg / Sum;
   } else {
    LastPosition = (SensorCount - 1) * 1000 / 2;
}

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
  glcd(0,0,"%d   ",analog(0));
  glcd(1,0,"%d   ",analog(1));
  glcd(2,0,"%d   ",analog(2));
  glcd(3,0,"%d   ",analog(3));
  glcd(4,0,"%d   ",analog(4));
  glcd(5,0,"%d   ",analog(5));
  glcd(6,0,"%d   ",analog(6));
}

void Read1(){
  Read_map();
  glcd(0,0,"%d   ",Sensor[0]);
  glcd(1,0,"%d   ",Sensor[1]);
  glcd(2,0,"%d   ",Sensor[2]);
  glcd(3,0,"%d   ",Sensor[3]);
  glcd(4,0,"%d   ",Sensor[4]);
  glcd(5,0,"%d   ",Sensor[5]);
  glcd(6,0,"%d   ",Sensor[6]);
  delay(600);
  glcdClear();
  }
