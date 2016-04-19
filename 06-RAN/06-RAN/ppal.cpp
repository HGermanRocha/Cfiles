/*

	Ejercicio: Petalos de una flor

*/

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <time.h>

using namespace std;

int main()
{
	int a = 0, b = 0, pet_flor = 0, guess = 0;
	srand(time(NULL));
	int dado[5];
	
	for(int i = 0; i < 5; i++)
	{
		dado[i] = 1 + rand()%6;

		if(dado[i] == 3 || dado[i] == 5)
		{
			pet_flor += dado[i] - 1;
		}
	}
	
	cout<<"\t\tPETALOS DE UNA FLOR\n";
	cout<<"\nAdivine el truco del juego, si adivina obtiene $500.00 pesos.";
	cout<<"\n\nEstos son los resultados de 6 dados lanzados:\n\n";

	for(int i = 0; i < 5; i++)
	{
		cout<<"Dado "<<i + 1<<"\t";
	}
	
	cout<<"Petalos de una flor\n";
	
	for(int i = 0; i < 5; i++)
	{
		cout<<"  "<<dado[i]<<" \t";
	}
	cout<<"\nCuantos petalos crees que hayan? ";
	cin<<guess;
	cout<<"\nPresiona ENTER";
	getch();

	return 0;
}