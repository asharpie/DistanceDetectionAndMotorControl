#include <LiquidCrystal.h>
#include <Stepper.h>


const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int stepsPerRevolution = 2038;
Stepper myStepper = Stepper(stepsPerRevolution,6,7,8,13)
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  lcd.begin(16,2);
  lcd.clear();
}
void loop() {
  // Clears the trigPin
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
  //Serial.print("Distance: ");
  lcd.setCursor(0,0);
  delay(300);
  lcd.clear();
  lcd.print("Distance: ");
  Serial.println(distance);
  lcd.print(distance);
  lcd.print(" cm");
  if(distance<10){
    myStepper.setSpeed(10);
    myStepper.step(stepsPerRevolution);
  }else{
    myStepper.setSpeed(0);
  }
}
