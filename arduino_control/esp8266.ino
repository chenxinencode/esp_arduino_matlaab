#include <ESP8266WiFi.h>
#include <Arduino.h>
#include <Wire.h>


//const char *ssid = "3x513";
//const char *password = "862234463";
const char *ssid = "iPhone";
const char *password = "11111111";

//const char *ssid = "Cornetto";
//const char *password = "qwertyuiop.";

int timeout=20;

boolean DEBUG=false;
WiFiServer server(8888);

void setup()
{
    Serial.begin(250000);
    //Serial.printf("Connecting to %s ", ssid);
    WiFi.begin(ssid, password);

   while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        //Serial.print(".");
    }
    //Serial.println(" connected"); 
    server.begin();
   //Serial.printf("Web server started, open %s in a web browser\n", WiFi.localIP().toString().c_str());
   while(Serial.read()>=0){}//清除串口
}

void loop()
{
 server.begin();  
 while (WiFi.status() == WL_CONNECTED)
 {      
    WiFiClient clientpc = server.available(); //尝试建立客户对象
    clientpc.setTimeout(1);
    while (clientpc.connected()) //如果客户端建立连接
    { 
      //pc-->mega
        String response="";
        long int time=millis();
         while ((time+timeout) > millis())
         {
          while(clientpc.available()) {
            // The esp has data so display its output to the serial window
            char c=clientpc.read(); // read the next character.
            response += c;
            
            } 
      
          if(response.charAt(response.length()-2)=='，'&&response.charAt(response.length()-1)=='；'){
            //delay(2);
            time=0;
            
          }
          }
        Serial.print(response);

      //mega-->pc
//        String mega_to_pc= "";
//        long int time2=millis();
//         while ((time2+timeout) > millis())
//         {
//          while(Serial.available()) {
//            // The esp has data so display its output to the serial window
//            char d=Serial.read(); // read the next character.
//            mega_to_pc += d;
//            } 
//      
//          if(mega_to_pc.charAt(mega_to_pc.length()-2)=='，'&&mega_to_pc.charAt(mega_to_pc.length()-1)=='；'){
//            time=0;
//          }
//          }
//        clientpc.print(mega_to_pc);
   
 
    }

  
          
}
}
