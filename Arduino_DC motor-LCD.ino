//dc motor control I LCD display
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C LCD(0x27, 16, 2); // run ic2_scanner sketch and get the IC2 address, which is 0x3f in my case, it could be 0x3f in many cases
int motorPin1 = 8;//initialize pin8 for motor1
int motorPin2 = 9;//initialize pin9 for motor2
void setup() {

  lcd.init();
  // Set the pin modes of the above IO pins to OUTPUT
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  lcd.setCursor(2, 0);

  // Print a message to the LCD.
  lcd.backlight();
  lcd.print("  Hello!");
  lcd.setCursor(0, 1);
  lcd.print(" Microdigisoft");
  delay(5000);
}

void loop()
{
  clockwise();//motor rotate in forward direction
  delay(5000);
  brake(); //stop the motor
  delay(2000);
  anticlockwise();// motor rotate in backward direction
  delay(5000);
  brake();//stop the motor
  delay(2000);

}

void clockwise()   //motor rotate in forward direction
{
  lcd.clear();
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  lcd.setCursor(2, 0);
  lcd.print("  Go Forward");
}
void anticlockwise()  // motor rotate in backward direction
{
  lcd.clear();
  digitalWrite(motorPin1, LOW );
  digitalWrite(motorPin2, HIGH);
  lcd.setCursor(2, 0);
  lcd.print(" Go Backward    ");
}
void brake()       // No rotation OR delay
{
  lcd.clear();
  digitalWrite(motorPin1, LOW );
  digitalWrite(motorPin2, LOW);
  lcd.setCursor(2, 0);
  lcd.print("    STOP    ");

}
