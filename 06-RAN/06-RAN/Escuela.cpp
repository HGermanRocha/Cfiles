#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include<cstdlib>

using namespace std;

void principiante(int, float &punt, string nombre, string apellido, string grupo);
void intermedio(int, float &punt, string nombre, string apellido, string grupo);
void avanzado(int, float &punt, string nombre, string apellido, string grupo);
void checkGrado(int &num);
int CheckSeguir();
void checkRespuesta(int res, int sol, float &punt, float valor, int &respuestas_correctas);
float Title(int &counter, string materia);
void Status(string nombre, string apellido, string grupo, int grado, int &respuestas_correctas, int counter, string materia);
void Operaciones(int nivel);

int main ()
{
	string nombre, apellido, grupo;
	int grado, seguir = 1; 
	float puntuacion = 0;

	while(true)
	{
		system("cls");
		
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
			//principiante(grado, puntuacion);
		}
		else if(grado > 2 && grado < 5)
		{
			//intermedio(grado, puntuacion);
		}
		else if(grado > 4 && grado < 7)
		{
			avanzado(grado, puntuacion, nombre, apellido, grupo);		
		}

		system("cls");
		cout<<"\t\tSTATUS FINAL";
		cout<<"\n\nPuntuacion Final: "<<puntuacion;
		
		if(puntuacion < 3)
		{
			cout<<"\n\nLo siento, reprobaste este examen\n";
		}
		else if (puntuacion >= 3 && puntuacion < 4.5)
		{
			cout<<"\n\nAprobaste! Sientete orgulloso\n";
		}
		else if(puntuacion == 4.5)
		{
			cout<<"\n\nFelicidades! Aprobaste este examen con honores!!!\n";
		}
		
		cout<<"\nDesea continuar?\n1.Si\t\t2.No\n";
		cin>>seguir;
		
		if(seguir == 2)
		{
			break;
		}
	}

	return 0;
}

void principiante(int grado, float &punt)
{

}

void intermedio(int grado, float &punt)
{

}

