#include <ESP8266WiFi.h>
#include <DHT.h>
#include <ThingSpeak.h>
int PulseSensorPurplePin = A0;        // Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0
int LED = D1;   //  The on-board Arduion LED

int Signal;                // holds the incoming raw data. Signal value can range from 0-1024
int Threshold = 550;            // Determine which Signal to "count as a beat", and which to ingore.

DHT dht(D5, DHT11);
WiFiClient client;
long myChannelNumber = 1580288;
const char myWriteAPIKey[] = "1A39RXIDPVTBM2S1";
const char myReadAPIKey[] = "1G2Z5O4AT4PWOV2E";

// The SetUp Function:
void setup() {
  Serial.begin(115200);
  WiFi.begin("PTCL558", "yahyasattar");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
  pinMode(LED,OUTPUT);         // pin that will blink to your heartbeat!
  Serial.begin(115200);         // Set's up Serial Communication at certain speed.
  dht.begin();
  ThingSpeak.begin(client);
}

// The Main Loop Function
void loop() {

  Signal = analogRead(PulseSensorPurplePin);  // Read the PulseSensor's value.
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.println("\nYour heart rate is.");
  Serial.println(Signal);            // Send the Signal value to Serial Plotter.
  Serial.println("Temperature: " + (String) t);  // Assign this value to the "Signal" variable.
  Serial.println("Humidity: " + (String) h);
  ThingSpeak.writeField(myChannelNumber, 1, t, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 2, h, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 3, Signal, myWriteAPIKey);
  
   if(Signal > Threshold){                          // If the signal is above "550", then "turn-on" Arduino's on-Board LED.
     digitalWrite(LED,HIGH);
   } else {
     digitalWrite(LED,LOW);                //  Else, the sigal must be below "550", so "turn-off" this LED.
   }

delay(10);


}
