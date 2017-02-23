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
		char arreglo[MAX] = {0};
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
		bool push(char valor)
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
		char top()
		{
			return arreglo[pos-1];
		}
		bool balanceada()
		{
			int counter1 = 0, counter2 = 0;
			char type;
			bool respuesta = false;
			
			string expresion = "{3*[(9-7)+(8*3)]}";
			
			for(int i = 0; i < expresion.length(); i++)
			{
				
				if(expresion[i] == '{')
				{
					type = '}';
					counter1++;
					for(int j = i; j < expresion.length(); j++)
					{
						if(expresion[j] == type)
						{
							cout<<type<<endl;
							counter2++;
							break;
						}
					}
				}
				else if(expresion[i] == '(')
				{
					type = ')';
					counter1++;
					for(int j = i; j < expresion.length(); j++)
					{
						if(expresion[j] == type)
						{
							counter2++;
							cout<<type<<endl;
							break;
						}
					}
					
				}
				else if(expresion[i] == '[')
				{
					type = ']';
					counter1++;
					for(int j = i; j < expresion.length(); j++)
					{
						if(expresion[j] == type)
						{
							counter2++;
							cout<<type<<endl;
							break;
						}
					}
				}	
			
			}                                                                                                             	
			
			return counter1==counter2;
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
	Pila p;	
	
	p.imprimir();
	
	if(p.balanceada())
	{
		cout<<"La expresion esta balanceada!";
	}
	else
	{
		cout<<"No esta balanceada";
	}
	
	cout<<endl;
	
	system("pause");
	
	return 0;
}