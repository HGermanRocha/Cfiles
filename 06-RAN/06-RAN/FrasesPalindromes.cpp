#include <iostream>
#include <fstream>
#include <string>

#include "Cola.h"
#include "Pila.h"

using namespace std;

class Palabra
{
	private:
		string frase;
		TDA_Cola c;
		TDA_Pila p;
	public:
		void setFrase(string frase)
		{
			this->frase = frase;
		}
		bool esPalindrome()
		{
			p.crearPila();
			c.crearCola();
			
			for(int i = 0; i < frase.length(); i++)
			{
				p.push(frase[i]);
				c.insertar(frase[i]);
			}
			for(int i = 0; i < frase.length(); i++)
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
	string line;
	int counter = 0;
	ifstream myfile ("ejemplo.txt");
	Palabra palabra;
	
	if(myfile.is_open())
	{
		while(getline(myfile, line))
		{
			palabra.setFrase(line);
			
			if(palabra.esPalindrome())
			{
				counter++;
			}
		}
		
		cout<<"Frases palindromas en el archivo 'ejemplo.txt': "<<counter<<endl;
		
		myfile.close();
	}
	else
	{
		cout<<"Unable to open file";
	}
	
	return 0;
}