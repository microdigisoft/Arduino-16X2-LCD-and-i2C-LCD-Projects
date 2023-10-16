#include <LiquidCrystal_I2C.h >
LiquidCrystal_I2C lcd(0x20, 16, 2); //initialize 16x2 LCD display
int R_LED = 8; // initilize pin8 for RED LED
int Y_LED = 9; // initilize pin9 for YELLOW LED
int G_LED = 10;// initilize pin10 for GREEN LED
void setup() {
  lcd.begin(16, 2);//
  lcd.init(); // Initialize LCD
  // Set the pin modes of the above IO pins to OUTPUT
  pinMode(R_LED, OUTPUT); // Define RED LED as output
  pinMode(Y_LED, OUTPUT);// Define YELLOW LED as output
  pinMode(G_LED, OUTPUT);// Define GREEN LED as output
  lcd.setCursor(2, 0);// Set LCD cursor position
  // Print a message to the LCD.
  lcd.backlight();//Turn on Backlight
  lcd.print("  Hello!");
  lcd.setCursor(0, 1);
  lcd.print(" Microdigisoft");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("    Digital    ");
  lcd.setCursor(0, 1);
  lcd.print("  Thermometer   ");
  delay(1000);
  lcd.clear();
}
void loop() {
  float vol = analogRead(A0) * (5.0 / 1024.0) * 100; //analog pin A0 to read the temperature sensor voltage
  delay(10);
  // Result Display in lcd
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Temperature");
  lcd.setCursor(4, 1);
  lcd.print(vol);//Print voltage
  lcd.write(0);
  lcd.print("C");
  delay(1000);
  if (vol <= 31)//if the temperature is low
  {
    digitalWrite(G_LED, HIGH);// GREEN led on
    digitalWrite(Y_LED, LOW);
    digitalWrite(R_LED, LOW);
  }
  else if (vol >= 32 && vol <= 40)// if the temperature is middle
  {
    digitalWrite(R_LED, LOW);
    digitalWrite(Y_LED, HIGH);//YELLOW led on
    digitalWrite(G_LED, LOW);
  }
  else if (vol >= 41)//If the temperature is HIGH
  {
    digitalWrite(G_LED, LOW);
    digitalWrite(Y_LED, LOW);
    digitalWrite(R_LED, HIGH);// RED led on
  }
  delay(100);
}
