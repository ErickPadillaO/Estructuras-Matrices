#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Declaramos Funciones que utilizaremos
int menuDeInicio();
void puntajes(int puntajeJugador, int puntajePC);
void llenarMatrizDelJuego(int filas, int columnas, int matriz[][columnas]);
void llenarMatrizDeCasillas(int filas, int columnas, int matriz[][columnas]);
void imprimirMatriz(int filas, int columnas, int matriz[][columnas]);
int jugar(int filas, int columnas, int matrizDelJuego[][columnas], int matrizDeCasillas[][columnas]);
int ingresarValorEnLaCasilla(int turno, int casilla, int columnas, int matrizDelJuego[][columnas]);
int verificarGanador(int filas, int columnas, int matriz[][columnas]);
//Función principal
int main(){
	const int filas = 3, columnas = 3;
	int matrizDelJuego[filas][columnas];
	int matrizDeCasillas[filas][columnas];
	int opcion, ganador, puntajeJugador = 0, puntajePC = 0;
	do{
		opcion = menuDeInicio();
		if(opcion == 1){
			ganador = jugar(filas, columnas, matrizDelJuego, matrizDeCasillas);
			if(ganador == 1){
				puntajeJugador++;
			} else if(ganador == 2){
				puntajePC++;
			}
			printf("\nPresiona ENTER para regresar al menu principal...");
			getchar();
		} else if(opcion == 2){
			puntajes(puntajeJugador, puntajePC);
		} else {
			printf("¡Saliste del juego!\n");
		}
	} while(opcion != 3);
	return 0;
}
//Funcion para empezar a jugar
int jugar(int filas, int columnas, int matrizDelJuego[][columnas], int matrizDeCasillas[][columnas]){
	int casilla = 0, valido = 0, limpiarBuffer, contador = 0, turno = rand() % 2 + 1, turnoAnterior, ganador = 0;
	llenarMatrizDelJuego(filas, columnas, matrizDelJuego);
	llenarMatrizDeCasillas(filas, columnas, matrizDeCasillas);
	do{
		do{
			system("clear");
			printf("*************************\n");
			printf("*       Jugando         *\n");
			printf("*************************\n");
			printf("Matriz Del Juego\n");
			imprimirMatriz(filas, columnas, matrizDelJuego);
			printf("\nMatriz De Casillas\n");
			imprimirMatriz(filas, columnas, matrizDeCasillas);
			//Turno de la PC es el 2 y del jugador es el 1
			if(turno == 2){
				casilla = (rand() % 9) + 1;
				valido = 1;
			} else {
				printf("\nTU TURNO \n");
				printf("Selecciona una casilla disponible [0]: ");
				valido = scanf("%d", &casilla);
				while ((limpiarBuffer = getchar()) != '\n' && limpiarBuffer != EOF);
			}
			//Validamos que no sean caracteres, solo numeros
			if(valido != 1){
				printf("Entrada invalida!\nPresiona ENTER para intentar de nuevo...\n");
				getchar();
			//Validamos los numeros permitidos para las casillas
			} else if(casilla < 1 || casilla > 9){
				printf("Opcion no disponible!\nPresiona ENTER para intentar de nuevo...\n");
				getchar();
				valido = 0;
			}
		}while(valido != 1);
		turnoAnterior = turno;
		turno = ingresarValorEnLaCasilla(turno, casilla, columnas, matrizDelJuego);
		if(turno != turnoAnterior){ //Solo avanza si la jugada es valida
			contador++;
		}
		//Verificar ganador apartir de la quinta ronda
		if(contador > 4){
			ganador = verificarGanador(filas, columnas, matrizDelJuego);
			if(ganador != 0){
				system("clear");
				printf("Matriz de la Victoria\n");
				imprimirMatriz(filas, columnas, matrizDelJuego);
				printf("\n¡El jugador %d ha ganado!\n", ganador);
				return ganador;
				break;
			}
		}
	}while(contador < 9);
	if(ganador == 0){
		system("clear");
		printf("Matriz del Empate\n");
		imprimirMatriz(filas, columnas, matrizDelJuego);
		printf("\n¡Empate!\n");
		return 0;
	}
	return 0;
}
//Funcion para inicializar la matriz del juego
void llenarMatrizDelJuego(int filas, int columnas, int matrizDelJuego[][columnas]){
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			matrizDelJuego[i][j] = 0;
		}
	}
}
//Funcion para llenar la matriz de casillas numeradas
void llenarMatrizDeCasillas(int filas, int columnas, int matriz[][columnas]){
	int casillas = 1;
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			matriz[i][j] = casillas++;
		}
	}
}
//Funcion para imprimir una matriz
void imprimirMatriz(int filas, int columnas, int matriz[][columnas]){
	for(int i = 0; i < filas; i++){
		printf("[");
		for(int j = 0; j < columnas; j++){
			printf(" %d", matriz[i][j]);
		}
		printf(" ]\n");
	}
}
//Funcion para poner el valor a la casilla elegida
int ingresarValorEnLaCasilla(int turno, int casilla, int columnas, int matrizDelJuego[][columnas]){
	int fila = (casilla - 1) / columnas;
	int columna = (casilla - 1) % columnas;
	if(matrizDelJuego[fila][columna] == 0){
		matrizDelJuego[fila][columna] = turno;
		if(turno == 1){ //Cambiar turno
			return 2;
		} else {
			return 1;
		}
	} else {
		if(turno == 1){
			printf("Espacio ocupado! Intenta con otro...");
			getchar();
			return turno;
		} else {
			return turno;
		}
	}
}
//Funcion para verificar si hay ganador
int verificarGanador(int filas, int columnas, int matirz[][columnas]){
	//Verificar filas
	for(int i = 0; i < filas; i++){
		if(matirz[i][0] != 0 && matirz[i][0] == matirz[i][1] && matirz[i][1] == matirz[i][2]){
			return matirz[i][0];
		}
	}
	//Verificar columnas
	for(int j = 0; j < columnas; j++){
		if(matirz[0][j] != 0 && matirz[0][j] == matirz[1][j] && matirz[1][j] == matirz[2][j]){
			return matirz[0][j];
		}
	}
	//Verificar diagonales
	if(matirz[0][0] != 0 && matirz[0][0] == matirz[1][1] && matirz[1][1] == matirz[2][2]){
		return matirz[0][0];
	}
	if(matirz[0][2] != 0 && matirz[0][2] == matirz[1][1] && matirz[1][1] == matirz[2][0]){
		return matirz[0][2];
	}
	return 0; // No hay ganador
}
//Funcion para mostrar los puntajes
void puntajes(int puntajeJugador, int puntajePC){
	system("clear");
	printf("**************************\n");
	printf("*       Puntajes         *\n");
	printf("**************************\n");
	printf("Partidas ganadas del jugador: %d\n", puntajeJugador);
	printf("Partidas ganadas de la PC: %d\n", puntajePC);
	printf("Presiona ENTER para regresar al menu principal...");
	getchar();
}
//Funcion para el menu de inicio
int menuDeInicio(){
	srand(time(NULL));
	int opcion = 0, valido = 0, limpiarBuffer;
	do{
		system("clear");
		printf("*****************************************\n");
		printf("*       Bienvenido al juego del gato    *\n");
		printf("*****************************************\n");
		printf("1.- Jugar\n2.- Puntajes\n3.- Salir\n\nSelecciona la opcion deseada: ");
		valido = scanf("%d", &opcion);
		while ((limpiarBuffer = getchar()) != '\n' && limpiarBuffer != EOF);
		if(valido != 1){
			printf("Entrada invalida!\nPresiona ENTER para intentar de nuevo...\n");
			getchar();
		} else if(opcion < 1 || opcion > 3){
			printf("Opcion no disponible!\nPresiona ENTER para intentar de nuevo...\n");
			getchar();
			valido = 0;
		}
	}while(valido != 1);
	return opcion;
}
