#include<math.h>
#include <DynamixelShield.h>
DynamixelShield dxl;

//Arduino---ESP
//3.3V------3V
//GND-------G
//RX3------TX
//TX3------RX



const uint8_t DXL_ID1 = 1;
const uint8_t DXL_ID2 = 2;
const uint8_t DXL_ID3 = 3;
const uint8_t DXL_ID4 = 4;
const uint8_t DXL_ID5 = 5;
const uint8_t DXL_ID6 = 6;
const uint8_t DXL_ID7 = 7;
const float DXL_PROTOCOL_VERSION = 1.0;
using namespace ControlTableItem;

#define N 8
#define pi 3.1415926535897 
#define rad2deg 180/pi
#define NORMALIZE 3.41 // 1023/300
#define MAX_POS 1023

float t=0;  
const double dt=0.1;


double alpha;
double omega;
double delta;
double phi;
double default_ang;

long loopTime = 20000;    // in micro seconds
double qd[N-1];
//double qdd[N-1]={45,30,30,30,30,30,45};
double qdd[N-1];
float dxl_pos[N-1];

bool DEBUG1=false;//通过串口测试
bool DEBUG2=true;//测试一个舵机
void setup() {

  
  debug_or_dxl();   
  Serial3.begin(250000);//这是和ESP连接的 250000是可以的，
  


}

void loop() {
             
    //ESP_READ();//通过蓝牙获取步态 
    String stopstr=";";
    int timeout_secs=1;//s

    ESPwait(stopstr,timeout_secs);  
    //execute(response);
  

        
}
