#include <Wire.h >
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // run ic2_scanner sketch and get the IC2 address, which is 0x3f in my case, it could be 0x3f in many cases
Servo servo1; //initialize servo
#define trigPin 9 // initilize pin9 for HCSR04 trigger pin
#define echoPin 8 // initilize pin8 for HCSR04 Echo pin
#define led 2 // initilize pin2 for LED
int pos = 0;
void setup()
{
  lcd.begin (16, 2); // begin LCD
  lcd.init(); // Initialize LCD
  lcd.setCursor(2, 0); // Set the cursor

  // Print a message to the LCD.
  lcd.backlight();
  lcd.print("  Hello!");
  lcd.setCursor(0, 1);
  lcd.print(" Microdigisoft");
  delay(5000);

  // initialize the lcd
  Serial.begin (9600);
  servo1.attach(10);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
}
void loop()
{
  lcd.begin(16, 2);
  // clear old screen data
  lcd.clear();
  // text to be dispalyed on the screen
  lcd.setCursor(3, 0);
  lcd.print("OBJECT");
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  lcd.setCursor(0, 1);
  lcd.print ("distance:");
  if (distance <= 20)
  {
    //servo1.write(180);
    Serial.print(distance);
    lcd.print (distance);
    lcd.print ("cm");
    digitalWrite(led, HIGH);
    for (pos = 180; pos > 1; pos -= 1)  // goes from 180 degrees to 0 degrees                                                                                 // in steps of 1 degree
    {
      servo1.write (pos);      // tell servo to go to position in variable 'pos'
      delay (5);          // waits 5ms for the servo to reach the position
    }
    digitalWrite(led, HIGH);
    Serial.println("cm : LED is on ");
    delay(500);
    for (pos = 0; pos < 180; pos += 1) // goes from 0 degrees to 180 degrees
    {
      servo1.write(pos);
      delay(5);

    }
  }
  else {
    Serial.print(distance);
    lcd.print (distance);
    lcd.print ("cm");
    digitalWrite(led, LOW);
    Serial.println(" cm : LED is off ");
    delay(500);
    servo1.write(0);
  }
}
