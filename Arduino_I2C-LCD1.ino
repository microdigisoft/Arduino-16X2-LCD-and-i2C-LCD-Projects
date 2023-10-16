// include the library code:
#include < Wire.h >
#include < LiquidCrystal_I2C.h >
LiquidCrystal_I2C lcd(0x27, 16, 2); // run ic2_scanner sketch and get the IC2 address, which is 0x3f in my case,it could be 0x3f in many cases

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
void setup() {

  lcd.init();

  // set up the LCD's number of columns and rows:
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("  Hello!");
  lcd.setCursor(0, 1);
  lcd.print(" Microdigisoft");
  delay(1000);

  void loop() {}
