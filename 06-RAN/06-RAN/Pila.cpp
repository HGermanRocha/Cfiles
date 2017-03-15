#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define MAX 15

//---------------------------------------------------------------------------------------------
//*************CLASE PILA***************
//Esta clase maneja el comportamiento de una pila para resolver el problema

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

//--------------------------------------------------------------------------------
//*************CLASE EXPRESIONES**********************
//Sirve para analizar la expresion a evaluar, checar si esta balanceada y para realizar comparaciones de
//jerarquia entre operadores entrantes a la pila y operadores del top de la pila

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
			//*******NOTA IMPORTANTE********
			//Se le asigna el valor -1 por default a las variales 'prioridad1' y 'prioridad2' para abarcar el simbolo '('. Si se llega a comparar
			//entonces la prioridad del parentesis en nula y por lo tanto no debe de se un obstaculo para que un nuevo 
			//operador sea agregado a la pila.
			
			int prioridad1 = -1, prioridad2 = -1; 
			
			//Arreglos que ayudan a obtener el valor jerarquico de cada operador.
			//Segun la posicion de los operadores en el arreglo es el valor jerarquico que tiene cada uno.
			char jerarquiaDeOperadores[3] = {'+','*','^'}; 
			char jerarquiaDeOperadores2[2]={'-','/'};
			
			for(int i  = 0; i < 3; i++)
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
			
			for(int i = 0; i < 2; i++)
			{
				if(operador1 == jerarquiaDeOperadores2[i])
				{
					prioridad1 = i;
				}
				if(operador2 == jerarquiaDeOperadores2[i])
				{
					prioridad2 = i;
				}
			}
			
			return (prioridad1 > prioridad2);
		}
		bool esMenor(char operador1, char operador2)
		{
			int prioridad1 = 5, prioridad2 = 5;
			char jerarquiaDeOperadores[3] = {'+','*','^'};
			char jerarquiaDeOperadores2[2]={'-','/'};
			
			for(int i  = 0; i < 3; i++)
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
			
			for(int i = 0; i < 2; i++)
			{
				if(operador1 == jerarquiaDeOperadores2[i])
				{
					prioridad1 = i;
				}
				if(operador2 == jerarquiaDeOperadores2[i])
				{
					prioridad2 = i;
				}
			}
			
			return (prioridad1 < prioridad2);
		}
};

int main()
{
	string infija = "(4+(9-3))*(7+5)";
	string expresionPosfija=infija;
	int counter = 0, pos = 0;
	int resultado[50];
	
	//Creacion de los objetos
	Expresion expresion(infija);
	Pila pila;
	
	if(expresion.estaBalanceada())
	{
		//cout<<"La expresion esta balanceada!";
		
//----------------------------------------------------------------------------------------
//********************CONVERSION A POSFIJO******************************

		for(int i = 0; i < infija.length(); i++)
		{
			//Si el elemento de la epresion infija es un OPERANDO...
			if((int)infija[i] >= 48 && (int)infija[i]<=57)
			{
				expresionPosfija[counter] = infija[i];
				counter++;
			}
			else
			{
				//Si la pila esta vacia...
				if(pila.estaVacia())
				{
					pila.push(infija[i]);
				}
				else
				{
					//Si el operador que esta ingresando a la pila es un parentesis de apertura...
					if(infija[i] == '(')
					{
						pila.push(infija[i]);
					}
					//Si el operador que esta ingresando a la pila es un parentesis de cerradura...	
					else if(infija[i]== ')')
					{
						while(pila.top() != '(')
						{
							expresionPosfija[counter] = pila.top();
							pila.pop();	
							counter++;
						}
						pila.pop();					
					}
					else
					{
						//Si el operador que esta ingresando a la pila es mayor...
						if(expresion.esMayor(infija[i], pila.top()))
						{
							pila.push(infija[i]);
						}
						else
						{
							//Si el operador que esta ingresando en menor...
							while(expresion.esMenor(infija[i], pila.top()) && pila.top() != '(')
							{
								expresionPosfija[counter]=pila.top();
								pila.pop();
								counter++;
							}
								
						}
					}
				}
			}
		}
		//Se vacia la pila si despues de todo el procedimiento quedan elementos en la pila y se agregan a la expresion posfija.
		while(!pila.estaVacia())
		{
			expresionPosfija[counter] = pila.top();
			counter++;
			pila.pop();
		}
		
	}
	else
	{
		cout<<"No esta balanceada";
	}
	
	cout<<"Expresion Infija: "<<infija<<endl;
	cout<<"Expresion Posfija: ";
	for(int i = 0; i < counter; i++)
	{
		cout<<expresionPosfija[i];
	}
	
	cout<<endl;
//---------------------------------------------------------------------------
//*********CALCULO DE LA EXPRESION POSFIJA******************************
	for(int i = 0; i < counter; i++)
	{
		//Si el elemento de la expresion posfija es un OPERANDO...
		if((int)expresionPosfija[i] >= 48 && (int)expresionPosfija[i]<=57)
		{
			resultado[pos] = (int)expresionPosfija[i] - 48;		//Convertidor de caracter a entero
			pos++;
		}
		else 
		{
			//Si el elemento de la expresion posfija es un operador se realiza su respectiva operacion
			if(expresionPosfija[i] == '+')
			{
				resultado[pos - 2] += resultado[pos - 1];  
			}
			else if(expresionPosfija[i] == '-')
			{
				resultado[pos - 2] -= resultado[pos - 1];
			}
			else if(expresionPosfija[i] == '*')
			{
				resultado[pos - 2] *= resultado[pos - 1];
			}
			else if(expresionPosfija[i] == '/')
			{
				resultado[pos - 2] = resultado[pos - 2] / resultado[pos - 1];
			}
			pos -= 1;
		}
	}
	cout<<"Resultado: "<<resultado[0]<<endl;
	cout<<endl;

	return 0;
}
