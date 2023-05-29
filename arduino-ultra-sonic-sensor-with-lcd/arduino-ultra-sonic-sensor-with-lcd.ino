#include <Arduino.h>

// Variables
long duration; // variable for the duration of sound wave travel
int distance;  // variable for the distance measurement
int distanceOldState;

// PINS
int trigPin = A0;
int echoPin = A1;
int relay = A2;

void setup()
{

    pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
    pinMode(echoPin, INPUT);  // Sets the echoPin as an INPUT

    pinMode(relay, OUTPUT);
}
void loop()
{
    // Clears the trigPin condition
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds

    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

    if (distance != distanceOldState)
    {
        if (distance >= 60)
        {
            digitalWrite(relay, LOW);
        }
        else
        {
            digitalWrite(relay, HIGH);
        }

        delay(300);
    }
    distanceOldState = distance;
}