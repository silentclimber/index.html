#include <ThingSpeak.h>
#include <ESP8266WiFi.h>

int PulseSensorPurplePin = A0;
int data;

WiFiClient client;
long myChannelNumber = 578494;
const char myWriteAPTkey[] = "";

void setup(){
Serial.begin(115200);
WiFi.begin("","");
while(WiFi.status() != WL_CONNECTED)
{
  delay(200);
  Serial.println("connecting....\n");
}
Serial.println();
Serial.println("NodeMCU is connected!");
Serial.println(WiFi.localIP());
ThingSpeak.begin(client);
}

void loop(){
if (data > 549 ){
  data = analogRead(PulseSensorPurplePin);
  Serial.println("Your Heart-beat is:");
  Serial.begin(data);
  ThingSpeak.writeField(myChannelNumber, 1, data, myWriteAPTkey);
  delay(10);
  }
else{
  Serial.println();

}
delay(200);
}
