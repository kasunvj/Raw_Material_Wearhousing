////////////Linea NMC Proliferation ////IOT device//////////////////////////////////////////////////////////////////////////////////////
////////Developed By Prolifgeration Team//////////////////////////////////////////////////////////////////////////////////////////////
///////////////Authors:::Sampath Gamage,Pradeep Dushyantha,Dinushan Prabhashitha./////////////////////////////////////////////////////

///////////////////////////////////////Library SET////////////////////////////////////////////////////////////////////////////////////////////
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <index.h>///web page predefined
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////DEFINE/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define FIREBASE_HOST "raw-material-localization.firebaseio.com" //"example.firebaseio.com"
#define FIREBASE_AUTH "BLDSJgjuUKtVfnv9ltM3DvnIsbKrxfdFHGjsn1hb"//"token_or_secret"
//////////////////////////////////////////////////////////////////////////////////
#define WIFI_SSID "Dinu"
#define WIFI_PASSWORD "123456789"

////D@rw!n_20!6
ESP8266WebServer server(80); //Server on port 80


///////////////////////////////////////////////////////////////////////////////////


//
//String PNAME = "NMC";
//String MNAME = "HangTag";
String PNAME = "NMC";
String MNAME = "HangTag";
String MSN = "7L0006";
String CYCLES = PNAME + "/" + MNAME + "/" + MSN + "/No_of_cycles";
String DOWNTIME = PNAME + "/" + MNAME + "/" + MSN + "/DownTime";
String STA = PNAME + "/" + MNAME + "/" + MSN + "/Status";
int downtime;
int cycles;
String sta = "";

//const int buttonPin = 2;    // the number of the pushbutton pin
const int ledPin = 13;      // the number of the LED pin

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 10;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
 // Serial.begin(115200);

  



  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);


 // server.on("/", handleRoot);      //Which routine to handle at root location

  server.begin();

  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
   
    Serial.print(".");
    delay(500);
  }
  
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
 

  ////////////////////////////////////////////////////////////firebase initalize parameters of Database//////////////////////////////////////////////////
  /////////////////////////////////////////////////////////// set value
  Firebase.setFloat("number/dinu", 1);
//  Firebase.setInt(CYCLES,1);
//  Firebase.setInt(DOWNTIME,1);
//  Firebase.setString(STA, "Running");
//  //// handle error
//  if (Firebase.failed()) {
//  Serial.print("setting /number failed:");
//  Serial.println(Firebase.error());
//  return;
//  }
//  delay(1000);
  /////////////////////////////////////////Load Firebase DATA/////////////////////////////////////////////////////////////////////////////////////////////////////////////\


  downtime = Firebase.getInt(DOWNTIME);
  cycles = Firebase.getInt(CYCLES);
  sta = Firebase.getString(STA);
  if (Firebase.failed()) {
    Serial.print("setting /number failed:");
    Serial.println(Firebase.error());
    ESP.reset();
    return;
  }

  delay(1000);
  server.handleClient();
  digitalWrite(2,LOW);
  digitalWrite(16,HIGH);
}





void loop() {









 

Firebase.setInt(CYCLES, 232);
digitalWrite(16,HIGH);
if(WiFi.status() != WL_CONNECTED){
  digitalWrite(16,LOW);
  Serial.println("Disconnected");
}
 

  if (Firebase.failed()) {
    Serial.print("setting /number failed:");
    Serial.println(Firebase.error());
    //ESP.restart();
    return;
  }

}
