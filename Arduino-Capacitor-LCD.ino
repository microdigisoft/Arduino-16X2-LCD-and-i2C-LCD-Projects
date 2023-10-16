#include <LiquidCrystal.h> // Import LCD library
LiquidCrystal lcd(6, 7, 2, 3, 4, 5); // Define lcd pin with 4bit mode
int R1 = 8;// Define pin8 for Resistor-1
int R2 = 9;//Define pin8 for Resistor-2
int analogPin = A0;// Analog pin read potential at cap
unsigned long start_timer = 0;
unsigned long stop_timer = 0;
unsigned long duration = 0;
float voltage = 3;
float Capacitance = 0.0;
int solution (void);
void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print(" Measurment");
  lcd.setCursor(0, 1);
  lcd.print("of capacitor ");
  pinMode(R2, INPUT);
  pinMode(R1, OUTPUT);
  digitalWrite(R1, HIGH);
}
//1021 1022 1023
void loop()
{
  while (solution() >= 1010 && solution() <= 1030)
  {
    lcd.setCursor(0, 1);
    lcd.print("place capacitor ");
    delay(200);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    delay(200);
  }
  delay(2000);
  lcd.setCursor(0, 1);
  lcd.print("                ");
  while (1)
  {
    pinMode(R1, INPUT);
    pinMode(R2, OUTPUT);
    digitalWrite(R2, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Discharging-");//12
    while (voltage > 2.0)
    {
      voltage = solution();
      delay(100);
      lcd.setCursor(12, 1);
      Capacitance = voltage * (99.0 / 1023.0); // Calculate Capacitance
      lcd.print((99 - Capacitance), 0);
      lcd.setCursor(14, 1);
      lcd.print("%");
    }

    lcd.setCursor(0, 1);
    lcd.print("                ");
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("charging-");//9
    lcd.setCursor(13, 1);
    lcd.print("%");
    pinMode(R2, INPUT);
    pinMode(R1, OUTPUT);
    digitalWrite(R1, HIGH);
    start_timer = micros();

    while (solution() < 648)
    {
      lcd.setCursor(9, 1);
      lcd.print(solution() * (100.0 / 1023.0), 1);
    }

    stop_timer = micros();
    duration = stop_timer - start_timer;
    Capacitance = duration / 10000;
    lcd.clear();
    // lcd.setCursor(0,1);
    // lcd.print("                ");
    lcd.setCursor(0, 0);
    lcd.print("value = ");
    lcd.print(Capacitance);
    lcd.print("uF");
    delay(3000);
    while (1)
    {
      lcd.setCursor(0, 1);
      lcd.print("   Restart  ");
      delay(200);
      lcd.setCursor(0, 1);
      lcd.print("                ");
      delay(200);
    }

  }
}

int solution (void)
{
  int value;
  value = analogRead(analogPin);
  return value;
}
