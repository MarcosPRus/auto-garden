#define BLYNK_TEMPLATE_ID "TMPLrhCJ0pMA"
#define BLYNK_DEVICE_NAME "autogarden beta"

char auth[] = "9Ti1qcom3IewLYNx72JTiz4DnIOU7TXw";

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ONO6718";
char pass[] = "Yr57hEBV3mkr";

int Sensor = A0;
float ratio_resistencias = (9.97+3.2)/9.97;
float offset_div_tension = 0.0;
float Vout = 0.0, Vin = 0.0, Vin_percent = 0.0;

BlynkTimer timer;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Puerto serie conectado.");

  Blynk.begin(auth, ssid, pass);

  timer.setInterval(500L, sendDataEvent);
}

void sendDataEvent() {
  // put your main code here, to run repeatedly:
  Vout = analogRead(Sensor);
  delay(10);

  Vin = (Vout/1024)*3.3*ratio_resistencias + offset_div_tension;
  Vin_percent = map(Vin, 2.8, 4.2, 0, 100);
  
  Blynk.virtualWrite(V0, Vin_percent);
  Blynk.virtualWrite(V2, Vin);
  
  Serial.print("El voltaje de la batería es: ");
  Serial.print(Vin);
  Serial.println ("V");
}

void loop(){
  Blynk.run();
  timer.run();
}
