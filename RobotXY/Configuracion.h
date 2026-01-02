// --- CONFIGURACIÓN DE PINES ---
#define stepX1 3 
#define dirX1  2 
#define stepX2 5 
#define dirX2  4 
#define limitPinX 11 

#define stepY  7 
#define dirY   6 
#define limitPinY 12 

#define motorInterfaceType 1 

// --- PARÁMETROS DE MOVIMIENTO ---
const int VEL_MAX = 800;
const int ACEL = 150;
const int VEL_HOMING = 200;
const long DIST_SEGURIDAD = -4000; // Cuánto se aleja tras el homing
const long DIST_SEGURIDADY = -3000; 