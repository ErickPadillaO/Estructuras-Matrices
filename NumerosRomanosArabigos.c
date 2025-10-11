/*Entrada: Un carácter (char) que representa el símbolo romano (I, V, X, L, C, D, M). 
Solo algunas letras pueden ir antes de otras para restar. Las combinaciones de resta son: 
\(IV\) N (4),  \(IX\) O (9), \(XL\) P (40), \(XC\) Q (90), \(CD\) R (400), y \(CM\) S (900)*/

//void repetidos()

#include <stdio.h>
#include <string.h>
#include <ctype.h>
int  romanoAEntero(char numeroRomano){
	switch(numeroRomano){
		case 'M':
			return 1000;
			break;
		case 'D':
			return 500;
			break;
		case 'C':
			return 100;
			break;
		case 'L':
			return 50;
			break;
		case 'X':
			return 10;
			break;
		case 'V':
			return 5;
			break;
		case 'I':
			return 1;
			break;
		default:
			return 0;
			break;
	}
}
void validarNumeroRomano(char numeroRomano){
	char letrasNumerosRomanos[] = {'M','D','C','L','X','V','I'};
	int validar = 0;
	for(int i = 0; i < strlen(letrasNumerosRomanos); i++){
		if(numeroRomano == letrasNumerosRomanos[i]){
			validar++;
			break;
		}
	}
	if(validar == 0){
		printf("El numero NO es romano\n");
	} else {
		printf("El numero SI es romano\n");
	}
}
int main(){
	char numeroRomano;
	printf("Ingresa el numero romano: ");
	scanf("%c",&numeroRomano);
	numeroRomano = toupper(numeroRomano);
	printf("Ingresaste %c\n", numeroRomano);
	validarNumeroRomano(numeroRomano);
	return 0;
}
