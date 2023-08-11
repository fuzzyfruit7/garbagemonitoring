//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
const int trigPin = 7;
const int echoPin = 6;
long duration;
int distance;
int buzzer=A0;
void setup()
{
  pinMode(buzzer, OUTPUT);digitalWrite(buzzer,LOW);
   pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hello, world!");
  lcd.setCursor(2,1);
  lcd.print("Ywrobot Arduino!");
   
}


void loop()
{
   digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  lcd.clear();lcd.print("DISTANCE:");lcd.print(distance);delay(1000);
  if(distance<=10)
  {
    lcd.setCursor(0,1);lcd.print("BIN 95% FULL");delay(1000);
   digitalWrite(buzzer,HIGH);delay(100);digitalWrite(buzzer,LOW);delay(100);
   Serial.println("BIN_FULL");delay(1000);
  }
 else if(distance>10 && distance<20)
  {
    lcd.setCursor(0,1);lcd.print("BIN 33% Empty");delay(1000);
  }
 else if(distance>20 && distance<50)
  {
    lcd.setCursor(0,1);lcd.print("BIN 66% Empty");delay(1000);
  }
 else if(distance>50)
  {
    lcd.setCursor(0,1);lcd.print("BIN Empty");delay(1000);
  }
}