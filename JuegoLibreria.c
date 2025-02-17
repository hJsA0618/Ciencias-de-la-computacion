#include "JuegoLibreria.h"

/*<-------------------------- Definiciones de las funciones -------------------------->*/

char escenario[MAX_FILA][MAX_COL];
int posX = 1;
int posY = 1;
char direccionPistola = '-';
int puntaje = 0;
int contadorEnemigosMuertos = 0;
Enemigo enemigos[ENEMY];
int numEnemigos = 0;

/*<-------------------------- cargarEscenario -------------------------->*/
void cargarEscenario(const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de escenario.\n");
        return;
    }

    int i = 0, j = 0;
    while (fscanf(archivo, "%c", &escenario[i][j]) != EOF) {
        if (escenario[i][j] == '\n') {
            i++;
            j = 0;
        } else {
            j++;
            if (j >= MAX_COL) {
                j = 0;
                i++;
            }
        }
    }

    fclose(archivo);
}

/*<-------------------------- mostrarPuntaje -------------------------->*/
void mostrarPuntaje() {
    printf("Puntaje: %d Enemigos muertos: %d\n\t", puntaje, contadorEnemigosMuertos);
}

/*<-------------------------- mostrarEscenarioConPuntaje -------------------------->*/
void mostrarEscenarioConPuntaje() {
    system("cls");  //es de windwos.h y es para limpiar pantalla
    mostrarPuntaje();
    for (int i = 0; i < MAX_FILA; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            if (escenario[i][j] != '\0') {
                printf("%c", escenario[i][j]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/*<-------------------------- posicionAnterior -------------------------->*/
void posicionAnterior() {
    /*es para limipiar el personaje principal*/
    if (escenario[posY][posX] == '&') {
        escenario[posY][posX] = ' ';
    }
    /*para la pistolita*/
    if (posX + 1 < MAX_COL && escenario[posY][posX + 1] == '-') {
        escenario[posY][posX + 1] = ' ';
    }
    if (posX - 1 >= 0 && escenario[posY][posX - 1] == '+') {
        escenario[posY][posX - 1] = ' ';
    }
}

/*<-------------------------- esColision -------------------------->*/
int esColision(int x, int y) {
    if (x < 0 || x >= MAX_COL || y < 0 || y >= MAX_FILA || escenario[y][x] == '#') {
        return 1;
    }
    return 0;
}

/*<-------------------------- aplicarGravedad -------------------------->*/
void aplicarGravedad() {
    if (posY < MAX_FILA - 1 && !esColision(posX, posY + 1)) {
        posicionAnterior();
        posY++;
        dibujarPersonaje();
        mostrarEscenarioConPuntaje();
    }
}

/*<-------------------------- dibujarPersonaje -------------------------->*/
void dibujarPersonaje() {
    escenario[posY][posX] = '&';
    // si hay un # desaparecer la pistola
    if (direccionPistola == '-') {
        if (posX + 1 < MAX_COL && escenario[posY][posX + 1] != '#') {
            escenario[posY][posX + 1] = '-';
        }
    } else if (direccionPistola == '+') {
        if (posX - 1 >= 0 && escenario[posY][posX - 1] != '#') {
            escenario[posY][posX - 1] = '+';
        }
    }
}

/*<-------------------------- moverIzquierda -------------------------->*/
void moverIzquierda() {
    if (posX > 0 && !esColision(posX - 1, posY)) {
        posicionAnterior();
        posX--;
        direccionPistola = '+';
        dibujarPersonaje();
        mostrarEscenarioConPuntaje();
    }
}

/*<-------------------------- moverDerecha -------------------------->*/
void moverDerecha() {
    if (posX < MAX_COL - 1 && !esColision(posX + 1, posY)) {
        posicionAnterior();
        posX++;
        direccionPistola = '-';
        dibujarPersonaje();
        mostrarEscenarioConPuntaje();
    }
}

/*<-------------------------- moverArriba -------------------------->*/
void moverArriba() {
    if (posY > 0 && !esColision(posX, posY - 1)) {
        posicionAnterior();
        posY--;
        dibujarPersonaje();
        mostrarEscenarioConPuntaje();
    }
}

/*<-------------------------- moverAbajo -------------------------->*/
void moverAbajo() {
    if (posY < MAX_FILA - 1 && !esColision(posX, posY + 1)) {
        posicionAnterior();
        posY++;
        dibujarPersonaje();
        mostrarEscenarioConPuntaje();
    }
}

/*<-------------------------- saltar -------------------------->*/
void saltar() {
    int alturaMax = 2;
    for (int i = 0; i < alturaMax; i++) {
        if (!esColision(posX, posY - 1)) {
            posicionAnterior();
            posY--;
            dibujarPersonaje();
            mostrarEscenarioConPuntaje();
            /*para hacer la animación de salto*/
            Sleep(100);
        } else {
            break;
        }
    }
}

/*<-------------------------- generarEnemigos -------------------------->*/
void generarEnemigos() {
    int x, y;
    do {
        x = rand() % (MAX_COL - 4);
        y = MAX_FILA - 4;
        while (y > 0 && (escenario[y][x] == '#' || escenario[y][x] == '&')) {
            y--;
        }
    } while (escenario[y][x] == '#' || escenario[y][x] == '&');

    if (numEnemigos < 10) {
        enemigos[numEnemigos].x = x;
        enemigos[numEnemigos].y = y;
        enemigos[numEnemigos].simbolo = 'E';
        escenario[y][x] = enemigos[numEnemigos].simbolo;
        numEnemigos++;
    }
}

/*<-------------------------- moverEnemigos -------------------------->*/
void moverEnemigos() {
    for (int i = 0; i < numEnemigos; i++) {
        if (enemigos[i].x < posX) {
            if (!esColision(enemigos[i].x + 1, enemigos[i].y)) {
                escenario[enemigos[i].y][enemigos[i].x] = ' ';
                enemigos[i].x++;
                escenario[enemigos[i].y][enemigos[i].x] = enemigos[i].simbolo;
            }
        } else if (enemigos[i].x > posX) {
            if (!esColision(enemigos[i].x - 1, enemigos[i].y)) {
                escenario[enemigos[i].y][enemigos[i].x] = ' ';
                enemigos[i].x--;
                escenario[enemigos[i].y][enemigos[i].x] = enemigos[i].simbolo;
            }
        }

        if (enemigos[i].y < MAX_FILA - 1 && !esColision(enemigos[i].x, enemigos[i].y + 1)) {
            escenario[enemigos[i].y][enemigos[i].x] = ' ';
            enemigos[i].y++;
            escenario[enemigos[i].y][enemigos[i].x] = enemigos[i].simbolo;
        }
    }
}

/*<-------------------------- disparar -------------------------->*/
void disparar() {
    int dx = 0, dy = 0;
    if (direccionPistola == '-') {
        dx = 1;
    } else if (direccionPistola == '+') {
        dx = -1;
    }

    int x = posX + dx;
    int y = posY + dy;

    while (x >= 0 && x < MAX_COL && y >= 0 && y < MAX_FILA && !esColision(x, y)) {
        if (escenario[y][x] == 'E') {
            for (int i = 0; i < numEnemigos; i++) {
                if (enemigos[i].x == x && enemigos[i].y == y) {
                    animacionMuerteEnemigo(i);
                    escenario[y][x] = ' ';
                    enemigos[i] = enemigos[numEnemigos - 1];
                    numEnemigos--;
                    puntaje += 100;
                    contadorEnemigosMuertos++;
                    break;
                }
            }
            break;
        }

        x += dx;
        y += dy;
    }
}

/*<-------------------------- reproducirSonidoMuerteEnemigo -------------------------->*/
void reproducirSonidoMuerteEnemigo() {
    Beep(1000, 200); 
}

/*<-------------------------- reproducirSonidoCampana -------------------------->*/
void reproducirSonidoCampana() {
    Beep(500, 500);
}

/*<-------------------------- animacionMuerteEnemigo -------------------------->*/
void animacionMuerteEnemigo(int i) {
    for (int j = 0; j < 3; j++) {
        escenario[enemigos[i].y][enemigos[i].x] = '*';
        mostrarEscenarioConPuntaje();
        Sleep(200);
        escenario[enemigos[i].y][enemigos[i].x] = ' ';
        mostrarEscenarioConPuntaje();
        Sleep(200);
    }
}

/*<-------------------------- verificarColisionConEnemigos -------------------------->*/
void verificarColisionConEnemigos() {
    for (int i = 0; i < numEnemigos; i++) {
        if (enemigos[i].x == posX && enemigos[i].y == posY) {
            reproducirSonidoCampana();
            printf("...Has muerto con un puntaje de %d\nJuego terminado.\n", puntaje);
            exit(0);
        }
    }
}

/*<-------------------------- verificarLimiteJugador -------------------------->*/
void verificarLimiteJugador() {
    if (posX < 0 || posX >= MAX_COL-1 || posY < 0 || posY >= MAX_FILA-1) {
        printf("Has salido del limite del mapa\n Game Over....\n\n:C");
        exit(0);
    }
}

/*<-------------------------- verificarLimiteEnemigos -------------------------->*/
void verificarLimiteEnemigos() {
    for (int i = 0; i < numEnemigos; i++) {
        if (enemigos[i].x < 0 || enemigos[i].x >= MAX_COL-1 || enemigos[i].y < 0 || enemigos[i].y >= MAX_FILA-1) {
            escenario[enemigos[i].y][enemigos[i].x] = ' ';
            enemigos[i] = enemigos[numEnemigos - 1];
            numEnemigos--;
        }
    }
}
