#include "AccelStepper.h"
#include "Configuracion.h"

AccelStepper stepperX1(motorInterfaceType, stepX1, dirX1); 
AccelStepper stepperX2(motorInterfaceType, stepX2, dirX2);
AccelStepper stepperY(motorInterfaceType, stepY, dirY);
AccelStepper stepperZ(motorInterfaceType, stepZ, dirZ); // Nuevo motor

void setup() {
  Serial.begin(9600);
  configurarHardware(); 
  
  /*// Prueba rápida de salud del motor Z
  Serial.println("Prueba motor Z...");
  stepperZ.runToNewPosition(800); 
  stepperZ.runToNewPosition(0);*/
  
  ejecutarHoming();     
  Serial.println("Robot listo.");
}

void loop() {
  // Ejecuta la secuencia
  teclearPIN(1, 2, 3, 0); 
  
  // Espera 10 segundos antes de repetir para que no se sobrecalienten los drivers
  Serial.println("Esperando 10 segundos...");
  delay(10000);
}