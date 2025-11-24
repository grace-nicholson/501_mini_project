#include <ArduinoMqttClient.h>
#include <WiFiNINA.h>
#include "Arduino_BHY2Host.h"

Sensor temp(SENSOR_ID_TEMP);
Sensor humid(SENSOR_ID_HUM);
SensorBSEC bsec(SENSOR_ID_BSEC);

///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = "grace";        // your network SSID (name)
char pass[] = "beanbean";    // your network password (use for WPA, or use as key for WEP)

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

const char broker[] = "pf-uyp85ksb0tbt7jocc1qo.cedalo.cloud";
int        port     = 1883;
const char topic1[] = "joetopic1";
const char topic2[] = "joetopic2";
const char topic3[] = "joetopic3";


//set interval for sending messages (milliseconds)
const long interval = 5000;
unsigned long previousMillis = 0;

int count = 0;

void setup() {

  Serial.begin(115200);
  while(!Serial);
  BHY2Host.begin();

  temp.begin();
  humid.begin();
  bsec.begin();

  // attempt to connect to Wifi network:
  Serial.print("Attempting to connect to WPA SSID: ");
  Serial.println(ssid);
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    // failed, retry
    Serial.print(".");
    delay(5000);
  }

  Serial.println("You're connected to the network");
  Serial.println();

  Serial.print("Attempting to connect to the MQTT broker: ");
  Serial.println(broker);

  if (!mqttClient.connect(broker, port)) {
    Serial.print("MQTT connection failed! Error code = ");
    Serial.println(mqttClient.connectError());

    while (1);
  }

  Serial.println("You're connected to the MQTT broker!");
  Serial.println();
}

void loop() {
  // call poll() regularly to allow the library to send MQTT keep alive which
  // avoids being disconnected by the broker
  mqttClient.poll();
  //BHY2Host.update();


  static auto printTime = millis();
  BHY2Host.update();

  if (millis() - printTime >= 30000) {
    // save the last time a message was sent
    printTime = millis();

    //record random value from A0, A1 and A2
    //float Rvalue1 = temp.value();
    //float Rvalue2 = humid.value();
   // float Rvalue3 = bsec.value();

    Serial.print("Sending message to topic1: ");
    Serial.println(topic1);
    Serial.println(temp.value());

    Serial.print("Sending message to topic2: ");
    Serial.println(topic2);
    Serial.println(bsec.toString());

    Serial.print("sending message to topic3: ");
    Serial.println(topic3);
    Serial.println(humid.value());

    // send message, the Print interface can be used to set the message contents
    mqttClient.beginMessage(topic1);
    mqttClient.print(temp.value());
    mqttClient.endMessage();

    mqttClient.beginMessage(topic2);
    mqttClient.print(bsec.toString());
    mqttClient.endMessage();

   mqttClient.beginMessage(topic3);
   mqttClient.print(humid.value());
   mqttClient.endMessage();
    
    Serial.println();
  }
}
