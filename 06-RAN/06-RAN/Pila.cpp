#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define MAX 9

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
		
		
		bool estaVacia()
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
			if(estaVacia())
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

		void imprimir()
		{
			for(int i = pos-1; i >= 0; i--)
			{
				cout<<arreglo[i]<<endl;
			}
		}
};

class Expresion
{
	private:
		string expresion;
		
	public:
		Expresion(string expresion="{3*[(9-7)+(8*3)]}")
		{
			this->expresion = expresion;
		}
		bool estaBalanceada()
		{
			int aberturas = 0, cerraduras = 0;
			int aber1 = 0, cer1 = 0;
			char type;
			
			//string expresion = "{3*[(9-7)+(8*3)]}";
			
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
		
		bool esMayor(char operador1, char operador2)
		{
			int prioridad1, prioridad2;
			char jerarquiaDeOperadores[7] = {')','(','-','+','/','*','^'};
			
			for(int i = 0; i < 7; i++)
			{
				if(operador1 == jerarquiaDeOperadores[i])
				{
					prioridad1 = i;
				}
				if(operador2 == jerarquiaDeOperadores[i])
				{
					prioridad2 = i;
				}
			}
			
			return (prioridad1 > prioridad2);
		}
};

int main()
{
	string infija = "4*5/(4+6)";
	string expresionPosfija=infija;
	int counter = 0;
	
	//Creacion de los objetos
	Expresion expresion(infija);
	Pila pila;
	
	if(expresion.estaBalanceada())
	{
		cout<<"La expresion esta balanceada!";
		cout<<endl;
		for(int i = 0; i < infija.length(); i++)
		{
			if((int)infija[i] >= 48 && (int)infija[i]<=57)
			{
				expresionPosfija[counter] = infija[i];
				counter++;
			}
			else
			{
				if(pila.estaVacia())
				{
					pila.push(infija[i]);
					pila.imprimir();
					cout<<endl;
				}
				else
				{
					if(expresion.esMayor(infija[i], pila.top()))
					{
						
					}
				}
			}
		}
		
	}
	else
	{
		cout<<"No esta balanceada";
	}
	//cout<<expresionPosfija;
	cout<<endl;
	
	//system("pause");
	
	return 0;
}