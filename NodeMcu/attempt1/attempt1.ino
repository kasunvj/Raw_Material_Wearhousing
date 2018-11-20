#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>



#define FIREBASE_HOST "https://rawmateriallocalization.firebaseio.com"
#define WIFI_SSID "SPUTNIC SAT 3"
#define WIFI_PASSWORD "ne5551n4001"


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD );
  Serial.print("Connecting");
  while(WiFi.status() != WL_CONNECTED){ Serial.print(".");delay(500);}
  Serial.print("Connected");
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
  // but actually the LED is on; this is because
  // it is active low on the ESP-01)
  delay(500);                      // Wait for a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(500);                      // Wait for two seconds (to demonstrate the active low LED)
}
