#include <iostream>
#include <math.h>
#include <time.h>
#include <conio.h>

using namespace std;

void displayBote(float bote_usuario, float bote_casa, float bote_total);

int main()
{
	int m1, m2, objetivo = 0, tiro = 0;
	float bote_total = 0, bote_casa = 10, bote_usuario = 0;
	bool ganar = false;

	while (ganar == false)
	{
		tiro += 1;
		srand(time(NULL));
	
		m1 = 1 + rand()%6;
		m2 = 1 + rand()%6;
		objetivo = m1 + m2;

		cout<<"Jugemos Craps\n\n";
		cout<<"Para comenzar debes apostar 5 pesos\n";
		


		bote_usuario = 5;
		bote_total = bote_usuario + bote_casa;

		displayBote(bote_usuario, bote_casa, bote_total);

		cout<<"\nEl resultado de sus dados es:\n";
		cout<<"Dado 1: "<<m1<<"\nDado 2: "<<m2<<"\n\n";

		if((objetivo == 7) || (objetivo == 11) && (tiro == 1))
		{
			ganar = true;
			cout<<"Ganaste!\nPresiona ENTER para continuar";
			
			getch();

            bote_total = bote_usuario + bote_casa;
			bote_usuario = (bote_total / 2);

			displayBote(bote_usuario, bote_casa, bote_total);
		}
		else if((objetivo == 2) || (objetivo == 3) || (objetivo == 12) && (tiro == 1))
		{
			ganar  = false;
		}

		getch();
				
	}

	return 0;
}

void displayBote(float bote_usuario, float bote_casa, float bote_total)
{
	cout<<"\nBote total: "<<bote_total<<" pesos\tBote propio: "<<bote_usuario<<" pesos\tBote casa: "<<bote_casa<<" pesos\n";
}