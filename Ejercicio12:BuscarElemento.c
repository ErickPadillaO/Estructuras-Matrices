/*Crea un programa que:
	1.- Genere una matriz de 4x4
	2.- Pida al usuario un número a buscar
	3.- Indique si existe y muestre todas las posiciones donde aparece
	4.- Si no existe, muestre un mensaje apropiado*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Definimos filas y columnas como constantes
#define FILAS 4
#define COLUMNAS 4
int valorIngresado;
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
//Paso 3: Declaramos una funcion para buscar el un elemento en la matriz
void buscarElemento(int filas, int columnas, int elemento){
	int encontrado = 0;
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			if(matriz[i][j] == elemento){
				encontrado++;
				printf("El valor %d si existe y se encuentra en la posicion [ %d,%d ]\n", elemento, i, j);
			}
		}
	}
	if(encontrado == 0){
		printf("El valor %d no se encuentra en la matriz.\n", elemento);
	}
}
//Funcion principal
int main(){
	//Inicializar semilla para numeros aleatorios
	srand(time(NULL));
	//Llamado de funciones
	llenarMatriz(totalDeFilas, totalDeColumnas);
	imprimirMatriz(totalDeFilas, totalDeColumnas);
	//Paso 2: Pedir valor a buscar al usuario
	printf("Ingresa el valor que deseas buscar: ");
	scanf("%d",&valorIngresado);
	//Paso 4: Mostrar si existe o no el elemento
	buscarElemento(totalDeFilas, totalDeColumnas, valorIngresado);
	return 0;
}
