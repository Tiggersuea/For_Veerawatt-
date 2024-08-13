void PidTrack(){
  position= Read_map();
  sp=10;
  KP=0.020;// ถ้าค่า KP สูง ระบบจะตอบสนองอย่างรวดเร็วต่อความผิดพลาด แต่ถ้าสูงเกินไปอาจทำให้เกิดการสั่น (Oscillation)
  KD=0.018;//ช่วยลดการสั่น (Oscillation) โดยเพิ่มการหน่วงเวลาตามอัตราการเปลี่ยนแปลงของความผิดพลาด ทำให้การตอบสนองของระบบมีความนุ่มนวลและเสถียรมากขึ้น
  KI=0.00001;//ช่วยปรับแก้ปัญหาความผิดพลาดที่ยังคงมีอยู่เมื่อเวลาผ่านไป (Steady-State Error) แต่ถ้าค่า KI สูงเกินไปอาจทำให้เกิดการสั่นหรือไม่เสถียร
//   while(Sensor[0]>150||Sensor[6]>150)
//   {
//    position=Read_map();
//    Pid();
//   }
   position=Read_map();
   Pid();
}

//เพิ่มความเร็ว
 void SpeedUp(int MinSpeed , int TopSpeed , unsigned long TimeSpeed){
  int Time = 0;
 
  Time = TimeSpeed;
 
  while(MinSpeed < TopSpeed)
  {
    StTime();
   
    
    MinSpeed += 1;
    sp = MinSpeed;
    
    if(MinSpeed > 40)
    {
      KP = 0.00595;
      KD = 0.0996; 
      KI = 0.00000407;
    }
    
    else if(MinSpeed > 50)
    {
      KP = 0.00895;
      KD = 0.1096;
      KI = 0.00000407;
    }
    
    else if(MinSpeed > 60)
    {
      KP = 0.01295;
      KD = 0.1396; 
      KI = 0.00000407;
    }

    else if(MinSpeed > 70 && MinSpeed < 81)
    {
      KP = 0.01595;
      KD = 0.1896; 
      KI = 0.00000407;
    }

    else 
    {
      KP = 0.01695;
      KD = 0.1996; 
      KI = 0.00000407;
    }

    while(ReadTime() < Time)
    {
      
      position=Read_map();
      Pid();
    }
    
  }
}

//หยุดตรงเส้นตัด
void Trackcross(){
  position= Read_map();
  sp=40;
  KP=0.016;
  KD=0.16;
  KI=0.00001;
   while(Sensor[0]<150||Sensor[6]<150)
   {
    position=Read_map();
    Pid();
   }
}

//เดินผ่านเส้นตัดไป
void TrackTime(int Speed,float kp,float kd,float ki,int Time)
{
  StTime();
  sp=Speed;
  KP=kp;
  KD=kd;
  KI=ki;
  
  while(ReadTime() < Time)
    {
      
      position=Read_map();
      Pid();
    }
}

//เลี้ยวขวา
void Right(){
  motor(1,45);
   motor(2,-10);
   delay(90);
    TrackTime(50,0.016,0.2,0.00001,50);
  }
//เลี้ยวซ้าย
void Left(){
  turn=false;
  motor(1,-10);
   motor(2,45);
   delay(100);
   TrackTime(50,0.016,0.2,0.00001,50);
   turn=true;
}

// อ่านจุดตัด
void ReadCross(int cross){
   Trackcross();
   TrackTime(25,0.016,0.16,0.00001,60);
  while(count<cross){
    PidTrack();
    Trackcross();
    TrackTime(25,0.016,0.16,0.00001,60);
    }
  TrackTime(25,0.016,0.16,0.00001,50);
  ao();
}
