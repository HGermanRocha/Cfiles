/* 
	Ejercicio del 19 de Abril de 2016

*/


#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int Lanzar();

int main()
{
	srand(time(NULL));
	int p1 = 0, p2 = 0, p3 = 0, p4 = 0, seguir = 0;
	bool op;

	do
	{
		op = false;

		p1 = 1 + rand()%2;
		p2 = 1 + rand()%2;
		p3 = 1 + rand()%2;
		p4 = 1 + rand()%2;

		cout<<"Jugando disparejo\nEl jugador 1 tiene: "<<p1<<"\nEl jugador 2 tiene: "<<p2<<"\n";
		cout<<"El jugador 3 tiene: "<<p3<<"\nEl jugador 4 tiene: "<<p4<<endl;

		if(p1 != p2 && p1 != p3 && p1 != p4)
		{
			cout<<"El jugador 1 gana\n";
		}
		else if(p2 != p1 && p2 != p3 && p2 != p4)
		{
			cout<<"El jugador 2 gana\n";
		}
		else if(p3 != p1 && p3 != p2 && p3 != p4)
		{
			cout<<"El jugador 3 gana\n";
		}
		else if(p4 != p1 && p4 != p3 && p4 != p2)
		{
			cout<<"El jugador 4 gana\n";
		}
		else
		{
			cout<<"Nadie gana. Desea continuar? (0/1) ";
			cin>>seguir;

			if(seguir == 1)
			{
				op = true;
			}
			else
			{
				op = false;
			}
		}
	}while(op == true);
	return 0;
}

int lanzar()
{
	return 1 + rand()%2;
}