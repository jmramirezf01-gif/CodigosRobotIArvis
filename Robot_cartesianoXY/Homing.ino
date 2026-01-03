void configurarHardware() {
  // Ajustes de los motores
  stepperX1.setMaxSpeed(VEL_MAX);  stepperX1.setAcceleration(ACEL); 
  stepperX2.setMaxSpeed(VEL_MAX);  stepperX2.setAcceleration(ACEL);
  stepperY.setMaxSpeed(VEL_MAX);   stepperY.setAcceleration(ACEL);

  // Sensores
  pinMode(limitPinX, INPUT);
  pinMode(limitPinY, INPUT);
}

void ejecutarHoming() {
  // --- PASO 1: EJE X ---
  Serial.println("Calibrando Eje X...");
  stepperX1.moveTo(15000); // Valor alto para asegurar que llegue al sensor
  stepperX2.moveTo(15000);
  
  while (digitalRead(limitPinX) == HIGH) {
    stepperX1.run();
    stepperX2.run();
  }
  stepperX1.stop(); stepperX2.stop();
  stepperX1.setCurrentPosition(0); stepperX2.setCurrentPosition(0);

  // Alejar X a posición segura
  stepperX1.moveTo(DIST_SEGURIDAD);
  stepperX2.moveTo(DIST_SEGURIDAD);
  esperarMotores();

  delay(500);

  // --- PASO 2: EJE Y ---
  Serial.println("Calibrando Eje Y...");
  stepperY.moveTo(15000);
  
  while (digitalRead(limitPinY) == HIGH) {
    stepperY.run();
  }
  stepperY.stop();
  stepperY.setCurrentPosition(0);

  // Alejar Y a posición segura
  stepperY.moveTo(DIST_SEGURIDADY);
  esperarMotores();
  
  Serial.println("Homing finalizado con exito.");
}

void esperarMotores() {
  while (stepperX1.distanceToGo() != 0 || stepperX2.distanceToGo() != 0 || stepperY.distanceToGo() != 0) {
    stepperX1.run();
    stepperX2.run();
    stepperY.run();
  }
}