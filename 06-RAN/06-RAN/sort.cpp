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
void bubbleSort(int[]);
void impArr(int[]);


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

//Definición de la función mediana
void mediana(int sol[])
{
	cout<<"\n\n********************\n\tMediana\n*********************\n\nLas respuestas sin organizar son: \n";

	impArr(sol);
	bubbleSort(sol);

	cout<<"\n\nEl arreglo ordenado es: ";

	impArr(sol);
	
	cout<<"\n\nLa mediana es el elemento "<<SIZE / 2<<" del total de "<<SIZE<<" respuestas ordenadas.\nPara este cuestionario la mediana es: "<<sol[SIZE / 2];

	getch();
}