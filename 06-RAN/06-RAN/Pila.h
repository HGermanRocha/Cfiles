#include <iostream>
#include <string>
#include <cmath>

using namespace std;

typedef char TIPO_DE_DATO;

#define MAX 6

class TDA_Pila
{
    private:
		int n;
		int pos;
		TIPO_DE_DATO arreglo[MAX] = {0};
	public:
		void crearPila()
		{
			pos = 0;
		}
		
		
		bool estaVacia()
		{	
			return (pos == 0);
		}
		bool llena()
		{
			return(pos == MAX);
		}
		bool push(TIPO_DE_DATO valor)
		{
			if(llena())
			{
				return false;
			}
			
			arreglo[pos] = valor;
			pos++;
			
			return true;
		}
		bool pop()
		{
			if(estaVacia())
			{
				return false;
			}
			
			pos--;
			arreglo[pos] = 0;
		
			return true;
		}
		TIPO_DE_DATO top()
		{
			return arreglo[pos-1];
		}

		void imprimir()
		{
			for(int i = pos-1; i >= 0; i--)
			{
				cout<<arreglo[i]<<endl;
			}
		}
};