#include <iostream>

using namespace std;
//http://recursostic.educacion.es/descartes/web/materiales_didacticos/markov_mbgr/productodematrices.htm
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
			
			if(m >= this->m || n>= this->n)
			{
				return false;
			}
			
			return true;
		}
		int filas()
		{
			return m;
		}
		int columnas()
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
			Matriz m3(5, 5);
			
			for(int i = 0; i < x.filas(); i++)
			{
				for(int j = 0; j < x.columnas(); j++)
				{		
					m3.asignarElemento(i, j, (x.obtenerElemento(i, j) + y.obtenerElemento(i, j)));
				}
			}
			
			return m3;
		}
				
		Matriz multiplicar(Matriz x, Matriz y)
		{
			int multiplicar = 0, counter = 0, helper = 0;
			
			Matriz m3(x.filas(), y.columnas());
			
			for(int i = 0; i < x.filas(); i++)
			{
				while(helper < y.columnas())
				{
					for(int j = 0; j < y.filas(); j++)
					{
						multiplicar += x.obtenerElemento(i, j) * y.obtenerElemento(j, helper);		
						
					}
					m3.asignarElemento(i, helper, multiplicar);	
					multiplicar = 0;
					helper++;
				}
				helper = 0;
			}
			
			return m3;
		}
		
		Matriz transponer(Matriz x)
		{
			Matriz res(x.columnas(), x.filas());
			
			for(int i = 0; i < x.filas(); i++)
			{
				for(int j = 0; j < x.columnas(); j++)
				{
					res.asignarElemento(j, i, x.obtenerElemento(i, j));
				}
			}
			
			return res;
		}
};

//m = filas, n = columnas
//Abstraccion de objetos en clases

int main()
{
	int counter = 1, m, n;
	Matrices ms;
	
	/*cout<<"Por favor ingrese el tamaño de la matriz que desea crear: "<<endl;
	cout<<"m: ";
	cin>>m;
	cout<<"n: ";
	cin>>n;*/
	
	cout<<"MATRIZ 1\n\n";
	
	Matriz m1 = ms.creaMatriz(5, 5);
	m1.inicializarMatriz(4);
	
	m1.imprimir();
	
	cout<<"\n\nMATRIZ 2";
	
	Matriz m2 = ms.creaMatriz(5, 2);
	m2.inicializarMatriz(2);
	
	cout<<endl<<endl;
	
	m2.imprimir();
	
	cout<<endl<<endl;
	
/*	cout<<"\n\nSUMA\n\n";
	Matriz mSuma = ms.sumar(m1, m2);
	mSuma.imprimir();
*/	
	cout<<endl<<endl;
	
	cout<<"\n\nMULTIPLICACION\n\n";
	Matriz mMultiplicacion = ms.multiplicar(m1, m2);
	mMultiplicacion.imprimir();
	
	cout<<endl<<endl;
	
	cout<<"\n\nTRANSPUESTA\n\n";
	Matriz mTranspuesta = ms.transponer(m2);
	mTranspuesta.imprimir();
	
	
	
	//system("pause");
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
	
	//system("pause");
	
	return 0;
}