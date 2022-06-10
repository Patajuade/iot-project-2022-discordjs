#include <ArduinoJson.h>

String message ="";
bool messageReady = false;

void setup() {
  Serial.begin(9600);
}

void loop() {
  while(Serial.available()){
    message = Serial.readString();
    messageReady = true;
  }
  if(messageReady){
    DynamicJsonDocument doc(1024);
    DeserializationError error = deserializeJson(doc,message);
    if(error){
      Serial.print(F("deserialization failed"));
      Serial.println(error.c_str());
      messageReady = false;
      return;
    }
    if(doc["type"]=="request"){
      doc["type"]="response";
      doc["num"] = random(0,21);
      serializeJson(doc,Serial);
    }
    messageReady = false;
  }
//Ici si je lance le moniteur, je peux mimer ce que va envoyer l'esp à l'arduino en tapant {"type":"request"}
}
