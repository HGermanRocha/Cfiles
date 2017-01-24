#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>

using namespace std;

class Conjunto
{
	public:
	int array[50] = {0};
	int length, counter = 0, posicion;
	void insertar(int numero, int pos); 
	void obtenerLongitud();
	void eliminar(int numero);
	void obtenerPosicion(int num);
	void imprimir();
	void acomodarPosiciones();
};

void Conjunto::insertar(int numero, int pos)
{
	array[pos] = numero;
}
void Conjunto::imprimir()
{
	//system("cls");
	this->obtenerLongitud();
	
	for(int i= counter- 1;i>= 0; i--)
	{
		cout<<array[i]<<endl;
	}
	counter = 0;
}
void Conjunto::obtenerLongitud()
{
	for(int i = 0; i < 50; i++)
	{
		if(array[i]!= 0)
		{
			counter++;
		}
		else
		{
			break;
		}
		
	}
}
void Conjunto::eliminar(int numero)
{
	this->obtenerPosicion(numero);
	this->obtenerLongitud();
	array[posicion] = 0;
	this->acomodarPosiciones();
}

void Conjunto::obtenerPosicion(int num)
{
	this->obtenerLongitud();
	
	for(int i = 0; i < counter; i++)
	{
		if(num == array[i])
		{
			posicion = i;
		}
	}
	counter = 0;
}
void Conjunto::acomodarPosiciones()
{
	int calc = counter - posicion;
	
	for(int i = 0; i < calc; i++)
	{
		array[posicion] = array[posicion + 1];
		array[posicion + 1] = array[posicion + 2];
		posicion++;
	}
	posicion -= calc;
	counter = 0;
}

int main()
{
	int num, p = 0, elem, opc, iteraciones = 0, checker = 0;
	
	Conjunto Obj;
	
	while(true)
	{
		cout<<endl<<endl<<"Por favor seleccione la opcion que desea realizar: "<<endl;
		if(iteraciones > 0)
		{
			cout<<"1. Insertar un elemento"<<endl;
			cout<<"2. Eliminar un elemento"<<endl;
		}
		else
		{
			cout<<"1. Insertar un elemento"<<endl;
		}
		cin>>opc;
		
		system("cls");
		
		switch(opc)
		{
			case 1:
				cout<<"Ingrese el numero que desea insertar: ";
				cin>>num;
				
				cout<<Obj.getNumber(num);
								
				Obj.insertar(num, p);
				
				system("cls");
				Obj.imprimir();
		
				p++;
				iteraciones++;
				break;
			case 2:
				cout<<"Ingrese el elemento que desea eliminar: ";
				cin>>elem;
				Obj.eliminar(elem);
				p-=2;
				
				system("cls");
				Obj.imprimir();
		
				p++;
				iteraciones++;
				break;
			default:
				cout<<"Opcion invalida!";
				break;
		}
		
		getch();

	}
	
	system("cls");
	return 0;	
}/