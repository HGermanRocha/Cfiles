#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include<cstdlib>

void principiante(int, float &punt);
void intermedio(int, float &punt);
void avanzado(int, float &punt);
void checkGrado(int &num);
int CheckSeguir();

using namespace std;

int main ()
{
	string nombre, apellido, grupo;
	int grado;
	float puntuacion = 0;

	while(true)
	{
		cout<<"\t\tJUEGO DE PREGUNTAS\n\n";
		cout<<"Nombre: ";
		cin>>nombre;
		cout<<"\nApellido: ";
		cin>>apellido;
		cout<<"\nGrado: ";
		cin>>grado;
		//Función
		checkGrado(grado);

		cout<<"\nGrupo: ";
		cin>>grupo;

		cout<<"\nA continuacion se le mostrara el nivel de juego dependiendo de su grado\ny podra seleccionar ";
		cout<<"alguna materia que posee un paquete de preguntas que\nsegun su nivel de dificultad es la puntuacion que le da.";
		cout<<"\n\nPara continuar presione \'Enter\'\n";

		getch();
		system("cls");

		if(grado > 0 && grado < 3)
		{
			principiante(grado, puntuacion);
		}
		else if(grado > 2 && grado < 5)
		{
			intermedio(grado, puntuacion);
		}
		else if(grado > 4 && grado < 7)
		{
			avanzado(grado, puntuacion);
		}

		cout<<"\n\nPuntuacion Final: "<<puntuacion;

		getch();

		system("cls");
	}

	return 0;
}

void principiante(int grado, float &punt)
{

}

void intermedio(int grado, float &punt)
{

}

void avanzado(int grado, float &punt)
{
	int opc, sol, res;
	float valor = 0;
	int parar = 0;

	while(true)
	{
		cout<<"\t\tAVANZADO\n\n";
		cout<<"Seleccione alguna materia:\n";
		cout<<"1.Historia\n2.Matematicas\n3.Geografia\n";
		cin>>opc;
		if(opc == 4)
		{
			break;
		}

		system("cls");

		switch(opc)
		{
			case 1:
				while(true)
				{
					cout<<"\t\tHISTORIA\n\n";
					cout<<"Pregunta 1\t\tValor: 0.25pts\n\n";
					sol = 1;
					valor = 0.25;
					cout<<"Quien de los siguientes NO fue presidente de Mexico:\n";
					cout<<"1.Francisco Villa\t2.Venustiano Carranza\t3.Manuel Gomez\n";
					cin>>res;
					if(res == sol)
					{
						punt += valor;
					}
					else
					{
						punt += 0;
					}

					parar = CheckSeguir();

					if(parar == 1)
					{
						break;
					}

					system("cls");

					cout<<"\t\tHISTORIA\n\n";
					cout<<"Pregunta 2\t\tValor: 0.50pts\n\n";
					sol = 2;
					valor = 0.50;
					cout<<"A quien se le conoce como  el \'Maestro de America\'?\n";
					cout<<"1.Benito Juarez\t2.Justo Sierra\t3.Octavio Paz\n";
					cin>>res;

					parar = CheckSeguir();

					if(parar == 1)
					{
						break;
					}

					if(res == sol)
					{
						punt += valor;
					}
					else
					{
						punt += 0;
					}
				}
				break;
			case 2:
				cout<<"\t\tMATEMATICAS\n\n";
				break;
			case 3:
				cout<<"\t\tGEOGRAFIA\n\n";
				break;
			default:
				cout<<"Opcion invalida!";
				break;
		}
	}
}

void checkGrado(int &num)
{
	while(num < 1 && num > 6)
	{
		system("cls");

		cout<<"Grado invalido!\n";
		cout<<"Grado: ";
		cin>>num;
	}
}

int CheckSeguir()
{
	int parar;
	cout<<"Si desea cambiar de materia presione 1, sino presione 0. \nNOTA: La dificultad de las preguntas va en aumento.\n";
	cin>>parar;

	return parar;
}