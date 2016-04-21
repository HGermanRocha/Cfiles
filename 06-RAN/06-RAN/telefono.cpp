#include <iostream>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>

using namespace std;

void output(int, float[], string[], float[]);

int main()
{
	float tarifa = 0;
	int i = 0, opc = 0, salir = 0;
	float precio[100];
	float min[100];
	string tipo_llamada[100];

	while(salir == 0)
	{
		system("cls");
		cout<<"\t\t***CALCULADORA DE PRECIOS DE LLMADAS***\n\n";
	
		cout<<"Por favor seleccione el tipo de llamada que realizo:\n\n";
		cout<<"1.Llamada local o telefono fijo\n";
		cout<<"2.Llamada a celular nacional\n";
		cout<<"3.Llamada internacional a EEUU o CANADA\n";
		cout<<"4.Llamada internacional (resto del mundo)\n";
		cout<<"5.Salir\n";
		cin>>opc;

		while(opc > 5 || opc < 1)
		{
			cout<<"Opcion invalida! Ingrese de nuevo\n";
			cin>>opc;

		}

		if(opc != 5)
		{
			cout<<"\nAhora ingrese los minutos que realizo: ";
			cin>>min[i];
			min[i] = ceil(min[i]);
		}

		switch(opc)
		{
			case 1:
				tarifa = 1.20;
				tipo_llamada[i] = "Local";
				break;
			case 2:
				tarifa = 4.50;
				tipo_llamada[i] = "Celular";
				break;
			case 3:
				tarifa = 5.00;
				tipo_llamada[i] = "A EEUU o CANADA";
				break;
			case 4:
				tarifa = 6.50;
				tipo_llamada[i] = "Internacional (Resto del mundo)";
				break;
			case 5:
				salir = 1;
				break;

		}

		getch();
		precio[i] = tarifa * min[i];
		i++;
	}

	i--;

	output(i, precio, tipo_llamada, min);

	return 0;
}

void output(int i, float precio[], string tipo_llamada[], float min[])
{
	string blankSpace = "";
	system("cls");
	cout<<"***REGISTRO DE PRECIOS POR LLAMADA***\n\n";
	cout<<"Tipo de llamada\t\t\t\tMinutos\t\tCosto\n";

	for(int j = 0; j < i; j++)
	{
		blankSpace = "";
		for(int k = 0; k < (40 - tipo_llamada[j].length()); k++)
		{
			blankSpace += " ";
		}
		cout<<tipo_llamada[j]<<blankSpace<<min[j]<<"\t\t"<<precio[j]<<endl;

	}
	getch();

}