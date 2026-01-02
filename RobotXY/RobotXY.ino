#include "AccelStepper.h"
#include "Configuracion.h"

// Instancias de los motores 
AccelStepper stepperX1(motorInterfaceType, stepX1, dirX1);
AccelStepper stepperX2(motorInterfaceType, stepX2, dirX2);
AccelStepper stepperY(motorInterfaceType, stepY, dirY);


void setup() {
  Serial.begin(9600);
  
  configurarHardware(); // Configurando velocidades y pines 
  ejecutarHoming(); // Realizando calibracion secuencial

  Serial.println("Robot listo para ejecuacion de actividades.");

}

void loop() {
  dibujarCuadrado();

}
