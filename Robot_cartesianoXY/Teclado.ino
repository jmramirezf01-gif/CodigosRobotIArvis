void presionarTecla(){
  Serial.println("Click!");
  // Baja a presionar
  stepperZ.moveTo(Z_PRESIONAR);
  esperarMotores();
  delay(200);

  // Subiendo para liberar la tecla 
  stepperZ.moveTo(Z_ARRIBA);
  esperarMotores();
  delay(200);
}

void teclearPIN(int n1, int n2, int n3, int n4){
  int pin[] = {n1, n2, n3, n4};
  for (int i=0; i<4; i++){
    if(pin[i] == 0 && i>0) break; // Si el pin es 0 y no es el primero termina 
    irANumero(pin[i]);
    presionarTecla();
  }
}


// Aqui se completa el switch con las coordenadas reales del Pinpad 

void irANumero(int numero){
  int OFFSET = 1200; 
  long targetX = 0;
  long targetY = 0; 

  switch (numero) {
    case 1: targetX = 0;          targetY = 0;          break;
    case 2: targetX = OFFSET;     targetY = 0;          break;
    case 3: targetX = OFFSET*2;   targetY = 0;          break;
    case 4: targetX = 0;          targetY = 0;          break; 
    // Agregar el resto de casos segun se necesite  
  }

  stepperX1.moveTo(DIST_SEGURIDAD + targetX);
  stepperX2.moveTo(DIST_SEGURIDAD + targetX);
  stepperY.moveTo(DIST_SEGURIDAD + targetY);
  esperarMotores();
}
