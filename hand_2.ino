#include <Servo.h> // Incluir en el programa la libreria servo la cual hace posible la gestion de lo servomotores
Servo viServo, viServo2, viServo3, viServo4; // Esto inicializara la lectura y escritura de los servomotores
int sensorValue, sensorValue2, sensorValue3, sensorValue4; // En esta variable numerica se guardaran los valores que se tomen del stick del joystick
int angle, angle2, angle3, angle4; // En esta otra variable numerica se guardaran los angulos de los servomotores
 
void setup() { // Esta funcion como indica su nombre sirve para establecer reglas antes de la ejecutacion formal del codigo
  Serial.begin(9600); // Esta es la velocidad de trasmision de datos del arduino
  viServo.attach(6);  // Este es el pin donde va conectado el primer servo al arduino 
  viServo2.attach(7); // Este es el pin donde va conectado el segundo servo al arduino
  viServo3.attach(8); // Este es el pin donde va conectado el tercer servo al arduino
  viServo4.attach(9); // Este es el pin donde va conectado el cuarto servo al arduino
  delay(1000); // Despues de 1000ms (1s) de iniciar todo ejecutara la funcion loop
}

void loop() {
 // Las siguientes 4 variables guardaran en orden el valor que reciban los stick del joystick
  sensorValue = analogRead(A0);
  sensorValue2 = analogRead(A1);
  sensorValue3 = analogRead(A2);
  sensorValue4 = analogRead(A3);
  /* 
   Las siguientes 4 variables guardaran el recorrido que hara el joystick
   los parametros del map funcionan asi (valor_base, de minimo, de maximo, a minimo, a maximo) osea que el valor "de minimo" sera el del joystick y "a minimo" el referenciado al servo lo mismo con los maximos
  */
  angle = map(sensorValue,50,515,200,-113);
  angle2 = map(sensorValue2,50,515,200,-113);
  angle3 = map(sensorValue3,50,515,-113,200);
  angle4 = map(sensorValue4,50,515,-113,200);
 
  // Esto imprime en la consola de la computadora los valores tomados
  Serial.println(sensorValue+ sensorValue2+ sensorValue3+ sensorValue4); 
  Serial.print("\t");
  Serial.println(angle+ angle2+ angle3+ angle4);
 // Con esta funcion se hara la escritura al servomotor, osea para donde se movera usando lo guardado en las funciones angle
  viServo.write(angle); 
  viServo2.write(angle2);
  viServo3.write(angle3);
  viServo4.write(angle4);
 // Un pequeño retraso para que el instantaneo de los datos no sea perjudicial
  delay(10);
}
