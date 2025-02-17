#ifndef JUEGOLIBRERIA_H
#define JUEGOLIBRERIA_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define MAX_FILA 12 
#define MAX_COL 120 
#define ENEMY 10

/*<--------------------------variables globales-------------------------->*/
extern char escenario[MAX_FILA][MAX_COL];
extern int posX;
extern int posY;
extern char direccionPistola;
extern int puntaje;
extern int contadorEnemigosMuertos;

typedef struct {
    int x;
    int y;
    char simbolo;
} Enemigo;

extern Enemigo enemigos[ENEMY];
extern int numEnemigos;

/*<------------------------- Explicación de las variables globales ------------------------->


1. char escenario[MAX_FILA][MAX_COL]
El escenario es una matriz para poder ver el mapa del juego. Es necesaria porque como se actualiza constantemente  (como mover personajes, mostrar el escenario, generar enemigos, etc.). Si fuera local, habría que pasarla como parámetro en cada función, entonces idealmente fue elgida de esa manera para que todas las funciones tengan acceso rapido a ella.

2. int posX = 1; y int posY = 1;  
Estas variables tienen la ubicacion del personaje en el mapa. Como la posición cambia cuando el personaje se mueve, estas deben estar para utilizarlas facilmente

3. char direccionPistola = '-';  
Esta variable indica hacia dónde dispara el personaje (a la izquierda o a la derecha). Como el jugador puede cambiar de dirección, no es necesario crear una nueva variable en cada función que controle el disparo, es suficiente con que sea accesible desde cualquier parte del código. El disparo afecta otras funciones, como disparar() o detectar colisiones. Al ser global, se puede cambiar la dirección del disparo sin tener que pasar la variable como parámetro en todas las funciones.

4. int puntaje = 0;   
El puntaje cambia mientras se juega (por ejemplo, cuando el jugador mata a un enemigo). Como el puntaje se necesita mostrar en varias partes del juego, tiene que ser accesible globalmente. Tener el puntaje como variable global permite actualizarlo y mostrarlo en cualquier momento sin necesidad de pasarlo entre funciones.

5. int contadorEnemigosMuertos = 0;  
Esta variable cuenta cuántos enemigos han sido eliminados por el jugador. Al igual que el puntaje, debe ser accesible desde cualquier parte del juego.

6. Enemigo enemigos[10];  
Este arreglo guarda a los enemigos activos del juego. Los enemigos pueden aparecer o morir durante el juego, así que hay que tener acceso a esta información en varias partes del código.

7. int numEnemigos = 0;  
¿Por qué es global?:  
Esta variable guarda la cantidad de enemigos activos en el juego. Cada vez que un enemigo es eliminado o aparece, el número de enemigos cambia.*/


/*<--------------------- Funciones --------------------->*/
void cargarEscenario(const char* nombreArchivo);
void mostrarEscenarioConPuntaje();
void posicionAnterior();
int esColision(int x, int y);
void aplicarGravedad();
void dibujarPersonaje();
void moverIzquierda();
void moverDerecha();
void moverArriba();
void moverAbajo();
void saltar();
void generarEnemigos();
void moverEnemigos();
void disparar();
void reproducirSonidoMuerteEnemigo();
void mostrarContadorEnemigosMuertos();
void animacionMuerteEnemigo(int i);
void verificarColisionConEnemigos();
void reproducirSonidoCampana();
void verificarLimiteJugador();
void verificarLimiteEnemigos();

#endif
