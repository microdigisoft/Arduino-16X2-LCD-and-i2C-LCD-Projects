#include <LiquidCrystal_I2C.h>//Import I2C LCD library
#include "DHT.h"                       // Include the DHT library.
#include <DHT_U.h>
#define Type DHT11
#define DHTPIN 2                       // Set the DHT Pin.
#define DHTTYPE DHT11                  // Set the DHT type.

LiquidCrystal_I2C lcd(0x20, 16, 2);// Start LCD veriable
int sensePin = 2;
DHT HT(sensePin, Type);//Initialize DHT sensor with variable to handle DHT11 functions
float humidity; // Variable to hold the reading for humidity
float temperature;// Variable to hold the reading for temperature
int ledPin1 = 9;// Variable to drive led1
int ledPin2 = 10;// Variable to drive led2
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
  delay(1000);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  lcd.clear();
}

void loop() {
  // put your loop code here, to run continuesly:
  humidity = HT.readHumidity();
  temperature = HT.readTemperature();
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
  lcd.setCursor(1, 0);
  lcd.print("  Humidity: ");
  lcd.setCursor(4, 1);
  lcd.print(humidity);
  lcd.print(" %");
  delay(1000);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  lcd.clear();
  delay(1000);
  lcd.setCursor(1, 0);
  lcd.print("Temperature: ");
  lcd.setCursor(4, 1);
  lcd.print(temperature);
  lcd.setCursor(10, 1);
  lcd.print( (char)223);
  lcd.print("C");
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, HIGH);
  delay(1000);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  lcd.clear();
  delay(1000);
}
