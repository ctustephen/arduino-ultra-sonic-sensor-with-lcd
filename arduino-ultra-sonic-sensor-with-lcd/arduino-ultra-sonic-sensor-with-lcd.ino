#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // Set the LCD I2C address

// Variables
long duration; // variable for the duration of sound wave travel
int distance;  // variable for the distance measurement
int distanceOldState;

// PINS
int trigPin = A0;
int echoPin = A1;

void setup()
{
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);

    pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
    pinMode(echoPin, INPUT);  // Sets the echoPin as an INPUT
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
        char ch[20];

        snprintf(ch, sizeof(ch), "Distance %dcm", distance);

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(ch);

        delay(300);
    }
    distanceOldState = distance;
}