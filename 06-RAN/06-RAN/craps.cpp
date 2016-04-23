#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <string>

using namespace std;

int getRandomNumber();
bool checkContinue(string word);
void displayBote(float bote_usuario, float bote_total);

int main()
{
	int dado1, dado2, suma = 0, objetivo = 0, tiro = 1;
	float bote_total = 10, bote_usuario = 5;
	string respuesta = "";
	
	cout<<"\t\tJUGEMOS CRAPS\n";
	
	while (true)
	{
		system("cls");

		cout<<"\t\tJUGEMOS CRAPS\n";
		
		bote_total += bote_usuario;

		displayBote(bote_usuario, bote_total);

		cout<<"\nPara comenzar presione ENTER\n";
		getch();
		
		dado1 = getRandomNumber();
		dado2 = getRandomNumber();
		
		suma = dado1 + dado2;
		
		system("cls");
		cout<<"\nEl resultado de sus dados es:\n";
		
		cout<<"Dado 1: "<<dado1<<"\nDado 2: "<<dado2<<"\n\n";

		if((suma == 7) || (suma == 11))
		{
			bote_usuario = (bote_total / 2);
			
			cout<<"Ganaste!\nBote propio: "<<bote_usuario<<" Pesos\nDesea continuar apostando? (si/no)\n";
			cin>>respuesta;
			
			if(checkContinue(respuesta))
			{
				system("cls");
			}
			
			else if (checkContinue(respuesta) == false)
			{
				break;
			}

		}
		else if((suma == 2) || (suma == 3) || (suma == 12))
		{
			cout<<"Perdiste!\nDesea continuar apostando? (si/no)\n";
			cin>>respuesta;
			
			if(checkContinue(respuesta))
			{
				cout<<"Presiona ENTER para continuar\n";
			}
			
			else if (checkContinue(respuesta) == false)
			{
				break;
			}
			
			getch();
		}
		else
		{
			objetivo = suma;
			tiro += 1;
		
			break;
		}
				
	}
	
	if(tiro > 1)
	{
		cout<<"Su objetivo es "<< objetivo;
		getch();
				
		while(suma != objetivo)
		{
			
		}	
		
	}

	cout<<"\nGracias por jugar!\n";
	
	return 0;
}

void displayBote(float bote_usuario, float bote_total)
{
	cout<<"\nBote total: "<<bote_total<<" pesos\tBote propio: "<<bote_usuario<<" pesos\n";
}

bool checkContinue(string word)
{
	bool accepted;
	
	if(word == "si" || word == "Si" || word == "sI" || word == "SI")
	{
		accepted = true;
	}
	else
	{
		accepted = false;
	}
	
	return accepted;
}

int getRandomNumber()
{
	int number;
	srand(time(NULL));
		
	number = 1 + rand()%6;
	
	return number;	
}