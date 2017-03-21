#include <iostream>
#include <string>

#include "Cola.h"
#include "Pila.h"

using namespace std;

const int limite = 6;

class Palabra
{
	private:
		string palabra;
		TDA_Cola c;
		TDA_Pila p;
	public:
		void setPalabra(string palabra)
		{
			this->palabra = palabra;
		}
		bool esPalindrome()
		{
			//Es importante inicializar los valores de las estructuras
			p.crearPila();
			c.crearCola();
			
			for(int i = 0; i < limite; i++)
			{
				p.push(palabra[i]);
				c.insertar(palabra[i]);
			}
			for(int i = 0; i < limite; i++)
			{
				if(p.top() != c.getFrente())
				{
					return false;
				}
				p.pop();
				c.eliminar();
			}
			
			return true;
		}
};

int main()
{
	string word;
	
	Palabra palabra;
	
	cout<<"Ingresa una palabra: ";
	cin>>word;
	
	palabra.setPalabra(word);
	
	if(palabra.esPalindrome())
	{
		cout<<endl<<endl<<"Es palindrome!";
	}
	else
	{
		cout<<endl<<endl<<"NO es plindrome!";
	}
	
	return 0;
}