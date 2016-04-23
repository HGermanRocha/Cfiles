#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <string>

using namespace std;

void timer(int x);
int getRandomNumber();
bool checkContinue(string word);
void displayBote(float bote_usuario, float bote_total);

int main()
{
	int dado1, dado2, suma = 0, objetivo = 0, tiro = 0, helper = 1;
	float bote_total = 10, bote_usuario = 5;
	string respuesta = "";
	
	while(true)
	{
		tiro = 1;
		
		while (true)
		{
			system("cls");
			
			dado1 = getRandomNumber();
			
			cout<<"\t\tJUGEMOS CRAPS\n";
			
			bote_total += 5;
	
			displayBote(bote_usuario, bote_total);
	
			cout<<"\nPara comenzar presione ENTER\n";
			getch();
		
			dado2 = getRandomNumber();
			
			suma = dado1 + dado2;
			
			system("cls");
			cout<<"\t\tCRAPS\n\nEl resultado de sus dados es:\n";
			
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
				cout<<"Perdiste!\n\nDesea continuar apostando? (si/no)\n";
				cin>>respuesta;
				
				if(checkContinue(respuesta))
				{
					bote_usuario = 5;
					system("cls");
				}
				
				else if (checkContinue(respuesta) == false)
				{
					bote_usuario = 0;
					break;
				}
				
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
			
			while(true)
			{
				dado1 = getRandomNumber();
				
				cout<<"\n\nPresione ENTER para lanzar de nuevo\n";
				getch();
				
				system("cls");
				
				cout<<"\t\tCRAPS\n\n";
				cout<<"Para ganar debe obtener un "<<objetivo<<" al lanzar los dados.\nPero si le cae un 7 PIERDE\n\n";
				cout<<"Presione ENTER para continuar\n\n";
				getch();
				cout<<"Tiro #"<<tiro<<"\n\nEl resultado de sus dados es:\n";
				
				dado2 = getRandomNumber();
				
				cout<<"Dado 1: "<<dado1<<"\nDado 2: "<<dado2<<"\n\n";
				
				suma = dado1 + dado2;
				
				if(suma == objetivo)
				{
					bote_usuario = (bote_total / 2);
				
					cout<<"Ganaste!\nBote propio: "<<bote_usuario<<" Pesos\nDesea continuar apostando? (si/no)\n";	
					cin>>respuesta;
				
					if(checkContinue(respuesta))
					{
						helper = 1;
					}
					else if(checkContinue(respuesta) == false)
					{
						helper = 0;
					}
					
					break;
				}
				else if (suma == 7)
				{
					cout<<"Perdiste!\n\nDesea continuar apostando? (si/no)\n";
					cin>>respuesta;
				
					if(checkContinue(respuesta))
					{
						bote_usuario = 5;
						helper = 1;
					}
					else if(checkContinue(respuesta) == false)
					{
						bote_usuario = 0;
						helper = 0;
					}
	
					break;
				}
				else
				{
					cout<<"Estuviste cerca!";
				}
				
				tiro += 1;
			}	
			
		}
		
		if(helper == 0)
		{
			break;
		}
	}
	
	cout<<"\n\nPara ver sus resultados presione ENTER";
	
	getch();
	
	system("cls");
	cout<<"\t\tSCRABS\n\nGanancias totales: "<<bote_usuario<<" pesos\n\n\nGracias por jugar!\n";
	
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

void timer(int x)
{
	int number = 0;
	
	for(int i = 0; i < x; i++)
	{
		number = i;	
	}
}