void avanzado(int grado, float &punt, string nombre, string apellido, string grupo)
{
	int opc, sol, res, pregunta = 1, pregunta2 = 1, pregunta3 = 1, terminar = 0, nivel = 3;
	float valor = 0;
	int parar = 0, counter = 1, counter2 = 1, counter3 = 1, correctas = 0, correctas2 = 0, correctas3 = 0;
	string materia = "";

	while(true)
	{
		system("cls");
		
		if (terminar == 3)
		{
			cout<<"\t\tAVANZADO\n\n";
			cout<<"Has terminado todos los paquetes!\n\nPara ver tu puntuacion final presiona \'ENTER\'";
			
			getch();
			
			break;
		}
		
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
				materia = "HISTORIA";
				
				while(true)
				{
					if(pregunta == 1)
					{	
						valor = Title(counter, materia);
						
						sol = 1;
						cout<<"Quien de los siguientes NO fue presidente de Mexico:\n";
						cout<<"1.Francisco Villa\t2.Venustiano Carranza\t3.Manuel Gomez\n";
						cin>>res;
	
						checkRespuesta(res, sol, punt, valor, correctas);				
	
						parar = CheckSeguir();
	
						pregunta++;
						
						if(parar == 1)
						{
							break;
						}
					}

					if(pregunta == 2)
					{
						valor = Title(counter, materia);
					
						sol = 2;
						cout<<"A quien se le conoce como  el \'Maestro de America\'?\n";
						cout<<"1.Benito Juarez\t2.Justo Sierra\t3.Octavio Paz\n";
						cin>>res;
						
						checkRespuesta(res, sol, punt, valor, correctas);
						
						parar = CheckSeguir();
	
						pregunta++;
						
						if(parar == 1)
						{
							break;
						}
					}
					
					if(pregunta == 3)
					{
						valor = Title(counter, materia);
					
						sol = 3;
						cout<<"Quien fue el primer presidente de Mexico?\n";
						cout<<"1.Benito Juarez\t2.Porfirio Diaz\t3.Guadalupe Victoria\n";
						cin>>res;
						
						checkRespuesta(res, sol, punt, valor, correctas);
						
						//-----STATUS------
						Status(nombre, apellido, grupo, grado, correctas, counter, materia);	
						
						pregunta++;
						terminar++;
						
						break;
					}	
					else
					{
						system("cls");
						cout<<"Usted ya completo este paquete, continue con el que le falte\n";
						
						getch();	
						
						break;
					}
				}
				
				break;
			case 2:
				materia = "MATEMATICAS";
				
				while(true)
				{
					if(pregunta2 == 1)
					{	
						valor = Title(counter2, materia);
						
						sol = 1;
						cout<<"Quien de los siguientes NO fue presidente de Mexico:\n";
						cout<<"1.Francisco Villa\t2.Venustiano Carranza\t3.Manuel Gomez\n";
						cin>>res;
	
						checkRespuesta(res, sol, punt, valor, correctas2);				
	
						parar = CheckSeguir();
	
						pregunta2++;
						
						if(parar == 1)
						{
							break;
						}
					}

					if(pregunta2 == 2)
					{
						valor = Title(counter2, materia);
					
						sol = 2;
						cout<<"A quien se le conoce como  el \'Maestro de America\'?\n";
						cout<<"1.Benito Juarez\t2.Justo Sierra\t3.Octavio Paz\n";
						cin>>res;
						
						checkRespuesta(res, sol, punt, valor, correctas2);
						
						parar = CheckSeguir();
	
						pregunta2++;
						
						if(parar == 1)
						{
							break;
						}
					}
					
					if(pregunta2 == 3)
					{
						valor = Title(counter2, materia);
					
						sol = 3;
						cout<<"Quien fue el primer presidente de Mexico?\n";
						cout<<"1.Benito Juarez\t2.Porfirio Diaz\t3.Guadalupe Victoria\n";
						cin>>res;
						
						checkRespuesta(res, sol, punt, valor, correctas2);
						
						//-----STATUS------
						Status(nombre, apellido, grupo, grado, correctas2, counter2, materia);	
						
						pregunta2++;
						terminar++;
						
						break;
					}	
					else
					{
						system("cls");
						cout<<"Usted ya completo este paquete, continue con el que le falte\n";
						
						getch();	
						
						break;	
					}
				}
				
				break;
			case 3:
				materia = "GEOGRAFIA";
				
				while(true)
				{
					if(pregunta3 == 1)
					{	
						valor = Title(counter3, materia);
						
						sol = 2;
						cout<<"Australia se encuentra en Europa\n";
						cout<<"1.Verdadero\t\t2.Falso\n";
						cin>>res;
	
						checkRespuesta(res, sol, punt, valor, correctas3);				
	
						parar = CheckSeguir();
	
						pregunta3++;
						
						if(parar == 1)
						{
							break;
						}
					}

					if(pregunta3 == 2)
					{
						valor = Title(counter3, materia);
					
						sol = 2;
						cout<<"Cuantos estados tiene la republica?\n";
						cout<<"1.31\t\t2.32\t\t3.28\n";
						cin>>res;
						
						checkRespuesta(res, sol, punt, valor, correctas3);
						
						parar = CheckSeguir();
	
						pregunta3++;
						
						if(parar == 1)
						{
							break;
						}
					}
					
					if(pregunta3 == 3)
					{
						valor = Title(counter3, materia);
					
						sol = 1;
						cout<<"Cual es la capital de Tabasco?\n";
						cout<<"1.Villahermosa\t2.Tabasco\t3.Tuxtla\n";
						cin>>res;
						
						checkRespuesta(res, sol, punt, valor, correctas3);
						
						//-----STATUS------
						Status(nombre, apellido, grupo, grado, correctas3, counter3, materia);	
						
						pregunta3++;
						terminar++;
						
						break;
					}	
					else
					{
						system("cls");
						cout<<"Usted ya completo este paquete, continue con el que le falte\n";
						
						getch();
						
						break;	
					}
				}
				
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
	
	cout<<"\nSi desea cambiar de materia presione 1, sino presione 0. \nNOTA: La dificultad de las preguntas va en aumento.\n";
	cin>>parar;

	return parar;
}

float Title(int &counter, string materia)
{
	float valor = 0.25;
	float helper = valor * counter;
	
	system("cls");
	cout<<"\t\t"<<materia<<"\n\nPregunta "<<counter<<"\t\tValor: "<<valor * counter<<"pts\n\n";
	
	counter++;
	
	return helper;
}

void checkRespuesta(int res, int sol, float &punt, float valor, int &respuestas_correctas)
{	
	if(res == sol)
	{
		punt += valor;
		respuestas_correctas++;
	}
	else
	{
		punt += 0;
	}	
	
}

void Status(string nombre, string apellido, string grupo, int grado, int &respuestas_correctas, int counter, string materia)
{
	system("cls");
	cout<<"\t\tSTATUS\n\n";
	cout<<"Nombre: "<<nombre<<"\nApellido: "<<apellido<<"\nGrado: "<<grado<<"\nGrupo: "<<grupo;
	cout<<"\n\nRespuestas correctas: "<<respuestas_correctas<<" de "<<counter - 1<<"\n"<<"Materia: "<<materia<<"\n";
	cout<<"Status: COMPLETADA\n\n";
	getch();
}

void Operaciones(int nivel)
{
	
}

/*cout<<"\t\tHISTORIA\n\n";
cout<<"Pregunta 1\t\tValor: 0.25pts\n\n";*/