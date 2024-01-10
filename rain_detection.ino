
#define BLYNK_TEMPLATE_ID "TMPL6kGCXF7mI"
#define BLYNK_TEMPLATE_NAME "Weather Monitoring System"
#define BLYNK_AUTH_TOKEN "RI2qfZ9ozSPqf0hBziP7yqMyD3R3na25"
#define BLYNK_PRINT Serial  // Comment this out to disable prints and save space

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "RI2qfZ9ozSPqf0hBziP7yqMyD3R3na25";  //Enter the Auth code which was send by Blink
char ssid[] = "YuvaDesktop";  //Enter your WIFI Name
char pass[] = "Yuva1234";   

#define RAIN_SENSOR_PIN 2  // Define the pin to which the rain sensor is connected

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);  
  pinMode(RAIN_SENSOR_PIN, INPUT);
}

void loop() {
  int rainSensorValue = digitalRead(RAIN_SENSOR_PIN);

  if (rainSensorValue == HIGH) {
    Blynk.virtualWrite(V1,"Not raining");
  } else {
     Blynk.virtualWrite(V1," It's raining!");
  }
}
