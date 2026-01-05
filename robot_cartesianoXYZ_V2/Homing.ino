void configurarHardware() {
  stepperX1.setMaxSpeed(VEL_MAX);  stepperX1.setAcceleration(ACEL); 
  stepperX2.setMaxSpeed(VEL_MAX);  stepperX2.setAcceleration(ACEL);
  stepperY.setMaxSpeed(VEL_MAX);   stepperY.setAcceleration(ACEL);
  
  // Z más lento para ganar torque en el tornillo y calentar menos el driver
  stepperZ.setMaxSpeed(400);       
  stepperZ.setAcceleration(200); 

  pinMode(limitPinX, INPUT);
  pinMode(limitPinY, INPUT);
  pinMode(limitPinZ, INPUT); 
}

void ejecutarHoming() {
  Serial.println("--- Iniciando Homing Secuencial ---");

  // PASO 1: EJE Z (SUBIR)
  Serial.println("1. Calibrando Z...");
  stepperZ.moveTo(-9000); // Sube buscando el botón // -10000
  while (digitalRead(limitPinZ) == HIGH) { 
    stepperZ.run();
  }
  stepperZ.setSpeed(0);
  stepperZ.setCurrentPosition(0); 
  
  // RETROCEDE (Baja a altura de vuelo)
  stepperZ.moveTo(Z_SEGURIDAD);
  esperarMotores(); 
  Serial.println("Z listo.");

  // PASO 2: EJE X
  Serial.println("2. Calibrando X...");
  stepperX1.moveTo(15000); stepperX2.moveTo(15000);
  while (digitalRead(limitPinX) == HIGH) {
    stepperX1.run(); stepperX2.run();
  }
  stepperX1.setCurrentPosition(0); stepperX2.setCurrentPosition(0);
  stepperX1.moveTo(DIST_SEGURIDAD); stepperX2.moveTo(DIST_SEGURIDAD);
  esperarMotores();

  // PASO 3: EJE Y
  Serial.println("3. Calibrando Y...");
  stepperY.moveTo(15000);
  while (digitalRead(limitPinY) == HIGH) {
    stepperY.run();
  }
  stepperY.setCurrentPosition(0);
  stepperY.moveTo(DIST_SEGURIDAD); // Tu ajuste personalizado
  esperarMotores();
  
  Serial.println("--- Sistema Calibrado ---");
}

void esperarMotores() {
  // AHORA SÍ VIGILA A LOS 4 MOTORES
  while (stepperX1.distanceToGo() != 0 || stepperX2.distanceToGo() != 0 || 
         stepperY.distanceToGo() != 0 || stepperZ.distanceToGo() != 0) {
    stepperX1.run();
    stepperX2.run();
    stepperY.run();
    stepperZ.run();
  }
}