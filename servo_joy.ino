#include <Servo.h>
const int SW_pin = 2;
const int X_pin = A0;
const int Y_pin = A1;

#define echoPin 7
#define trigPin 8

long duration;
long distance;

Servo myservo;

int val; 

void setup() {
  myservo.attach(9);

  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

void loop() {
  val = analogRead(Y_pin);            
  val = map(val, 0, 1023, 0, 180);    
  myservo.write(val);                 
  delay(15);        

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration/58.2;

  Serial.println(distance);

  delay(50);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration/58.2;

  Serial.println(distance);

  delay(50);  
}
