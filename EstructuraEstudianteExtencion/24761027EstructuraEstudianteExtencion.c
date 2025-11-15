#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Estructura para crear un estudiante
struct Estudiante{
	int matricula;
	char nombre[50];
	int edad;
	float promedio;
};
//Estructura para crear materia
struct Materia{
	char nombreMateria[30];
	float calificacion;
};
//Funcion para llenar datos de Materia
void llenarDatosMateria(int materiasTotal, FILE *txt){
	char nombreMateria[30];
	float calificacion = 0, suma = 0, promedio = 0;
	int valido = 0, limpiarBufer;
	for(int i = 0; i < materiasTotal; i++){
		do{
			printf("\n** Datos para la materia %d **\n", i+1);
			printf("Ingrese el nombre: ");
			scanf("%29s", nombreMateria);
			while ((limpiarBufer = getchar()) != '\n' && limpiarBufer != EOF);
			printf("Ingresa la calificacion: ");
			valido = scanf("%f", &calificacion);
			while ((limpiarBufer = getchar()) != '\n' && limpiarBufer != EOF);
			if(valido == 0){
				printf("Dato incorrecto... Intenta de nuevo!\n");
				getchar();
				continue;
			}
			suma += calificacion;
			promedio = suma / materiasTotal;
			if (txt != NULL){
				if(i == 2){
					fprintf(txt,"%s %.2f %.2f\n", nombreMateria, calificacion, promedio);
				} else {
					fprintf(txt,"%s %.2f ", nombreMateria, calificacion);
				}
			}
		}while(valido == 0);
	}
}
//Funcion para llenar los datos de los estudiantes
void pedirDatosDelEstudiante(int longitud, FILE *txt){
	txt  = fopen("datosEstudiantes.txt", "w");
	char nombre [50];
	int matricula = 1000, edad = 0, limpiarBufer, valido = 0, totalMaterias = 3;
	float promedio = 0;
	for(int i = 0; i < longitud; i++){
		do{
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
			//Almacenar datos ingresados.
			if (txt != NULL){
				fprintf(txt,"%d %s %d ", matricula, nombre, edad);
			}
			//Llenara datos de las materias
			llenarDatosMateria(totalMaterias, txt);
			matricula++;
		}while(valido == 0);
	}
	fclose(txt);
}
//Funcion para cargar datos desde el txt
void cargarDatosEstudiante(int longitud, struct Estudiante (*ptrEstudiantes)[longitud], FILE *txt){
	char nombre [50], materiaUno [30], materiaDos [30], materiaTres [30];
	int matricula = 0, edad = 0;
	float calificacionUno = 0, calificacionDos = 0, calificacionTres = 0, promedio = 0;
	for(int i = 0; i < longitud; i++){
		fscanf(txt, "%d%s%d%s%f%s%f%s%f%f", &matricula, nombre, &edad, materiaUno, &calificacionUno,
			materiaDos, &calificacionDos, materiaTres, &calificacionTres, &promedio);
		(*ptrEstudiantes)[i].matricula = matricula;
		strcpy((*ptrEstudiantes)[i].nombre, nombre);
		(*ptrEstudiantes)[i].edad = edad;
		(*ptrEstudiantes)[i].promedio = promedio;
	}
	fclose(txt);
}
//Funcion para imprimir datos de los estudiantes
void imprimirDatosDelEstudiante(int longitud, struct Estudiante (*ptrEstudiantes)[longitud]){
	for(int i = 0; i < longitud; i++){
		printf("\n** Datos del estudiante %d **\n", i+1);
		printf("Matricula: %d\n", (*ptrEstudiantes)[i].matricula);
		printf("Nombre: %s\n", (*ptrEstudiantes)[i].nombre);
		printf("Edad: %d\n", (*ptrEstudiantes)[i].edad);
		printf("Promedio: %.1f\n", (*ptrEstudiantes)[i].promedio);
	}
}
//Funcion para el promedio general del grupo
void promedioDelGrupo(int longitud, struct Estudiante (*ptrEstudiantes)[longitud], float *ptrPromedioGeneral){
	float suma = 0;
	for(int i = 0; i < longitud; i++){
		suma += (*ptrEstudiantes)[i].promedio;
	}
	*ptrPromedioGeneral = suma / longitud;
}
//Funcion para obtener estudiante de mejor promedio
void mejorPromedio(int longitud, struct Estudiante (*ptrEstudiantes)[longitud]){
	int i = 0, posicion = 0;
	float mejorPromedio = (*ptrEstudiantes)[i].promedio;
	for(i = 1 ; i < longitud; i++){
		if((*ptrEstudiantes)[i].promedio > mejorPromedio){
			mejorPromedio = (*ptrEstudiantes)[i].promedio;
			posicion = i;
		}
	}
	printf("\n*** El estudiante con mejor promedio es %s con una calificacion de %.1f ***\n",
	 (*ptrEstudiantes)[posicion].nombre, (*ptrEstudiantes)[posicion].promedio);
}
//Funcion para mostrar menu de opciones
int menuDeOpciones(int opcion){
	int valido = 0, limpiarBufer;
	do{
		system("clear");
		printf("Programa que almacena información de varios estudiantes y las materias que cursan\n");
		printf("\n*** Menu de opciones ***\n");
		printf("1.- Capturar estudiantes\n2.- Mostrar todos\n3.- Buscar por matrícula\n4.- Salir\n");
		printf("Ingresa la opcion deseada: ");
		valido = scanf("%d", &opcion);
		while ((limpiarBufer = getchar()) != '\n' && limpiarBufer != EOF);
		if(valido == 0){
			printf("Dato incorrecto... Intenta de nuevo!\n");
			getchar();
			continue;
		}
		if(!(opcion > 0 && opcion < 5)){
			printf("Opcion no disponible... Intenta de nuevo!\n");
			getchar();
		} else{
			break;
		}
	} while(valido == 0);
	return opcion;
}
//Funcion para contar lineas en el archivo
void totalDeLineas(int *longitud, FILE *txt){
	txt = fopen("datosEstudiantes.txt", "r");
	if(txt == NULL){
		printf("Error al abrir el archivo...\n");
	} else {
		int lineas = 0;
		char caracter;
		while ((caracter = fgetc(txt)) != EOF) {
			if (caracter == '\n') {
				lineas++;
			}
		}
		*longitud = lineas;
	}
	fclose(txt);
}
//Funcion para buscar la matricula
void buscarMatricula(int matricula, int longitud, struct Estudiante (*ptrEstudiantes)[longitud]){
	int encontrado = 0;
	for(int i = 0; i < longitud; i++){
		if((*ptrEstudiantes)[i].matricula == matricula){
			printf("La matricula %d pertenece al estudiante %s.\n", matricula, (*ptrEstudiantes)[i].nombre);
			encontrado++;
			break;
		}
	}
	if(encontrado == 0){
		printf("No se encontro la matricula %d.\n", matricula);
	}
}
//Funcion principal
int main(){
	int opcion = 0;
	while(opcion != 4){
		int longitud = 0;
		FILE *archivoTexto;
		totalDeLineas(&longitud, archivoTexto);
		struct Estudiante estudiantes[longitud];
		struct Estudiante (*ptrEstudiantes)[longitud] = &estudiantes;
		int valido = 0, matricula = 0, limpiarBufer;
		float promedioGeneral = 0;
		opcion = menuDeOpciones(opcion);
		switch(opcion){
			case 1:
				do{
					system("clear");
					printf("*** Registrar Estudiantes ***\n");
					printf("\nIngresa el numero de estudiantes a registrar: ");
					valido = scanf("%d", &longitud);
					while ((limpiarBufer = getchar()) != '\n' && limpiarBufer != EOF);
					if(valido == 0){
						printf("Dato incorrecto... Intenta de nuevo!\n");
						getchar();
						continue;
					}
				} while(valido == 0);
				pedirDatosDelEstudiante(longitud, archivoTexto);
				printf("\n¡Datos guardados exitosamente!\nPreciona ENTER para ir al Menu Principal...");
				getchar();
				break;
			case 2:
				totalDeLineas(&longitud, archivoTexto);
				archivoTexto = fopen("datosEstudiantes.txt", "r");
				if(archivoTexto == NULL){
					printf("Error al abrir el archivo...\n");
				} else {
					system("clear");
					printf("*** Mostrar Todos los Estudiantes ***\n");
					cargarDatosEstudiante(longitud, ptrEstudiantes, archivoTexto);
					imprimirDatosDelEstudiante(longitud, ptrEstudiantes);
					mejorPromedio(longitud, ptrEstudiantes);
				}
				printf("\nPreciona ENTER para ir al Menu Principal...");
				getchar();
				break;
			case 3:
				totalDeLineas(&longitud, archivoTexto);
				archivoTexto = fopen("datosEstudiantes.txt", "r");
				if(archivoTexto == NULL){
					printf("Error al abrir el archivo...\n");
				} else {
					totalDeLineas(&longitud, archivoTexto);
					do{
						system("clear");
						printf("*** Buscar Estudiante por Matricula ***\n");
						printf("Ingresa el numero de matricula: ");
						valido = scanf("%d", &matricula);
						while ((limpiarBufer = getchar()) != '\n' && limpiarBufer != EOF);
						if(valido == 0){
							printf("Dato incorrecto... Intenta de nuevo!\n");
							getchar();
							continue;
						}
					} while(valido == 0);
					cargarDatosEstudiante(longitud, ptrEstudiantes, archivoTexto);
					buscarMatricula(matricula, longitud, ptrEstudiantes);
				}
				printf("\nPreciona ENTER para ir al Menu Principal...");
				getchar();
				break;
			case 4:
				printf("Saliedo del programa.....\n");
				break;
			default:
		}
	}
	return 0;
}
