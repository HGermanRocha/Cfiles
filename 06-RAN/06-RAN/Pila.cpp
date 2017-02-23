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
			int aberturas = 0, cerraduras = 0;
			int aber1 = 0, cer1 = 0;
			char type;
			
			string expresion = "{3*[(9-7)+(8*3)]}";
			
			for(int i = 0; i < expresion.length(); i++)
			{
				if(expresion[i] == '{' || expresion[i] == '(' || expresion[i] == '[' )
				{
					aber1++;
				}
				else if(expresion[i] == '}' || expresion[i] == ')' || expresion[i] == ']' )
				{
					cer1++;
				}
				if(expresion[i] == '{')
				{
					type = '}';
					aberturas++;
					for(int j = i; j < expresion.length(); j++)
					{
						if(expresion[j] == type)
						{
							cerraduras++;
							break;
						}
					}
				}
				else if(expresion[i] == '(')
				{
					type = ')';
					aberturas++;
					for(int j = i; j < expresion.length(); j++)
					{
						if(expresion[j] == type)
						{
							cerraduras++;
							break;
						}
					}
					
				}
				else if(expresion[i] == '[')
				{
					type = ']';
					aberturas++;
					for(int j = i; j < expresion.length(); j++)
					{
						if(expresion[j] == type)
						{
							cerraduras++;
							break;
						}
					}
				}	
			
			}                                                                                                             	
			
			return aberturas==cerraduras && aber1==cer1;
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