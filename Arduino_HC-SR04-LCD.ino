#define trigPin 13 //Initialize pin13 for HC-SR04 Trigger
#define echoPin 12 //Initialize pin12 for HC-SR04 Echo
#define led 7 //Initialize pini for LED

 #include <LiquidCrystal.h >

// initialize the library with the numbers of the interface pins
const int rs = 11, en = 9, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
pinMode(trigPin, OUTPUT);//Define trigger pin as output
pinMode(echoPin, INPUT);//Define Echo pin as input
pinMode(led, OUTPUT);//Define led pin as input
lcd.begin(16, 2);//Initialize 16x2 LCD display
lcd.setCursor(2,0); // Set LCD cursor
lcd.print("MICRODIGISOFT");//Print LCD
lcd.setCursor(1,1);
lcd.print("Distance Measurment"); //Print LCD
delay(500);
}

void loop()
{
long duration, distance;
digitalWrite(trigPin, LOW); // Added this line
delayMicroseconds(2); // Added this line
digitalWrite(trigPin, HIGH);
delayMicroseconds(10); // Added this line
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1; // Calculate distance, conversion in cm



if (distance <=10)

{ 
  digitalWrite(led,LOW);
   
  //Serial.println("cm : LED is on ");
  lcd.clear( );
 lcd.setCursor(1,0);
lcd.print("Distance = ");
  lcd.print(distance); //output on lcd in centimeter
  lcd.setCursor(14,0);
   lcd.print("cm");
   lcd.setCursor(1,0);
  lcd.print("Object in range ");
  delay(500);
   
}
else {
//lcd.print(distance);
digitalWrite(led,HIGH);
//Serial.println(" cm : LED is off ");
lcd.clear( );
lcd.setCursor(1,0);
lcd.print("Distance = ");
lcd.print(distance); //output on lcd in centimeter
lcd.setCursor(14,0);
lcd.print("cm");
lcd.setCursor(1,0);
lcd.println("Out of  range ");
delay(500);
    
}
}
