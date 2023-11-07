#include <Servo.h> 
Servo viServo, viServo2, viServo3, viServo4; 
int sensorValue, sensorValue2, sensorValue3, sensorValue4;
int angle, angle2, angle3, angle4; 
 
void setup() {
  Serial.begin(9600); 
  viServo.attach(6);  
  viServo2.attach(7);
  viServo3.attach(8);
  viServo4.attach(9);
  delay(1000);
}

void loop() {
  sensorValue = analogRead(A0);
  sensorValue2 = analogRead(A1);
  sensorValue3 = analogRead(A2);
  sensorValue4 = analogRead(A3);
  
  angle = map(sensorValue,50,515,200,-113);
  angle2 = map(sensorValue2,50,515,200,-113);
  angle3 = map(sensorValue3,50,515,200,-113);
  angle4 = map(sensorValue4,50,515,200,-113);
  
  Serial.println(sensorValue+ sensorValue2+ sensorValue3+ sensorValue4);
  Serial.print("\t");
  Serial.println(angle+ angle2+ angle3+ angle4);
 
  viServo.write(angle);
  viServo2.write(angle2);
  viServo3.write(angle3);
  viServo4.write(angle4);
  delay(107);8
}
