/*
	Ejercicio #1;
	
	Nombre: Héctor Germán Rocha Ramírez
	Matrícula: 150307
	Profesor: Valentín Baez Trejo
	Materia: Metodología de la programación
*/

//Inclusión de librerías
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <string>

using namespace std;

//Inicialización de funciones
int getRandomNumber();
bool checkContinue(string word);
void displayBote(float bote_usuario, float bote_total);

int main()
{
	//Declaración de variables
	int accion = 1, dado1 = 0, dado2 = 0, suma = 0, objetivo = 0, tiro = 0, helper = 1, random = 0;
	float bote_total = 0, bote_usuario = 5, bote_casa = 10, ganancias_casa = 0, acum_ganancias = 0;
	string respuesta = "";
	
	//Inicialización de un arreglo que almacenará frases que se dirán al azar cuando el jugador
	//no pueda dar en su objetivo
	string expresiones[6] = {"Intenta una vez mas", "Estuviste cerca!", "Lanza de nuevo", "Mejor suerte para la proxima", "Tu puedes, vamos!", "Casi! Prueba otra vez!"} ;
	
	
	//Aqui empieza el programa. NOTA: Este loop se repetirá hasta que la variable 'helper'
	//sea diferente de 0 o en otras palabras, hasta que el jugador ya no desee jugar.
	while(true)
	{
		tiro = 1; 	//1er tiro del jugador
		
		while (true)
		{
			system("cls");	
			
			dado1 = getRandomNumber();					//Valor random para el 1er dado. Aquí se llama la funcion getRandomNumber() explicado al final del código
			
			cout<<"\t\tJUGEMOS CRAPS\n";
			
			bote_total = bote_usuario + bote_casa;		//bote_total es la variable que almacena la apuesta de la casa y del usuario o jugador
			
			ganancias_casa = bote_casa;
			
			displayBote(bote_usuario, bote_total);		//Se llama la función displayBote() explicada al final del código
	
			cout<<"\nPara comenzar presione ENTER\n";
			getch();
		
			dado2 = getRandomNumber();					//Valor random para el 2do. dado.
			
			suma = dado1 + dado2;						//Suma es la adición de los valores de los dados para después señalar un objetivo o si el jugador-
														//gana o pierde
														
			system("cls");
			cout<<"\t\tCRAPS\n\nEl resultado de sus dados es:\n";
			
			cout<<"Dado 1: "<<dado1<<"\nDado 2: "<<dado2<<"\n\n";			
	
			if((suma == 7) || (suma == 11))					//Si el resultado de la suma de los dos dados es igual a 7 u 11 el jugador gana
			{	
				bote_usuario = (bote_total / 2);			//Si el  jugador gana obtiene la mitad del bote_total
				bote_casa = (bote_total / 2);				//lo mismo con el capital de la casa
				
				cout<<"Ganaste!\nBote propio: "<<bote_usuario<<" Pesos\nDesea continuar apostando? (si/no)\n";
				cin>>respuesta;
				
				if(checkContinue(respuesta))								//Se llama la funcion checkContinue() explicada al final del código
				{
					acum_ganancias -= (ganancias_casa - bote_usuario) + 5;	//Si el jugador desea seguir jugando la casa pierde. Aqui se define la pérdida
					
					bote_casa += 5;							//Si el jugador gana la casa tiene que poner 5 pesos para la siguiente ronda
					system("cls");							//Para mayor información CHECAR LA DOCUMENTACIÓN DEL PROGRAMA en la sección "Sistema de apuestas"
				}
				
				else if (checkContinue(respuesta) == false) 
				{
					acum_ganancias -= (ganancias_casa - bote_usuario);			//Si el jugador no desea continuar la casa sólo pierde el bote_usuario
					
					helper = 0;								//Ya que el jugador desea salir helper deberá ser 0 para cerrar el programa
					break;
				}
	
			}
			else if((suma == 2) || (suma == 3) || (suma == 12))				//Si la suma de los dados es alguno de estos valores entonces el jugador pierde
			{
				cout<<"Perdiste!\n\nDesea continuar apostando? (si/no)\n";	
				cin>>respuesta;
				
				bote_casa += bote_usuario;					//Si el jugador pierde, entonces la casa gana y su capital ahora es igual a todo el bote_total 
				bote_usuario = 0;							//Como el jugador perdió, su capital ahora es de 0 puesto que la casa gana todo el capital
				
				acum_ganancias += bote_usuario;							
				
				if(checkContinue(respuesta))
				{
					bote_usuario += 5;
					system("cls");
				}
				
				else if (checkContinue(respuesta) == false)
				{
					helper = 0;
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
					bote_casa = (bote_total / 2);
					
					cout<<"Ganaste!\nBote propio: "<<bote_usuario<<" Pesos\nDesea continuar apostando? (si/no)\n";	
					cin>>respuesta;
				
					if(checkContinue(respuesta))
					{
						acum_ganancias -= (ganancias_casa - bote_usuario) + 5;	
						
						bote_casa += 5;
						helper = 1;
					}
					else if(checkContinue(respuesta) == false)
					{
						acum_ganancias -= (ganancias_casa - bote_usuario);
						
						helper = 0;
					}
					
					break;
				}
				else if (suma == 7)
				{
					cout<<"Perdiste!\n\nDesea continuar apostando? (si/no)\n";
					cin>>respuesta;
					
					bote_casa += bote_usuario;
					bote_usuario = 0;
					
					acum_ganancias += bote_usuario;
					
					if(checkContinue(respuesta))
					{
						bote_usuario += 5;
						helper = 1;
					}
					else if(checkContinue(respuesta) == false)
					{
						helper = 0;
					}
	
					break;
				}
				else
				{
					random = getRandomNumber() - 1;
					cout<<expresiones[random];
				}
				
				tiro += 1;
			}	
			
		}
		
		if(helper == 0)
		{
			break;
		}
	}
	
	while(accion != 0)
	{
		system("cls");
		
		cout<<"Seleccione la accion que desea realizar: \n\n";
		cout<<"1.Ver saldo\n2.Bote final\n0.salir\n\n";
		cin>>accion;
		
		system("cls");
		
		switch(accion)
		{
			case 0:
				cout<<"\t\tGracias por jugar! :)\n\n\n\n\n\n\n";
				break;
			case 1:
				cout<<"\t\tSALDO FINAL\n\n";
				cout<<bote_usuario<<" pesos\n";
				break;
			case 2:
				cout<<"\t\tBOTE FINAL\n\n";
				cout<<bote_total<<" pesos\n";			
				break;
			case 3:
				cout<<"\t\t***REGISTRO DE GANANCIAS***\n\n";
				cout<<acum_ganancias<<" pesos\n\n\n\n\n";
				break;
			default:
				cout<<"Opcion invalida!\n";
				break;
		}	
		
		getch();
	}
	
	return 0;
}

