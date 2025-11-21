#include <ArduinoMqttClient.h>
#include <WiFiNINA.h>
#include "Arduino_BHY2Host.h"
Sensor temp(SENSOR_ID_TEMP);
Sensor humid(SENSOR_ID_HUM);
Sensor air_q(SENSOR_ID_BSEC);

///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = "Glide_Resident";        // your network SSID (name)
char pass[] = "SiloShelfHuman";    // your network password (use for WPA, or use as key for WEP)

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

const char broker[] = "test.mosquitto.org";
int        port     = 1883;
const char topic1[] = "gracetopic1";
const char topic2[] = "gracetopic2";
const char topic3[] = "gracetopic3";


//set interval for sending messages (milliseconds)
const long interval = 5000;
unsigned long previousMillis = 0;

int count = 0;

void setup() {

  Serial.begin(115200);
  BHY2Host.begin();
  temp.begin();
  humid.begin();
  air_q.begin();

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
  BHY2Host.update();

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time a message was sent
    previousMillis = currentMillis;

    //record random value from A0, A1 and A2
    float Rvalue1 = temp.value();
    float Rvalue2 = humid.value();
    float Rvalue3 = air_q.value();

    Serial.print("Sending message to topic1: ");
    Serial.println(topic1);
    Serial.println(Rvalue1);

    Serial.print("Sending message to topic2: ");
    Serial.println(topic2);
    Serial.println(Rvalue2);

    Serial.print("sending message to topic3: ");
    Serial.println(topic3);
    Serial.println(Rvalue3);

    // send message, the Print interface can be used to set the message contents
    mqttClient.beginMessage(topic1);
    mqttClient.print(Rvalue1);
    mqttClient.endMessage();

    mqttClient.beginMessage(topic2);
    mqttClient.print(Rvalue2);
    mqttClient.endMessage();

    mqttClient.beginMessage(topic3);
    mqttClient.print(Rvalue3);
    mqttClient.endMessage();
    
    Serial.println();
  }
}