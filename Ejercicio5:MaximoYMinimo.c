/*Desarrolla un programa que:
	1.- Llene una matriz de 4x4 con números aleatorios
	2.- Encuentre el valor máximo y su posición (fila, columna)
	3.- Encuentre el valor mínimo y su posición
	4.- Muestre los resultados*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Definimos filas y columnas como constantes
#define FILAS 4
#define COLUMNAS 4
int maximo = 0;
int minimo = 100;
//Declaramos la matriz
int matriz[FILAS][COLUMNAS];
//Extraemos el total de filas de la matriz dividiendo el tamaño total en bytes de la matriz entre el tamaño en bytes de uno de sus elementos
int totalDeFilas = sizeof(matriz)/sizeof(matriz[0]);
/*Extraemos el total de columnas de la matriz dividiendo el tamaño en bytes de uno de sus elementos entre
el tamaño en bytes del tipo de dato de la matriz*/
int totalDeColumnas = sizeof(matriz[0])/sizeof(int);
//Paso 1: Declaramos una funcion para llenar nuestra matirz con elementos aleatorios de 0 a 99
void llenarMatriz(int filas, int columnas){
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			matriz[i][j] = rand() % 99 + 1;//Numero aleatorio entre 0 y 99
		}
	}
}
//Declaramos una funcion para imprimir la matriz en formato de tabla
void imprimirMatriz(int filas, int columnas){
	for(int i = 0; i < filas; i++){
		printf("[ ");
		for(int j = 0; j < columnas; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("]\n");
	}
}
//Paso 2: Declaramos una funcion para imprimir el valor maximo y su posicion
void maximoPosicionMatriz(int filas, int columnas, int maximo){
	int posicionI = 0, posicionJ = 0;
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			if(matriz[i][j] > maximo){
				maximo = matriz[i][j];
				posicionI = i;
				posicionJ = j;
			}
		}
	}
	printf("El valor maximo es %d y se encuentra en la posicion [%d,%d].\n", maximo, posicionI, posicionJ);
}
//Paso 3: Declaramos una funcion para imprimir el valor minimo y su posicion
void minimoPosicionMatriz(int filas, int columnas, int minimo){
	int posicionI = 0, posicionJ = 0;
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			if(matriz[i][j] < minimo){
				minimo = matriz[i][j];
				posicionI = i;
				posicionJ = j;
			}
		}
	}
	printf("El valor minimo es %d y se encuentra en la posicion [%d,%d].\n", minimo, posicionI, posicionJ);
}
//Funcion principal
int main(){
	//Inicializar semilla para numeros aleatorios
	srand(time(NULL));
	//Llamado de funciones
	llenarMatriz(totalDeFilas, totalDeColumnas);
	imprimirMatriz(totalDeFilas, totalDeColumnas);
	//Paso 4: Mostrar resultados
	maximoPosicionMatriz(totalDeFilas, totalDeColumnas, maximo);
	minimoPosicionMatriz(totalDeFilas, totalDeColumnas, minimo);
	return 0;
}
