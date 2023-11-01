#include <Servo.h> // esto inclluye la lib
Servo servo0; // esto capta el servo
int angulo = 0; // angulo al que dobla 
int ejex = A1; // eje x del arduino
int ejey = A2; // eje y del arduino
int sel = 4; // movimiento del joystick
int LED = 5; 

void setup() {
servo0.attach(7); // conexion del servo
pinMode(sel, INPUT_PULLUP); 
}

void loop() {
  angulo =  map( analogRead(A1), 0, 1024, 0, 180);
        servo0.write(angulo);
        if ( ! digitalRead(sel))
              digitalWrite(LED, HIGH);
        else
              digitalWrite(LED, LOW);
        delay(250) ;

}
