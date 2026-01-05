void teclearPIN(int n1, int n2, int n3, int n4) {
  int pin[] = {n1, n2, n3, n4};
  for(int i = 0; i < 4; i++) {
    Serial.print("Yendo a numero: "); Serial.println(pin[i]);
    irANumero(pin[i]);
    delay(200); 
    presionarTecla();
    delay(500);
  }
}

void presionarTecla() {
  Serial.println("Z: Bajando...");
  stepperZ.moveTo(Z_PRESIONAR); // Baja al teclado
  esperarMotores();
  delay(300); 

  Serial.println("Z: Subiendo...");
  stepperZ.moveTo(Z_SEGURIDAD); // Sube a altura de vuelo
  esperarMotores();
}

void irANumero(int numero) {
  int OFFSET = 1200; 
  long targetX = 0;
  long targetY = 0;

  switch (numero) {
    case 1: targetX = 0;          targetY = 0;          break;
    case 2: targetX = -OFFSET;    targetY = 0;          break;
    case 3: targetX = -(OFFSET*2);targetY = 0;          break;
    case 4: targetX = 0;          targetY = -OFFSET;    break;
    case 5: targetX = -OFFSET;    targetY = -OFFSET;    break;
    case 6: targetX = -(OFFSET*2);targetY = -OFFSET;    break;
    case 7: targetX = 0;          targetY = -(OFFSET*2);break;
    case 8: targetX = -OFFSET;    targetY = -(OFFSET*2);break;
    case 9: targetX = -(OFFSET*2);targetY = -(OFFSET*2);break;
    case 0: targetX = -OFFSET;    targetY = -(OFFSET*3);break;
  }
  
  stepperX1.moveTo(DIST_SEGURIDAD + targetX);
  stepperX2.moveTo(DIST_SEGURIDAD + targetX);
  stepperY.moveTo(DIST_SEGURIDAD + targetY);
  esperarMotores();
}