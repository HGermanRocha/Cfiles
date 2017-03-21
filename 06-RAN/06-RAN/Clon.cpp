#include <iostream>
#include <string>
#include <cmath>

#include "Cola.h"

using namespace std;

TDA_Cola clon(TDA_Cola c)
{
	TDA_Cola a;
	
	a=c;
	
	return a;
}

int main()
{
	TDA_Cola c;
	TDA_Cola d;
	
	c.crearCola();
	
	c.insertar('e');
	c.insertar('r');
	c.insertar('t');
	
	d = clon(c);
	
	cout<<"*****ORIGINAL*****"<<endl<<endl;
	c.imprimir();
	
	cout<<endl<<endl<<"*****CLON*****"<<endl<<endl;
	
	d.imprimir();
	
	return 0;
}