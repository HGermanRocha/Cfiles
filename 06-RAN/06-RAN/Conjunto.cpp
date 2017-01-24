#include <iostream>

using namespace std;

class Conjunto
{
	public:
	int array[50] = {0}, length, counter = 0;
	void insertar(int numero, int pos); 
	void obtenerLongitud();
	void imprimir();
};

void Conjunto::insertar(int numero, int pos)
{
	array[pos] = numero;
}
void Conjunto::imprimir()
{
	//system("cls");
	for(int i= counter- 1;i>= 0; i--)
	{
		cout<<array[i]<<endl;
	}
	counter = 0;
}
void Conjunto::obtenerLongitud()
{
	for(int i = 0; i < 50; i++)
	{
		if(array[i]!= 0)
		{
			counter++;
		}
		else
		{
			break;
		}
		
	}
}


int main()
{
	int num, p = 0;
	Conjunto Obj;
	
	while(true)
	{
		cout<<"Ingrese el numero que desea insertar: ";
		cin>>num;
		
		Obj.insertar(num, p);
		Obj.obtenerLongitud();
		Obj.imprimir();
		p++;
	}
	
	system("cls");
	return 0;
}