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

string blankSpaces(int no_prop, string symbol);
void resultados(string symbol, int array[][5]);
void linea(int no_prop, char tipo, string symbol);
void displayTable(string symbol, int no_prop);

int main()
{
	int no_prop = 0, opc = 0;
	string symbol = "";
	
	while(opc != 5)
	{
		system("cls");
		
		cout<<"\t\tGENERADOR DE TABLAS DE VERDAD\n\n";
		
		cout<<"\n\nSeleccione la tabla de verdad que desea ver\n";
		cout<<"1.Conjuncion (^)\n";
		cout<<"2.Disyuncion (v)\n";
		cout<<"3.Implicacion logica (=>)\n";
		cout<<"4.Bicondicional (<=>)\n";
		cout<<"5.Salir\n";
		cout<<"\nOp:_";
		cin>>opc;
		
		if(opc != 5)
		{
			cout<<"\n\nIngrese el numero de proposiciones: ";
			cin>>no_prop;
		}
					
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
	char tipo;
	bool condi = true;
	string blankSpace;
	double size = pow(2, no_prop);
	int divisor = 1, helper = 0;
	int dimension = 0, counter = 0, counter2 = 0;
	int values[(int) size][no_prop];
	bool verdad[(int) size][no_prop];
	int resultado[(int) size];
	
	//Establecimiento de las letras para las proposiciones
	for(int i = 0; i < no_prop; i++)
	{		
		letters[i] = vocabulary[i + 15];
	}
	
	//-------------------TITULO----------------------------
	
	//Función que imprime una línea arreglada
	tipo ='_';
	linea(no_prop, tipo, symbol);
	
	//Proposiciones
	for(int i = 0; i < no_prop; i++)
	{
		cout<<"|  "<<letters[i]<<"  ";
	}
	
	//Expresión
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
	cout<<"  |\n";
	
	//-------------CONTENIDO--------------
	//Linea que defnine el techo del contenido
	tipo = '-'; 	
	linea(no_prop, tipo, symbol);
	
	//INICIALIZACIÓN DE LOS VALORES DE LA TABLA
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
	
	//Señalamiento de los valores de verdad de 0 y 1
	for(int i = 0; i < ((int) size); i++)
	{
		for(int j = 0; j < no_prop; j++)
		{			
			if(values[i][j] == 1)
			{
				verdad[i][j] = true;
			}
			else
			{
				verdad[i][j] = false;
			}
		}
	}
	
	//----------------RESULTADO DE LAS TABLAS DE VERDAD SEGÚN SU RESPECTIVO TIPO (^, V, =>, <=>)---------------------------
	//CÁLCULO DE LAS CONJUNCIONES
	if(symbol == "^")
	{
		for(int i = 0; i < ((int) size); i++)
		{
			for(int j = 0; j < no_prop; j++)
			{			
				if(verdad[i][j])
				{
					helper += 1;
				}
				else
				{
					helper -= 1;
				}
			}
			
			if(helper == no_prop)
			{
				resultado[i] = 1;
			}
			else
			{
				resultado[i] = 0;
			}
			helper = 0;
		}
	}
	//CALCULO DE LAS DISYUNCIONES
	else if(symbol == "v")
	{
		for(int i = 0; i < ((int) size); i++)
		{
			for(int j = 0; j < no_prop; j++)
			{			
				if(verdad[i][j])
				{
					helper += 1;
				}
			}
			
			if(helper >= 1)
			{
				resultado[i] = 1;
			}
			else
			{
				resultado[i] = 0;
			}
			helper = 0;
		}
	}
	//CÁLCULO DE LAS IMPLICACIONES
	else if(symbol == "=>")
	{	
		for(int i = 0; i < ((int) size); i++)
		{
			condi = verdad[i][0];
			
			for(int j = 0; j < no_prop - 1; j++)
			{			
				if(condi && verdad[i][j + 1])
				{
					condi = true;
				}
				else if(condi && !verdad[i][j + 1])
				{
					condi = false;
				}
				else if(!condi && verdad[i][j + 1])
				{
					condi = true;
				}
				else if(!condi && !verdad[i][j + 1])
				{
					condi = true;
				}
			}
			
			if(condi == true)
			{
				resultado[i] = 1;
			}
			else
			{
				resultado[i] = 0;
			}
		}
	}
	//CÁLCULO DE LAS BICONDICIONALES
	else if(symbol == "<=>")
	{
		for(int i = 0; i < ((int) size); i++)
		{
			for(int j = 0; j < no_prop - 1; j++)
			{			
				if(values[i][j] == values[i][j + 1])
				{
					helper += 1;
				}
			}
			
			if(helper == no_prop - 1)
			{
				resultado[i] = 1;
			}
			else
			{
				resultado[i] = 0;
			}
			helper = 0;
		}
	}
	
	//SALIDA DE LOS VALORES DE LA TABLA PARA EL USUARIO
	blankSpace = blankSpaces(no_prop, symbol);
	
	for(int i = 0; i < ((int) size); i++)
	{
		for(int j = 0; j < no_prop; j++)
		{			
			cout<<"|  "<<values[i][j]<<"  ";
		}
		cout<<"|"<<blankSpace<<resultado[i]<<blankSpace<<"|";
		cout<<endl;
	}
	
	//Dibuja una línea
	tipo = '-';
	linea(no_prop, tipo, symbol);
	
	getch();
	
}

//Funcion que imprime una linea basada en el numero de proposiciones, expresiones, etc.
void linea(int no_prop, char tipo, string symbol)
{
	int size = ceil(12.5 * no_prop);
	
	if(symbol == "=>")
	{
		for(int i = 0; i < size + (1 * (no_prop - 1)); i++)
		{
			cout<<tipo;
		}	
	}
	else if(symbol == "<=>")
	{
		for(int i = 0; i < size + (2 * (no_prop - 1)); i++)
		{
			cout<<tipo;
		}	
	}
	else
	{
		for(int i = 0; i < size; i++)
		{
			cout<<tipo;
		}
	}
	
	//New line
	cout<<"\n";
}

string blankSpaces(int no_prop, string symbol)
{
	string word = "";
	int x;
	
	if(symbol == "=>")
	{
		x = ceil(((5 * no_prop) + (2 * (no_prop - 1))) / 2);
	}
	else if(symbol == "<=>")
	{
		x = ceil(((5 * no_prop) + (3 * (no_prop - 1))) / 2);
	}
	else
	{
		x = ceil(((5 * no_prop) + (1 * (no_prop - 1))) / 2);
	}
	
	for(int i = 0; i < x; i++)
	{
		word += " ";
	}
	
	return word;
}