//ThatsEngineering
//Sending Data from Arduino to NodeMCU Via Serial Communication
//NodeMCU code

//Include Lib for Arduino to Nodemcu
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

//D3 = Rx & D5 = Tx
SoftwareSerial nodemcu(D3, D5);
char json[] = "test";

void setup() {
  // Initialize Serial port
  Serial.begin(9600);
  nodemcu.begin(9600);
  while (!Serial) continue;
}

void loop() {
  
  StaticJsonDocument<1000> jsonBuffer;
  //JsonObject& data = jsonBuffer.parseObject(nodemcu);
  deserializeJson(jsonBuffer,nodemcu);

//  if (data == JsonObject::invalid()) {
//    //Serial.println("Invalid Json Object");
//    jsonBuffer.clear();
//    return;
//  }

  Serial.println("JSON Object Recieved");
  Serial.print("Recieved Humidity:  ");
  float hum = jsonBuffer["humidity"];
  Serial.println(hum);
  Serial.println("-----------------------------------------");
}
