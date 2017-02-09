#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define MAX 15

class Pila
{
	private:
		int n;
		int pos;
		int arreglo[MAX] = {0};
	public:
		
		void crearPila()
		{
			pos = 0;
		}
		
		
		bool vacia()
		{	
			return (pos == 0);
		}
		bool llena()
		{
			return(pos == MAX);
		}
		bool push(int valor)
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
			if(vacia())
			{
				return false;
			}
			
			pos--;
			arreglo[pos] = 0;
		
			return true;
		}
		int top()
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

int main()
{
	int i = 1; 
	Pila p;	
	
	while(true)
	{
		if(!p.push(i))
			break;
		i++;
	}
	p.imprimir();
	
	
	system("pause");
	
	return 0;
}