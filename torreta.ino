#include <Servo.h>
  
Servo servo1;
Servo servo2;
int joyX = 0; // entrada del para eje x
int joyY = 1; // entrada del para eje y
int joyPulse = 2; // todavia no sabemos que componente usar para disparar
int servoValX;
int servoValY;
  
void setup() 
{
  servo1.attach(3); // out de pines digitales PWM hacia el servomotor
  servo2.attach(5); // attach, funcion para conectar servos y convertir los 0-255 en 0-180 grados
  pinMode(joyPulse, INPUT_PULLUP);
  int botonEstado = digitalRead(joyPulse);

if (botonEstado == 0) { // Botón presionado
    Serial.println(botonEstado);
    // Secuencia de movimientos de ejemplo
    // servo3.write(90);
    // delay(500);
    // servo3.write(0);
}

  serial.begin(115200);
}
  
void loop()
{
  
  servoValX = analogRead(joyX);
  servoValX = map(servoValX, 0, 1023, 0, 180);
  servo1.write(servoValX); // valor de rotacion mandada a pwm, servo 1 

  servoValY = analogRead(joyY);
  servoValY = map(servoValY, 0, 1023, 70, 180);
  servo2.write(servoValY); // valor de rotacion mandada a pwm, servo 2
  delay(15);  
}
