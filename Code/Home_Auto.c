#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>
// defines pins numbers
const int Speed1 = 16; // NODEMCU Pin D0
const int Speed2 = 5; // NodeMCU Pin D1
const int Speed4 = 4; // NODEMCU Pin D2
const int Lights = 0; // NODEMCU Pin D3
const int BUZZER = 12; // NODEMCU Pin D6
const int TRIGGER = 13; // NodeMCU Pin D7
const int ECHO = 15; // NODEMCU Pin D8
// defines variables
long duration;
int distance;
int safetyDistance;
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Kr9TGf4uGudseIDYm_z_rigzI6w0031M";
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "NodeMCU";
char pass[] = "NodeESP12E";
BLYNK_WRITE(V0)
{
int fan_speed = param.asInt(); // assigning incoming value from pin V0 to a v
ariable
Serial.print("V0 Slider value is: ");
Serial.println(fan_speed);
if (fan_speed == 0)
{
//All realys Off - Fan Off
digitalWrite(Speed1, HIGH);
digitalWrite(Speed2, HIGH);
digitalWrite(Speed4, HIGH);
}
if (fan_speed == 1)
{
//Speed1 Relay On - Fan at speed 1
  digitalWrite(Speed1, HIGH);
digitalWrite(Speed2, HIGH);
digitalWrite(Speed4, HIGH);
delay(500);
digitalWrite(Speed1, LOW);
}
if (fan_speed == 2)
{
//Speed2 Relay On - Fan at speed 2
digitalWrite(Speed1, HIGH);
digitalWrite(Speed2, HIGH);
digitalWrite(Speed4, HIGH);
delay(500);
digitalWrite(Speed2, LOW);
}
if (fan_speed == 3)
{
//Speed1 & Speed2 Relays On - Fan at speed 3
digitalWrite(Speed1, HIGH);
digitalWrite(Speed2, HIGH);
digitalWrite(Speed4, HIGH);
delay(500);
digitalWrite(Speed1, LOW);
digitalWrite(Speed2, LOW);
}
if (fan_speed == 4)
{
//Speed4 Relay On - Fan at speed 4
digitalWrite(Speed1, HIGH);
digitalWrite(Speed2, HIGH);
digitalWrite(Speed4, HIGH);
delay(500);
digitalWrite(Speed4, LOW);
}
// process received value
}
void setup()
{\
  Serial.begin(9600); // Starts the serial communication
Blynk.begin(auth, ssid, pass);
pinMode(TRIGGER, OUTPUT); // Sets the trigPin as an Output
pinMode(ECHO, INPUT); // Sets the echoPin as an Input
pinMode(BUZZER, OUTPUT);
// Debug console
pinMode(Speed1, OUTPUT);
pinMode(Speed2, OUTPUT);
pinMode(Speed4, OUTPUT);
pinMode(Lights,OUTPUT);
//Initially the fan will be in OFF state
digitalWrite(Lights, HIGH);
digitalWrite(Speed1, HIGH);
digitalWrite(Speed2, HIGH);
digitalWrite(Speed4, HIGH);
}
void loop()
{
// Clears the trigPin
digitalWrite(TRIGGER, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(TRIGGER, HIGH);
delayMicroseconds(10);
digitalWrite(TRIGGER, LOW);
// Reads the echoPin, returns the sound wave travel time in mic
roseconds
duration = pulseIn(ECHO, HIGH);
// Calculating the distance
distance= duration*0.034/2;
safetyDistance = distance;
if (safetyDistance>=5 && safetyDistance<=20)
{
digitalWrite(BUZZER, HIGH);
delay(2000);
digitalWrite(BUZZER,LOW);
delay(2000);
Serial.println("Bell Ringing...Some one is behind the doo
r");
// Prints the distance on the Serial Monitor
Serial.println("Distance : ");
Serial.println(safetyDistance);
}
else
{
digitalWrite(BUZZER, LOW);
}
Blynk.run();
}
