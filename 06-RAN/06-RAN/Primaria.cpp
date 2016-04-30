#include<iostream>
#include<string>
#include<ctime>
#include<stdlib.h>
#include<cstdlib>
#include<ctype.h>
#include<cctype>

using namespace std;

bool checkContinue(string word);
int checkRespuesta(int respuesta);
int getRandomNumber();

int main()
{
	int x = 0, y = 0, solucion = 0, respuesta = 0, ejercicio = 0, correctas = 0;
	string nombre = "", seguir = "";

	srand(time(NULL));

	cout<<"\t\t   BIENVENIDO\n\nEste es un programa que te ayudara a mejorar tus habilidades \nen ";
	cout<<"las multiplicaciones. A continuacion se formularan \noperaciones que debes resolver ";
	cout<<"y obtendremos tu nivel en las \nmultiplicaciones.\n";

	cout<<"\nPara comenzar ingresa tus datos:\n\n";
	cout<<"Nombre: ";
	cin>>nombre;
	
	cout<<"\n\nMuchas gracias, para comenzar presiona ENTER\n";
	cin.get();

	while(true)
	{
		ejercicio++;


		x = 1 + rand()%10;
		y = 1 + rand()%10;
		solucion = x * y;

		cout<<"Ejercicio "<<ejercicio<<":\t\tRespuestas correctas: "<<correctas<<"\n\n";
		cout<<"Cuanto es "<<x<<" * "<<y<<"? ";
		cin>>respuesta;

		respuesta = checkRespuesta(respuesta);

		if(respuesta == solucion)
		{
			cout<<"\nCorrecto!\n";
		}
		else
		{
			cout<<"\nLo siento, la respuesta es incorrecta\n";
		}

		cout<<"Desea continuar? (si/no)";
		cin>>seguir;

		cin.get();
	}

	return 0;
}

int getRandomNumber()
{
	int number;
	srand(time(NULL));					
		
	number = 1 + rand()%10;
	
	return number;	
}

int checkRespuesta(int input)
{
	if(isdigit(input))
	{
		cout<<"Hi!";
	}
	else
	{
		cout<<"\nIngresa valores numericos no letras!\n";
	}

	return input;
}
bool checkRespuesta(string word)
{

}