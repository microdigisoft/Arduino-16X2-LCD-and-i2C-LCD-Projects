#include <DHT.h>// Import DHT sensor Library
#include <DHT_U.h>
#define Type DHT11
#include <LiquidCrystal.h>// Import LCD library
int rs = 12; // Initialize pin 12 for RS pin of LCD
int en = 11; // Initialize pin 11 for Enable pin of LCD
int d4 = 5; // Initialize pin 5 for D4 pin of LCD
int d5 = 4; // Initialize pin 4 for D5 pin of LCD
int d6 = 3; // Initialize pin 3 for D6 pin of LCD
int d7 = 2; // Initialize pin 2 for D7 pin of LCD
int ledPin1 = 7; // Initialize pin 7 for LED1
int ledPin2 = 6; // Initialize pin 6 for LED2
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Initialize LCD with 4bit mode

int sensePin = A0; // Read DHT sensor data at analog pin A0
DHT HT(sensePin, Type); // Enable DHT11 sensor
float humidity;// Variable to read humidity
float temperature;// Variable to read temperature

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);
  HT.begin();
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);

  lcd.begin(16, 2);
  lcd.setCursor(4, 0);
  lcd.print("Hello!");
  lcd.setCursor(0, 1);
  lcd.print(" Microdigisoft");
  delay(5000);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  lcd.clear();
}
