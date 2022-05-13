void ESPwait(String stopstr,int timeout_secs)
{
  String response;
  bool found = false;
  char c;
  long timer_init;
  long timer;

  while (!found) {
    if (Serial3.available()) {
      
      c = Serial3.read();
      response += c;
      
      if (response.endsWith(stopstr)) {
      
        found = true;
//        Serial.println(response);
      }
    } // end Serial1_available()
  } // end while (!found)
  
if(DEBUG1==true) Serial.println(response);    

//下面是控制舵机

  if(DEBUG2==true)
  {
    
    String dxl_pos_str7=getValue(response, ',', 6);
    float dxl_pos7=dxl_pos_str7.toFloat();
    dxl.setGoalPosition(DXL_ID7, dxl_pos7);
    //delay(10);

  }

  else if(DEBUG1==false&&DEBUG2==false)
  {
      String dxl_pos_joint[7];//每个关节的角度值
      for (int j = 0; j < 7; j++) {
        dxl_pos_joint[j] = getValue(response, ',', j);
        dxl_pos[j] = dxl_pos_joint[j].toFloat();
      }
      dxl.setGoalPosition(DXL_ID1, dxl_pos[0]);
      dxl.setGoalPosition(DXL_ID2, dxl_pos[1]);
      dxl.setGoalPosition(DXL_ID3, dxl_pos[2]);
      dxl.setGoalPosition(DXL_ID4, dxl_pos[3]);
      dxl.setGoalPosition(DXL_ID5, dxl_pos[4]);
      dxl.setGoalPosition(DXL_ID6, dxl_pos[5]);
      dxl.setGoalPosition(DXL_ID7, dxl_pos[6]);


  }

}
