// Control de un motor a pasos con driver DRV8825 en Arduino MEGA
#include "AccelStepper.h"

// --- 1. DEFINICIÓN DE PINES Y PARÁMETROS (ARDUINO MEGA GPIO) ---
// Usando pines digitales comunes del Arduino MEGA
#define dirPin 2         // Pin de Dirección del Motor (Ej: Digital 2)
#define stepPin 3        // Pin de Paso del Motor (Ej: Digital 3)
#define motorInterfaceType 1 // Interfaz DRIVER (Paso/Dirección)


#define dirPin2 4   // Pin de Direccion del motor 2 ()
#define stepPin2 5 // Pin de Paso del motor 2


// --- 2. PARAMETROS DE TIEMPO Y VELOCIDAD ---
const long tiempoDeGiro = 7000;     // Tiempo que girará en una direccion (en milisegundos)
const float velocidadPositiva = 240.0; // Velocidad de giro en un sentido (pasos/seg)
const float velocidadNegativa = -240;  // Velocidad de giro en el sentido opuesto (pasos/seg)

// --- 3. VARIABLES DE ESTADO -- 
unsigned long tiempoAnterior = 0; // Para almacenar el ultimo momento de cambio de direccion 

// Creando una nueva instancia de la clase AccelStepper
// Motor 1
AccelStepper stepperX = AccelStepper(motorInterfaceType, stepPin, dirPin); 

// Motor 2 
AccelStepper stepperY = AccelStepper(motorInterfaceType, stepPin2, dirPin2);


void setup() {
    Serial.begin(9600); // Usamos 9600 baudios
    Serial.println("Control de Motor Continuo en Arduino MEGA.");
    
    // Establece la velocidad máxima de pasos por segundo
    stepperX.setMaxSpeed(1000.0);

    // Establece velocidad Maxima de pasos por segundo para segundo motor
    stepperY.setMaxSpeed(1000.0); 
    
    // Establece la aceleración para movimientos suaves
    stepperX.setAcceleration(500.0); 

    // Establece la aceleracion para movimientos suaves de segundo motor 
    stepperY.setAcceleration(500.0); 


    // Inicializa el motor girando en la primera direccion 
    stepperX.setSpeed(velocidadPositiva);
    stepperY.setSpeed(velocidadPositiva);

    tiempoAnterior = millis(); 
}

void loop() {

    // --- 4. LÓGICA DE CAMBIO DE DIRECCION ---
    if (millis() - tiempoAnterior >= tiempoDeGiro){
      // Si la velocidad actual es positiva, la cambia a negativa
      if (stepperX.speed() > 0  && stepperY.speed() > 0){
        stepperX.setSpeed(velocidadNegativa);
        stepperY.setSpeed(velocidadNegativa);
        Serial.println("Cambiando de direccion: Sentido Negativo");
      }
      else{
        stepperX.setSpeed(velocidadPositiva);
        stepperY.setSpeed(velocidadPositiva);
        Serial.println("Cambiando de direccion: Sentido Positivo");
      }

      tiempoAnterior = millis();
    }

    // --- 5. EJECUCION DEL MOVIMIENTO

    // runSpeed() ejecuta el movimiento a la velocidad establecida actualmente.
    // Debe llamarse constantemente para que el motor se mueva.
    stepperX.runSpeed();
    stepperY.runSpeed();
}