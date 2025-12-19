// Control de un motor a pasos con driver DRV8825 y arduino MEGA 
#include "AccelStepper.h"

// Definiendo las conexiones del motor 

// Motor 1
#define dirPin 2 
#define stepPin 3
#define motorInterfaceType 1
#define limitpin 9

int val = 0;

// Motor 2 
// #define dirPin2 4 
// #define stepPin2 5
// #define limitpin1 10


// Creando una nueva instancia de la clase AccelStepper
// Motor 1
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin); 

// Motor 2 
//AccelStepper stepper2 = AccelStepper(motorInterfaceType, stepPin, dirPin);


//bool moving = true;


void setup() {

  /*En esta seccion se establece el setpoint de cada carro del riel*/
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(500);
  stepper.setSpeed(500);
  //stepper2.setMaxSpeed(500);


  // Seccion donde se define al pin de datos del limite de carrera como INPUT
  pinMode(limitpin, INPUT);
  val = digitalRead(limitpin); 

  // El ciclo while permite que el carrete se desplace mientras no se presione 
  // el boton del final de carrera
  while (val == HIGH){
    stepper.setSpeed(-500);
    stepper.runSpeed();
    val = digitalRead(limitpin);
  }

  //
  stepper.setCurrentPosition(0);
  Serial.print("\nReferencia encontrada");
  stepper.runToNewPosition(4000);
  stepper.setCurrentPosition(0);
  stepper.stop();
  delay(4000);

}
/*  Esta seccion se encarga de mover el motor hasta cierta posicion 
    una vez que se establece el setpoint*/
void loop() {

  stepper.moveTo(-4000);
  while(stepper.distanceToGo() != 0){
    stepper.run();
  }
  

}
