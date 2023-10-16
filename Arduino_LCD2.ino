// include the library code:
#include <LiquidCrystal.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

}
void loop() {
  lcd.setCursor(2, 0);
  lcd.print("WELL-COME to");
  lcd.setCursor(2, 1);
  lcd.print("MICRODIGISOFT");
  //delay(1000);
  delay(1000);
  // Turn on the blinking cursor:
  lcd.clear();
  delay(1000);
}