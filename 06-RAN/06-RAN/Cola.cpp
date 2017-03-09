#include <iostream>
#include <string>

using namespace std;

typedef int TIPO_DE_DATO;

const int MAXTAMQ = 5;

class TDA_Cola 
{
	private:
		int frente;
		int final;
		int numElementos;
		TIPO_DE_DATO Arreglo[MAXTAMQ];	
	public:
	    int siguiente(int parametro)
	    {
	        return (parametro + 1) % MAXTAMQ;
	    }
	    void crearCola()
	    {
	        frente = 0;
	        final = MAXTAMQ - 1;
	        numElementos = 0;
	    }
	    bool estaVacia()
	    {
	        return frente==siguiente(final);
	    }
	    bool estaLlena()
	    {
	        return frente == siguitente(siguiente(final));
	    }
	    bool insertar(TIPO_DE_DATO x)
	    {
	        if(estaLlena())
	        {
	            return false;
	        }
	        
	        final = siguiente(final);
	        Arreglo[final] = x;
	        numElementos++;
	        return true;
	    }
	    bool eliminar()
	    {
	        if(estaVacia())
	        {
	            return false;
	        }
	        
	        frente = siguiente(frente);
	        numElementos--;
	        return true;
	    }
	    TIPO_DE_DATO getNumElementos()
	    {
	        return numElementos;
	    }
	    
	    void imprimir()
	    {
	        if(estaVacia())
	        {
	            return;
	        }
	        
	        for(int i = frente; i != final; i = siguiente(i))
	        {
	            cout<<Arreglo[i]<<" ";
	        }
	        cout<<endl<<endl<<"Total de elementos: "<<numElementos;
	        cout<<endl<<"Frente: "<<frente;
	        cout<<endl<<"Final: "<<final;
	    }
};

int main()
{
	
	
	return 0;
}