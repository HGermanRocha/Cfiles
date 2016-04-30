/*		
	Nombre del proyecto: Tablas de verdad
	Nombre del alumno: Héctor Germán Rocha Ramírez
	Matrícula: 150307
	Materia: Matemáticas Discretas I
	Profesor: Betancourt
*/

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

using namespace std;

void linea(int no_prop);
void displayTable(string symbol, int no_prop);

int main()
{
	int no_prop = 0, opc = 0;
	string symbol = "";
	
	while(opc != 5)
	{
		system("cls");
		
		cout<<"\t\tGENERADOR DE TABLAS DE VERDAD\n\n";
		cout<<"Ingrese el numero de proposiciones: ";
		cin>>no_prop;
		
		cout<<"\n\nSeleccione la tabla de verdad que desea ver\n";
		cout<<"1.Conjuncion (^)\n";
		cout<<"2.Disyuncion (v)\n";
		cout<<"3.Implicacion logica (=>)\n";
		cout<<"4.Bicondicional (<=>)\n";
		cout<<"5.Salir\n";
		cout<<"\nOp:_";
		cin>>opc;
					
		switch(opc)
		{
			case 1:
				symbol = "^";
				
				//Función que imprime la tabla
				displayTable(symbol, no_prop);
				
				break;
			case 2:
				symbol = "v";
				
				//Función que imprime la tabla
				displayTable(symbol, no_prop);
				
				break;
			case 3:	
				symbol = "=>";
			
				//Función que imprime la tabla
				displayTable(symbol, no_prop);
				
				break;
			case 4:
				symbol = "<=>";
				
				//Función que imprime la tabla
				displayTable(symbol, no_prop);
				
				break;
			case 5:
				getch();
				break;
			default:
				cout<<"Opcion invalida!\n";
				getch();
				
				break;
		}	
		
	}
		
	return 0;
}

//Funcion que despliega la tabla de verdad según las proposiciones 
//y el tipo de tabla que escogió el usuario
void displayTable(string symbol, int no_prop)
{
	char vocabulary[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char letters[no_prop];
	double size = 0;
	int divisor = 1;
	int dimension = 0, counter = 0;
	
	//Establecimiento de las letras para las proposiciones
	for(int i = 0; i < no_prop; i++)
	{		
		letters[i] = vocabulary[i + 15];
	}
	
	//-------------------TITULO----------------------------
	
	//Función que imprime una línea arreglada
	linea(no_prop);
	
	//Proposiciones
	for(int i = 0; i < no_prop; i++)
	{
		cout<<"|  "<<letters[i]<<"  ";
	}
	
	cout<<"|  ";
	for(int i = 0; i < no_prop; i++)
	{
		cout<<letters[i]<<"  ";
		
		if(i == no_prop - 1)
		{
			break;
		}
		
		cout<<symbol<<"  ";
	}
	cout<<" |\n";
	
	//-------------CONTENIDO--------------
	//Linea que defnine el techo del contenido 	
	linea(no_prop);
	
	size = pow(2, no_prop);
	
	//INICIALIZACIÓN DE LOS VALORES DE LA TABLA
	int values[(int) size][no_prop];
	
	for(int i = 0; i < no_prop; i++)
	{
		for(int j = 0; j < ((int) size); j++)
		{
			//No. de repeticiones por 1 o 0.
			dimension = ((int) pow(2, (double) divisor));
			
			if(counter < ((int) size / dimension))
			{
				values[j][i] = 1;	
			}
			else if(counter >= ((int) size / dimension))
			{
				values[j][i] = 0;
				
				if(counter == (((int) size / dimension) + ((int) size / dimension)) - 1)	
				{
					counter = -1;
				}
			}
			
			counter++;
		}
		counter = 0;
		divisor += 1;
	}
	
	for(int i = 0; i < ((int) size); i++)
	{
		for(int j = 0; j < no_prop; j++)
		{
			cout<<values[i][j]<<"  ";
		}
		cout<<endl;
	}
		
	cout<<"|  ";
		
	getch();
	
}

//Funcion que imprime una linea basada en el numero de proposiciones, expresiones, etc.
void linea(int no_prop)
{
	//Espacio para cada proposición
	for(int i = 0; i < (no_prop * 7); i++)
	{
		cout<<"-";
	}	
	
	//Espacio para la expresión
	for(int i = 0; i < (no_prop * 6); i++)
	{
		cout<<"-";
	}
	
	//New line
	cout<<"\n";
}