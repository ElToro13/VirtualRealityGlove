const int trigPin = 2;
const int echoPin = 4;
#include <Servo.h>
Servo myservo;
int p=0;
int c=0;
void setup() {
 myservo.attach(9);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}
long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}

void loop()
{

  long duration, inches, cm;

  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);


  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  if(cm<=5 || (cm>=8 && cm<=10)){
   
   
     myservo.write(110);  // Servo pull angle
  }
  else{
     c&=0;
     myservo.write(0);
    // digitalWrite(13,LOW);
  }
  
  //Serial.print(inches);
 // Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(100);
}


