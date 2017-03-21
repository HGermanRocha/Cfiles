#include <iostream>
#include <string>

#include "Cola.h"

using namespace std;

bool sonIguales(TDA_Cola c1, TDA_Cola c2)
{
	for(int i = 0; i < 4; i++)
	{
		if(c1.getFrente()!=c2.getFrente())
		{
			return false;
		}
		
		c1.eliminar();
		c2.eliminar();
	}
	
	return true;
}

int main()
{
	TDA_Cola c1;
	TDA_Cola c2;
	
	c1.crearCola();
	c2.crearCola();
	
	c1.insertar(15);
	c2.insertar(15);
	
	c1.insertar(78);
	c2.insertar(78);
	
	c1.insertar(45);
	c2.insertar(45);
	
	c1.insertar(23);
	c2.insertar(23);
	
	if(sonIguales(c1, c2))
	{
		cout<<"Las colas son iguales!";
	}
	else
	{
		cout<<"Las colas son diferentes!";
	}
	return 0;
}