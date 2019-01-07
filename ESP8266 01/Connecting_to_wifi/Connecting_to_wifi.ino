#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include <FirebaseArduino.h>

#define FIREBASE_HOST "https://rmdb2-4cb82.firebaseio.com" //"example.firebaseio.com"
#define FIREBASE_AUTH "5TPQCYWV3IzVxh5iIrCGZxzk8WqybBzkyATSiOBH"//"token_or_secret"
const char* ssid     = "SPUTNIC SAT 3";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "ne5551n4001";     // The password of the Wi-Fi network


String FABRIC = "Fabrics";
String MATNO = FABRIC +"/Material_No";
String CLRWAY = FABRIC + "/" + MATNO +"/Colour_way";
String LENGTH = FABRIC + "/" + MATNO + "/"+ CLRWAY+ "/Length"; 


void setup() {
  Serial.begin(115200);         // Start the Serial communication to send messages to the computer
  delay(10);
  Serial.println('\n');
  
  WiFi.begin(ssid, password);             // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(ssid); 

  int i = 0;
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print('.');
  }

  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}



void loop() { 
  if (WiFi.status() == WL_CONNECTED){
  Firebase.setInt(MATNO , 2345);
  Serial.println("wrote on firebase");}
  else 
  {Serial.println("Mot connectd");}
  delay(1000);
  }
