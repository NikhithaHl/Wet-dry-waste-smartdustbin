#include <Servo.h>

Servo servo1;

// ---------------- PIN DEFINITIONS ----------------
const int trigPin = 12;
const int echoPin = 11;

int potPin = A0;

const int servoPin = 8;

// ---------------- VARIABLES ----------------
long duration;
int distance = 0;

int soil = 0;
int fsoil = 0;

int maxDryValue = 1;
int Ultra_Distance = 15;

// ---------------- SETUP ----------------
void setup()
{
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  servo1.attach(servoPin);

  servo1.write(90);

  Serial.println("Soil Sensor Ultrasonic Servo");
}

// ---------------- MAIN LOOP ----------------
void loop()
{
  soil = 0;
  distance = 0;

  // -------- DISTANCE MEASUREMENT --------
  for (int i = 0; i < 2; i++)
  {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(7);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);

    digitalWrite(trigPin, LOW);
    delayMicroseconds(10);

    duration = pulseIn(echoPin, HIGH);

    distance = duration * 0.034 / 2 + distance;

    delay(10);
  }

  distance = distance / 2;

  // -------- OBJECT DETECTION --------
  if (distance < Ultra_Distance && distance > 1)
  {
    delay(1000);

    // -------- MOISTURE MEASUREMENT --------
    for (int i = 0; i < 3; i++)
    {
      soil = analogRead(potPin);

      soil = constrain(soil, 485, 1023);

      fsoil = map(soil, 485, 1023, 100, 0) + fsoil;

      delay(75);
    }

    fsoil = fsoil / 3;

    // -------- DISPLAY VALUES --------
    Serial.print("Humidity: ");
    Serial.print(fsoil);

    Serial.print("% Distance: ");
    Serial.print(distance);
    Serial.print(" cm");

    // -------- WASTE CLASSIFICATION --------
    if (fsoil > maxDryValue)
    {
      delay(1000);

      Serial.println(" ==> WET Waste");

      servo1.write(170);

      delay(3000);
    }
    else
    {
      delay(1000);

      Serial.println(" ==> Dry Waste");

      servo1.write(10);

      delay(3000);
    }

    // -------- RETURN SERVO TO CENTER --------
    servo1.write(90);
  }

  // -------- RESET --------
  distance = 0;
  fsoil = 0;

  delay(1000);
}
