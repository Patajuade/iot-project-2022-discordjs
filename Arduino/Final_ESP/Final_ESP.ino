//ThatsEngineering
//Sending Data from Arduino to NodeMCU Via Serial Communication
//NodeMCU code

//Include Lib for Arduino to Nodemcu
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

//D6 = Rx & D5 = Tx
SoftwareSerial nodemcu(D5, D3);


void setup() {
  // Initialize Serial port
  Serial.begin(115200);
  nodemcu.begin(115200);
  while (!Serial) continue;
}

void loop() {
  
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& data = jsonBuffer.parseObject(nodemcu);
  
  if (data == JsonObject::invalid()) {
    Serial.println("Invalid Json Object");
    jsonBuffer.clear();
    return;
  }

  Serial.println("JSON Object Recieved");
  Serial.print("Received result:  ");
  int result = data["result"];
  Serial.println(result);
  Serial.println("-----------------------------------------");
}
