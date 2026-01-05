// --- CONFIGURACIÓN DE PINES ---
#define stepX1 3 
#define dirX1  2 
#define stepX2 5 
#define dirX2  4 
#define limitPinX 11 

#define stepY  51 
#define dirY   50 
#define limitPinY 12 

#define stepZ  7 
#define dirZ   6 
#define limitPinZ 10 

#define motorInterfaceType 1 

// --- PARÁMETROS DE MOVIMIENTO ---
const int VEL_MAX = 800;
const int ACEL = 300;
const int VEL_HOMING = 300;

// IMPORTANTE: Distancia para alejarse de los sensores tras el homing
const long DIST_SEGURIDAD = -2000; 

// Eje Z: 0 es el botón (arriba). 400 es "vuelo". 3500 es "presionar".
const long Z_SEGURIDAD = 850;   
const long Z_PRESIONAR = 2000;