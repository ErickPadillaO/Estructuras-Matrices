#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Estructura para crear un estudiante
struct Estudiante{
	char nombre[50];
	int edad;
	float promedio;
};
//Funcion para llenar los datos de los estudiantes
void pedirDatosDelEstudiante(int longitud, struct Estudiante (*ptrEstudiantes)[longitud]){
	char nombre [50];
	int edad = 0, limpiarBufer, valido = 0;
	float promedio = 0;
	for(int i = 0; i < longitud; i++){
		do{
			system("clear");
			printf("\n** Datos para el estudiante %d **\n", i+1);
			printf("Ingrese el nombre: ");
			scanf("%49s", nombre);
			while ((limpiarBufer = getchar()) != '\n' && limpiarBufer != EOF);
			printf("Ingresa la edad: ");
			valido = scanf("%d", &edad);
			while ((limpiarBufer = getchar()) != '\n' && limpiarBufer != EOF);
			if(valido == 0){
				printf("Dato incorrecto... Intenta de nuevo!\n");
				getchar();
				continue;
			}
			printf("Ingresa el promedio: ");
			valido = scanf("%f", &promedio);
			while ((limpiarBufer = getchar()) != '\n' && limpiarBufer != EOF);
			if(valido == 0){
				printf("Dato incorrecto... Intenta de nuevo!\n");
				getchar();
				continue;
			}
			//Almacenar datos ingresados.
			strcpy((*ptrEstudiantes)[i].nombre, nombre);
			(*ptrEstudiantes)[i].edad = edad;
			(*ptrEstudiantes)[i].promedio = promedio;
		}while(valido == 0);
	}
}
//Funcion para imprimir datos de los estudiantes
void imprimirDatosDelEstudiante(int longitud, struct Estudiante (*ptrEstudiantes)[longitud]){
	system("clear");
	for(int i = 0; i < longitud; i++){
		printf("\n** Datos del estudiante %d **\n", i+1);
		printf("Nombre: %s\n", (*ptrEstudiantes)[i].nombre);
		printf("Edad: %d\n", (*ptrEstudiantes)[i].edad);
		printf("Promedio: %.1f\n", (*ptrEstudiantes)[i].promedio);
	}
}
//Funcion principal
int main(){
	struct Estudiante estudiantes[3];
	struct Estudiante (*ptrEstudiantes)[3] = &estudiantes;
	int longitud = sizeof(estudiantes)/sizeof(estudiantes[0]);
	pedirDatosDelEstudiante(longitud, ptrEstudiantes);
	imprimirDatosDelEstudiante(longitud, ptrEstudiantes);
	return 0;
}
