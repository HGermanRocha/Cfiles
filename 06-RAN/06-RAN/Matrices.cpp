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
		
		void inicializarMatriz(int valor)
		{
			for(int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					matriz[i][j] = valor;
				}
			}
		}
		void asignarElemento(int m, int n, int valor)
		{
		
			matriz[m][n] = valor; 
		
		}
		int obtenerElemento(int m, int n)
		{
		
			return matriz[m][n];
		
		}
		bool esPosicionValida(int m, int n)
		{
			//POSICION VALIDA: indica si la posicion que se busca es válida
			if(m >= this->m || n>= this->n)
			{
				return false;
			}
			
			return true;
		}
		int tamanioEnM()
		{
			return m;
		}
		int tamanioEnN()
		{
			return n;
		}
		void imprimir()
		{
		
			for(int i = 0; i < m; i++)
			{
				for(int j = 0; j < n; j++)
				{
					cout<<matriz[i][j]<<" ";
				}
				cout<<endl;
			}	
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
		
		Matriz sumar(Matriz x, Matriz y)
		{
			int suma;
			
			Matriz m3(5, 5);
			
			for(int i = 0; i < x.tamanioEnM(); i++)
			{
				for(int j = 0; j < x.tamanioEnN(); j++)
				{
					suma = x.obtenerElemento(i, j) + y.obtenerElemento(i, j);		
					m3.asignarElemento(i, j, suma);
				}
			}
			
			return m3;
		}
		
		Matriz multiplicar(Matriz x, Matriz )
};

int main()
{
	int counter = 1, m, n;
	Matrices ms;
	
	/*cout<<"Por favor ingrese el tamaño de la matriz que desea crear: "<<endl;
	cout<<"m: ";
	cin>>m;
	cout<<"n: ";
	cin>>n;*/
	
	Matriz m1 = ms.creaMatriz(5, 5);
	m1.inicializarMatriz(50);
	
	Matriz m2 = ms.creaMatriz(5, 5);
	m2.inicializarMatriz(14);
	
	
	Matriz mSuma = ms.sumar(m1, m2);
	mSuma.imprimir();
	
	
	
	
	
	
	
	system("pause");
	/*for(int i = 0; i < m; i++)
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
	
	if(m1.esPosicionValida(m, n))
		cout<<m1.obtenerElemento(m, n);
	else
		cout<<"Posicion invalida!"<<endl;
	*/
	
	system("pause");
	
	return 0;
}