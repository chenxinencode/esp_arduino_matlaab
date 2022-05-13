void debug_or_dxl(){
  if (DEBUG1==true){
    Serial.begin(115200);
  }
  if(DEBUG2==true){
    dxl.begin(1000000);
    dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
    dxl.ping(DXL_ID7);
    dxl.torqueOff(DXL_ID7);
    dxl.setOperatingMode(DXL_ID7, OP_POSITION);
    dxl.torqueOn(DXL_ID7);


  }
  else if (DEBUG1==false&&DEBUG2==false){
    dxl.begin(1000000);
    dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
    
    dxl.ping(DXL_ID1);
    dxl.ping(DXL_ID2);
    dxl.ping(DXL_ID3);
    dxl.ping(DXL_ID4);
    dxl.ping(DXL_ID5);
    dxl.ping(DXL_ID6);
    dxl.ping(DXL_ID7);
  
    dxl.torqueOff(DXL_ID1);
    dxl.torqueOff(DXL_ID2);
    dxl.torqueOff(DXL_ID3);
    dxl.torqueOff(DXL_ID4);
    dxl.torqueOff(DXL_ID5);
    dxl.torqueOff(DXL_ID6);
    dxl.torqueOff(DXL_ID7);
    
    dxl.setOperatingMode(DXL_ID1, OP_POSITION);
    dxl.setOperatingMode(DXL_ID2, OP_POSITION);
    dxl.setOperatingMode(DXL_ID3, OP_POSITION);
    dxl.setOperatingMode(DXL_ID4, OP_POSITION);
    dxl.setOperatingMode(DXL_ID5, OP_POSITION);
    dxl.setOperatingMode(DXL_ID6, OP_POSITION);
    dxl.setOperatingMode(DXL_ID7, OP_POSITION);
    
    dxl.torqueOn(DXL_ID1);
    dxl.torqueOn(DXL_ID2);
    dxl.torqueOn(DXL_ID3);
    dxl.torqueOn(DXL_ID4);
    dxl.torqueOn(DXL_ID5);
    dxl.torqueOn(DXL_ID6);
    dxl.torqueOn(DXL_ID7);

  }
}


void desire_angle_qd(float t,double *qdd)
{
//,double alpha,double omega,double delta,

  for (int i=0; i<N-1; i++)
  {

    qdd[i]=alpha*sin(omega*t+(i-1+1)*delta)+phi;

  }
  //return qdd;

}

void DxlToDegree(double *qdd,int *dxl_pos)
{
    
    for (int i=0; i<N-1; i++)
    {
      int max_pos = 1024;
      int max_deg = 300;
      dxl_pos[i]=(max_pos - 1) * ((max_deg/2 +qdd[i])/max_deg);
      //dxl_pos[i]=(qdd[i]+150)*NORMALIZE;
      dxl_pos[i]=round(dxl_pos[i]);
      dxl_pos[i]=min(max(dxl_pos[i],0),max_pos-1);
    }
    
    
}

void timeSync(unsigned long deltaT) {
  //unsigned long currTime = micros();
  unsigned long currTime = millis();
  long timeToDelay = deltaT - (currTime - t);
  if (timeToDelay > 0)
  {
    delay(timeToDelay);
    //delayMicroseconds(timeToDelay % 1000);
  }
  t = currTime + timeToDelay;
}

//void execute(response) {
  
//}

String getValue(String data, char separator, int index) {
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
