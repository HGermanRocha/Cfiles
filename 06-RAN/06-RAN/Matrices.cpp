#include <iostream>

using namespace std;

class Matriz
{
	private:
		int matriz[50][50];
		int m, n;
		
	public:
		Matriz(int m = 50, int n = 50)
		{
			this->m = m;
			this->n = n;
		}
		
		void asignarElemento(int m, int n, int valor)
		{
		
			matriz[m][n] = valor; 
		
		}
		int obtenerElemento(int m, int n)
		{
		
			return matriz[m][n];
		
		}
		bool esValido(int m, int n)
		{
			if(m >= this->m || int n>= this->n)
			{
				return false;
			}
			
			return true;
		}
			
	
};

class Matrices
{
	public:
		Matriz creaMatriz(int m, int n)
		{
			Matriz a(m, n);
			
			return a;	
		}	
};

int main()
{
	int counter = 1, m, n;
	Matrices ms;
	
	cout<<"Por favor ingrese el tamaño de la matriz que desea crear: "<<endl;
	cout<<"m: ";
	cin>>m;
	cout<<"n: ";
	cin>>n;
	
	Matriz m1 = ms.creaMatriz(m, n);
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			m1.asignarElemento(i, j, counter);
			cout<<m1.obtenerElemento(i, j)<<"  ";		
			counter++;  //counter puede ser cambiado por el valor que escoga el usuario
		}
		
		cout<<endl;
	}
	
	cout<<"Ingrese la posicion de la matriz de la que quiere obtener un elemento: ";
	cout<<endl<<"m: ";
	cin>>m;
	cout<<"n: ";
	cin>>n;
	
	cout<<m1.obtenerElemento(m, n);
	
	system("pause");
	
	return 0;
}