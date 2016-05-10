#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<conio.h>

#define SIZE 99				//Define el tamaño de los arreglos

using namespace std;

//Declaración de las funciones a usar
void media(int[]);
void mediana(int[]);
void moda(int[], int[]);
void bubblesort(int[]);
void imprArr(int[]);


//Definición del cuerpo principal
int main()
{
	int frecuencia[15] = {0};
	int respuestas[SIZE];

	srand(time(NULL));

	for(int i = 0; i < SIZE; i++)
	{
		respuestas[i] = 1 + rand()%9;
	}

	media(respuestas);
	mediana(respuestas);
	moda(frecuencia, respuestas);

	getch();

	return 0;
}