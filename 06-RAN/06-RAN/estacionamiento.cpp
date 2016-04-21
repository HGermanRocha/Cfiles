#include <iostream>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

void registro(float[], float[], int[]);

int main()
{
	float precio[3];
	float horas[3];
	int clienteId[3];

	for(int i = 0; i < 3; i++)
	{
		clienteId[i] = i + 1;
		
		cout<<"\nCliente "<<clienteId[i]<<"\nIngrese las horas en el estacionamiento: ";
		cin>>horas[i];
		horas[i] = ceil(horas[i]);

		if(horas[i] <= 3)
		{
			precio[i] = 10;
		}
		else if((horas[i] > 3) && (horas[i] < 24))
		{
			precio[i] = ((horas[i] - 3) * 5) + 10;
		}
		else if(horas[i] >= 24)
		{
			precio[i] = 80;
		}

	}

	cout<<"\n\nPara ver registo presione ENTER\n";
	getch();

	system("cls");

	registro(horas, precio, clienteId);

	getch();

	return 0;
}

void registro(float horas[], float precio[], int clienteId[])
{
	cout<<"\t\t***REGISTRO***";
	cout<<"\nCliente\t\tHoras\t\tCosto\n";

	for(int i = 0; i < 3; i++)
	{
		cout<<clienteId[i]<<"\t\t"<<horas[i]<<"\t\t"<<precio[i]<<" pesos"<<endl;	
	}
}