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

//Definición de la función de media
void media(int sol[])
{
	int total = 0, temp = 0;

	cout<<"******************\n\tMedia*********************\n\n";
	for(int j = 0; j < SIZE; j++)
	{
		total += sol[j];
	}

	cout<<"La media es el promedio de todos los dados.\nLa media para este cuestionario es: "<<total<<" / "<<SIZE<<" = "<<(float)total/SIZE;

	getch();
}