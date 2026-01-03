// --- CONFIGURACIÓN DE PINES ---
// Eje X
#define stepX1 3 
#define dirX1  2 
#define stepX2 5 
#define dirX2  4 
#define limitPinX 11 // Final de carrera 

// Eje Y
#define stepY  7 
#define dirY   6 
#define limitPinY 12 // Final de carrera 

// Eje Z
#define stepZ  8 
#define dirZ   9 
#define limitPinZ 10 // Final de carrera o push botton 

#define motorInterfaceType 1 

// --- PARÁMETROS DE MOVIMIENTO ---
const int VEL_MAX = 800;
const int ACEL = 150;
const int VEL_HOMING = 200;
const long DIST_SEGURIDAD = -4000; // Cuánto se aleja tras el homing
const long DIST_SEGURIDADY = -3000; 

// Parametros especificos para presionar (Eje Z)
const long Z_ARRIBA = 0; // Posicion del carrete tras el Homing 
const long Z_PRESIONAR = -500; // Valor ajustable para la profundidad de la presion de las teclas