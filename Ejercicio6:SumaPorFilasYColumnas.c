/*Crea un programa que:
	1.- Genere una matriz de 4x4
	2.- Calcule la suma de cada fila
	3.- Calcule la suma de cada columna
	4.- Presente los resultados de forma clara*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Definimos filas y columnas como constantes
#define FILAS 4
#define COLUMNAS 4
//Declaramos la matriz
int matriz[FILAS][COLUMNAS];
//Extraemos el total de filas de la matriz dividiendo el tamaño total en bytes de la matriz entre el tamaño en bytes de uno de sus elementos
int totalDeFilas = sizeof(matriz)/sizeof(matriz[0]);
/*Extraemos el total de columnas de la matriz dividiendo el tamaño en bytes de uno de sus elementos entre
el tamaño en bytes del tipo de dato de la matriz*/
int totalDeColumnas = sizeof(matriz[0])/sizeof(int);
//Paso 1: Declaramos una funcion para llenar nuestra matirz con elementos aleatorios de 0 a 9
void llenarMatriz(int filas, int columnas){
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			matriz[i][j] = rand() % 9 + 1;//Numero aleatorio entre 0 y 9
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
//Paso 2: Declaramos una funcion para mostrar la suma por filas
void sumaPorFilas(int filas, int columnas){
	for(int i = 0; i < filas; i++){
		int sumaDeFila = 0;
		for(int j = 0; j < columnas; j++){
			sumaDeFila += matriz[i][j];
		}
		printf("		%d: %d\n", i, sumaDeFila);
	}
}
//Paso 2: Declaramos una funcion para mostrar la suma por columnas
void sumaPorColumnas(int filas, int columnas){
	for(int i = 0; i < filas; i++){
		int sumaDeColumna = 0;
		for(int j = 0; j < columnas; j++){
			sumaDeColumna += matriz[j][i];
		}
		printf("		%d: %d\n", i, sumaDeColumna);
	}
}
//Funcion principal
int main(){
	//Inicializar semilla para numeros aleatorios
	srand(time(NULL));
	//Llamado de funciones
	llenarMatriz(totalDeFilas, totalDeColumnas);
	imprimirMatriz(totalDeFilas, totalDeColumnas);
	//Paso 4: Mostrar resultados
	printf("Suma por filas:\n");
	sumaPorFilas(totalDeFilas, totalDeColumnas);
	printf("Suma por columnas:\n");
	sumaPorColumnas(totalDeFilas, totalDeColumnas);
	return 0;
}
