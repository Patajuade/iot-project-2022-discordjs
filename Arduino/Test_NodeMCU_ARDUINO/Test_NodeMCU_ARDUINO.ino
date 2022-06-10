//ThatsEngineering
//Sending Data from Arduino to NodeMCU Via Serial Communication
//Arduino code

//DHT11 Lib
//#include <DHT.h>

//Arduino to NodeMCU Lib
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

//Initialise Arduino to NodeMCU (5=Rx & 3=Tx)
SoftwareSerial nodemcu(5, 3);

//Initialisation of DHT11 Sensor
//#define DHTPIN 4
//DHT dht(DHTPIN, DHT11);
float temp;
float hum;
float num;
char json[] = "test";

void setup() {
  Serial.begin(9600);

  //dht.begin();
  nodemcu.begin(9600);
  delay(1000);

  Serial.println("Program started");
}

void loop() {
  //StaticJsonBuffer<1000> jsonBuffer;
  StaticJsonDocument<1000> jsonBuffer; //change buffer into document because of Json V6...
  //JsonObject& data = jsonBuffer.createObject(); //What will store the sensor reading
  deserializeJson(jsonBuffer,nodemcu);
  
  

  //Obtain Temp and Hum data
  dht11_func();


  //Assign collected data to JSON Object
  jsonBuffer["humidity"] = hum;
  jsonBuffer["temperature"] = temp; 

  //Send data to NodeMCU
  //jsonBuffer.printTo(nodemcu); //printTo doesn't exist in Json V6, we replace it with :
  serializeJson(jsonBuffer, Serial);
  
  jsonBuffer.clear();

  delay(2000);
}

void dht11_func() {

  hum = 9999;
  temp = 9999;
  Serial.print("Humidity: ");
  Serial.println(hum);
  Serial.print("Temperature: ");
  Serial.println(temp);

}
