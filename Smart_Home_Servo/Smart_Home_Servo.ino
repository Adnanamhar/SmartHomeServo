
#define BLYNK_PRINT Serial

// Setting Library
#include <ESP8266WiFi.h> /* untuk modul wifi */
#include <BlynkSimpleEsp8266.h> /* file untuk blynk */
#include <Servo.h>


char auth[] = "YourAuthToken";
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

/* devinisi fungsi Servo */ 
Servo servo;

BLYNK_WRITE(V1)
{
  servo.write(param.asInt());
  // Fungsi Blynk untuk mengatur nilai sevo dengan pin virtual V1 yang ada pada aplikasi blynk
}

void setup()
{
  // Debug console
  Serial.begin(9600); // memulai serial monitor dengan baudrate 9600

  Blynk.begin(auth, ssid, pass); // menjalankan blynk sesuai token,wifi,dan passwordnya

  servo.attach(2); // setting pin gpio 2 ke Servo,D4  = 2
}

void loop()
{
  Blynk.run();
}
