void dibujarCuadrado() {
  Serial.println("Iniciando cuadrado de prueba...");
  
  // Lado 1
  stepperX1.moveTo(DIST_SEGURIDAD - 2000);
  stepperX2.moveTo(DIST_SEGURIDAD - 2000);
  esperarMotores();
  
  // Lado 2
  stepperY.moveTo(DIST_SEGURIDADY - 2000);
  esperarMotores();
  
  // Lado 3
  stepperX1.moveTo(DIST_SEGURIDAD);
  stepperX2.moveTo(DIST_SEGURIDAD);
  esperarMotores();
  
  // Lado 4
  stepperY.moveTo(DIST_SEGURIDADY);
  esperarMotores();
  
  delay(2000);
}