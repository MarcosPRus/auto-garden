/* Comment this out to disable prints and save space */
// #define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "4ebFtInjRmLLzYoi6xhy5m_JsgmrEK_A";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ONO6718";
char pass[] = "Yr57hEBV3mkr";

BlynkTimer timer;

int level = 0;
long freq = 1000L;


void readAllSensors(){
  //TODO Implementar codigo multiplexor
  level = analogRead(A0);
  Blynk.virtualWrite(V5, level); 
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  //Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  timer.setInterval(freq, readAllSensors);
}

void loop()
{
  Blynk.run();
  timer.run();
  //TODO Implementar deep sleep
}
