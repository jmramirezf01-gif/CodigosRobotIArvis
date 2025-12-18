// Control de un motor a pasos con driver DRV8825
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


bool moving = true;


void setup() {

  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(500);
  stepper.setSpeed(500);
  //stepper2.setMaxSpeed(500);


  pinMode(limitpin, INPUT);
  val = digitalRead(limitpin); 
  while (val == HIGH){
    stepper.setSpeed(-500);
    stepper.runSpeed();
    val = digitalRead(limitpin);
  }

  stepper.setCurrentPosition(0);
  stepper.runToNewPosition(4000);
  stepper.setCurrentPosition(0);





}
/*  Esta seccion se encarga de mover el motor hasta cierta posicion 
    una vez que se establece el setpoint*/
void loop() {

  stepper.moveTo(-400);
  while(stepper.distanceToGo() != 0){
    stepper.run();
  }
  

}
