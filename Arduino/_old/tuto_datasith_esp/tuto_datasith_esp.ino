#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>

ESP8266WebServer server;
char* ssid = "VOO-036325";
char* password = "JGHYYJQW";

void setup()
{
  WiFi.begin(ssid,password);
  Serial.begin(9600);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/",handleIndex);
  server.begin();
}

void loop()
{
  server.handleClient();
}

void handleIndex()
{
  // Send a JSON-formatted request with key "type" and value "request"
  // then parse the JSON-formatted response with keys "gas" and "distance"
  DynamicJsonDocument doc(1024);
  double num = 0;
  // Sending the request
  doc["type"] = "request";
  serializeJson(doc,Serial);
  // Reading the response
  boolean messageReady = false;
  String message = "";
  while(messageReady == false) { // blocking but that's ok
    if(Serial.available()) {
      message = Serial.readString();
      messageReady = true;
    }
  }
  // Attempt to deserialize the JSON-formatted message
  DeserializationError error = deserializeJson(doc,message);
  if(error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return;
  }
  num = doc["num"];
  // Prepare the data for serving it over HTTP
  String output = "num : " + String(num);
  // Serve the data as plain text, for example
  server.send(200,"text/plain",output);
}