//Despliega o muestra la salida del bote total y el bote propio
void displayBote(float bote_usuario, float bote_total)
{
	cout<<"\nBote total: "<<bote_total<<" pesos\tBote propio: "<<bote_usuario<<" pesos\n";
}

//Esta funcion analiza si el usuario desea seguir o no al ver si lo que ingresa es un 'si' para continuar 
//o un no para cerrar el programa. La función regresa un valor bool. En caso de que el jugador quiera seguir
//e ingrese 'si' en el teclado el programa regresa un 'true', de otro modo regresa 'false'

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

//Esta funcion genera un numero al azar entero y lo regresa al lugar donde
//la están llamando
int getRandomNumber()
{
	int number;
	srand(time(NULL));
		
	number = 1 + rand()%6;
	
	return number;	
}













































/*
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
*/
//*************************************************************---------
/*
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
	int accion = 0, dado1 = 0, dado2 = 0, suma = 0, objetivo = 0, tiro = 0, helper = 1, random = 0;
	float bote_total = 0, bote_usuario = 5, bote_casa = 10, ganancias_casa = 0;
	string respuesta = "";
	string expresiones[5] = {"Estuviste cerca!", "Lanza de nuevo", "Mejor suerte para la proxima", "Tu puedes, vamos!", "Casi! Prueba otra vez!"} ;
	
	while(true)
	{
		tiro = 1;
		
		while (true)
		{
			system("cls");
			
			dado1 = getRandomNumber();
			
			cout<<"\t\tJUGEMOS CRAPS\n";
			
			bote_total = bote_usuario + bote_casa;
	
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
				bote_casa = (bote_total / 2);
				
				cout<<"Ganaste!\nBote propio: "<<bote_usuario<<" Pesos\nDesea continuar apostando? (si/no)\n";
				cin>>respuesta;
				
				if(checkContinue(respuesta))
				{
					bote_casa += 5;
					system("cls");
				}
				
				else if (checkContinue(respuesta) == false)
				{
					helper = 0;
					break;
				}
	
			}
			else if((suma == 2) || (suma == 3) || (suma == 12))
			{
				cout<<"Perdiste!\n\nDesea continuar apostando? (si/no)\n";
				cin>>respuesta;
				
				bote_casa += bote_usuario;
				bote_usuario = 0;
				
				if(checkContinue(respuesta))
				{
					bote_usuario += 5;
					system("cls");
				}
				
				else if (checkContinue(respuesta) == false)
				{
					helper = 0;
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
					bote_casa = (bote_total / 2);
					
					cout<<"Ganaste!\nBote propio: "<<bote_usuario<<" Pesos\nDesea continuar apostando? (si/no)\n";	
					cin>>respuesta;
				
					if(checkContinue(respuesta))
					{
						bote_casa += 5;
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
					
					bote_casa += bote_usuario;
					bote_usuario = 0;
					
					if(checkContinue(respuesta))
					{
						bote_usuario += 5;
						helper = 1;
					}
					else if(checkContinue(respuesta) == false)
					{
						helper = 0;
					}
	
					break;
				}
				else
				{
					random = getRandomNumber() - 1;
					cout<<expresiones[random];
				}
				
				tiro += 1;
			}	
			
		}
		
		if(helper == 0)
		{
			break;
		}
	}
	
	ganancias_casa = (bote_total - bote_usuario) - 10;
	
	system("cls");
	cout<<"Seleccione la accion que desea realizar: \n\n";
	cout<<"1.Ver saldo\n2.Bote final\n";
	cin>>accion;
	
	system("cls");
	
	switch(accion)
	{
		case 1:
			cout<<"\t\tSALDO FINAL\n\n";
			cout<<bote_usuario<<" pesos\n";
			break;
		case 2:
			cout<<"\t\tBOTE FINAL\n\n";
			cout<<bote_total<<" pesos\n";			
			break;
		case 3:
			cout<<"\t\t***REGISTRO DE GANANCIAS***\n\n";
			cout<<ganancias_casa<<" pesos\n\n\n\n\n";
			break;
		default:
			cout<<"Opcion invalida!\n";
			break;
	}
	
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
*/