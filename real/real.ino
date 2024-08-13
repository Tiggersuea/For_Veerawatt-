#include<pop7.h>
int Last_value = 0;
int error = 0;
int integral = 0;
int differencial = 0;
int Last_error = 0;
const uint32_t setpoint = 3000;

float KP=0;
float KD=0;
double KI=0;
int sp=0;
bool turn = true;
//////////////////////// Time
int Time0,BaseTime0;

int count=0;

bool lineBlack = true;

const uint8_t SensorCount = 7;

int Kspeed,Ktime;
int Sensor[SensorCount];
bool Knb=false;
int position =0;
int Rmotor , Lmotor ;
float Kperror;
uint32_t LastPosition;
void setup() {

  // put your setup code here, to run once:
  //Serial.begin(115200);
//  OK();
while(in(8)) {
//  setTextSize(2);
//  Read();
}
 
  sound(1000,100);
  setTextSize(2);
  // TrackTime(60,0.016,0.16,0.00001,1900);
 
  // TrackTime(45,0.020,0.1,0.00001,12000);
  // TrackTime(60,0.016,0.16,0.00001,3000);
  // ao();
 
}

void loop(){
  
  //ReadCross(2);
  //TrackTime(25,0.23,0.3,0.015,30);
   PidTrack();
  //ReadMap();
//    Read();
}
