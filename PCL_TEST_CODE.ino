#define BLYNK_TEMPLATE_ID "TMPL3lyrO6B3H"
#define BLYNK_TEMPLATE_NAME "PCL"
#define BLYNK_AUTH_TOKEN "QRAbCVx2S-9KrY0gJp_dtljE7M2wU2Gi"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Srishaanth's_11r";
char pass[] = "12345678";

BlynkTimer timer;

// Ultrasonic Pins
#define TRIG 14
#define ECHO 27

// LED Pins
#define GREEN_LED 26
#define ORANGE_LED 25
#define RED_LED 33

// Buzzer
#define BUZZER 32

long duration;
float distance;

// Flood Variables
float sensorHeight = 30.0;

float rawWaterLevel;
float waterLevel;
float previousLevel = 0;
float rateOfRise;
float FRI;

float Hcritical = 20.0;
float Rcritical = 1.5;

String floodStatus;

bool warningBeep = false;

void setup()
{
Serial.begin(115200);

pinMode(TRIG, OUTPUT);
pinMode(ECHO, INPUT);

pinMode(GREEN_LED, OUTPUT);
pinMode(ORANGE_LED, OUTPUT);
pinMode(RED_LED, OUTPUT);

// Passive buzzer
ledcAttach(BUZZER, 2000, 8);

Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

// Read sensor every 1 second
timer.setInterval(1000L, readSensor);

// Warning buzzer timer
timer.setInterval(500L, warningBuzzer);
}

void loop()
{
Blynk.run();
timer.run();
}

void readSensor()
{

// Trigger ultrasonic
digitalWrite(TRIG, LOW);
delayMicroseconds(2);

digitalWrite(TRIG, HIGH);
delayMicroseconds(10);
digitalWrite(TRIG, LOW);

duration = pulseIn(ECHO, HIGH);

distance = duration * 0.034 / 2;


// Raw water level
rawWaterLevel = sensorHeight - distance;

if(rawWaterLevel < 0)
rawWaterLevel = 0;


// Smooth water level
waterLevel = (rawWaterLevel + previousLevel) / 2;


// Rate of Rise
rateOfRise = waterLevel - previousLevel;

if(rateOfRise < 0)
rateOfRise = 0;

previousLevel = waterLevel;


// Flood Risk Index
FRI = (0.6 * (waterLevel / Hcritical)) +
      (0.4 * (rateOfRise / Rcritical));

FRI = constrain(FRI, 0, 1);


// Serial Debug
Serial.print("Distance: ");
Serial.print(distance);

Serial.print(" | Water Level: ");
Serial.print(waterLevel);

Serial.print(" | Rate: ");
Serial.print(rateOfRise);

Serial.print(" | FRI: ");
Serial.println(FRI);


// SAFE
if(FRI < 0.4)
{
digitalWrite(GREEN_LED, HIGH);
digitalWrite(ORANGE_LED, LOW);
digitalWrite(RED_LED, LOW);

ledcWrite(BUZZER, 0);

warningBeep = false;

floodStatus = "Safe";
}


// WARNING
else if(FRI >= 0.4 && FRI < 0.7)
{
digitalWrite(GREEN_LED, LOW);
digitalWrite(ORANGE_LED, HIGH);
digitalWrite(RED_LED, LOW);

warningBeep = true;

floodStatus = "Warning";
}


// DANGER
else
{
digitalWrite(GREEN_LED, LOW);
digitalWrite(ORANGE_LED, LOW);
digitalWrite(RED_LED, HIGH);

ledcWrite(BUZZER, 128);

warningBeep = false;

floodStatus = "Danger";
}


// Send to Blynk
Blynk.virtualWrite(V0, waterLevel);
Blynk.virtualWrite(V1, distance);
Blynk.virtualWrite(V2, floodStatus);
Blynk.virtualWrite(V3, FRI);

}



void warningBuzzer()
{
if(warningBeep)
{
static bool toggle = false;

if(toggle)
ledcWrite(BUZZER, 128);
else
ledcWrite(BUZZER, 0);

toggle = !toggle;
}
}