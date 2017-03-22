#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Encriptador
{
	private:
		ostringstream line;
		string texto;
	public:
		void setLine(string s)
		{
			line<<s<<endl;
		}
		string getTexto()
		{
			return texto;
		}
		void germanCipher()
		{
			texto = line.str();
			
			for(int i = 0; i < line.str().length();i++)
			{
				if(texto[i]!= '\n')
				{
					texto[i] = (char)((int)texto[i] + 1); //Define el valor de cada caracter sumando 1 a su valor	
				}
			}
		}
		void encriptarArchivo()
		{
			ofstream outfile("prueba.txt");
			outfile<<texto;
			
			outfile.close();
		}
};

class Desencriptador
{
	private:
		ostringstream line;
		string texto;
	public:
		void setTexto(string s)
		{
			line<<s<<endl;
		}
		string getTexto()
		{
			return texto;
		}
		void descifrarMensaje()
		{
			texto = line.str();
			
			for(int i = 0; i < line.str().length();i++)
			{
				if(texto[i] != '\n')
				{
					texto[i] = (char)((int)texto[i] - 1); //Define el valor de cada caracter sumando 1 a su valor	
				}
			}
		}
		void descifrarArchivo()
		{
			ofstream outfile("descifrado.txt");
			outfile<<texto;
			
			outfile.close();
		}
};

int main()
{
	string line;
	Encriptador encriptar;
	Desencriptador desencriptar;
	
	ifstream myfile ("test.txt");
	
	if(myfile.is_open())
	{
		while(getline(myfile, line))
		{
			encriptar.setLine(line);  //se define la linea a encriptar			
		}
		
		encriptar.germanCipher();  //Aquí se encripta el texto ingresada
		
		desencriptar.setTexto(encriptar.getTexto()); //desencriptar recibe linea por linea la encriptacion que se está realizando
		
		encriptar.encriptarArchivo();
		
		desencriptar.descifrarMensaje();
		cout<<endl<<"Mensaje Desencriptado:"<<endl<<desencriptar.getTexto()<<endl;
		desencriptar.descifrarArchivo();
		
		myfile.close();
	}
	else
	{
		cout<<"Unable to open file";
	}
	//http://forums.devarticles.com/c-c-help-52/c-opening-all-txt-files-in-a-folder-one-by-150745.html
	//https://www.hackerrank.com/challenges/insertionsort2?h_r=next-challenge&h_v=zen HACKERRANK PROBLEM
	//https://www.hackerrank.com/challenges/red-john-is-back Dynamic Programming
	return 0;
}