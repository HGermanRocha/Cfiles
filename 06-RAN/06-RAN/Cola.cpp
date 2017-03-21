#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>

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
	        return frente == siguiente(siguiente(final));
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
	        
			Arreglo[frente] = NULL;
	        frente = siguiente(frente);
	        numElementos--;
	        return true;
	    }
	    TIPO_DE_DATO getNumElementos()
	    {
	        return numElementos;
	    }
	    
	    TIPO_DE_DATO getFrente()
	    {
	    	if(estaVacia())
	    	{
	    		return false;
	    	}
	    	return frente;
	    }
	    
	    bool esCapicua(int valor)
	    {
	    	double param = (double) valor;
	    	int length = ((int)log10(param)) + 1;
	    	int decimal; 
	    	int decimales[length];
	    	int helper = 1, counter = 0, counter2 = 0;
	    	
	    	for(int i = 0; i < length; i++)
	    	{
	    		param = param / 10;
	    		decimal = static_cast<int>(param*10)%10;
	    		
	    		decimales[i] = decimal;
	    	}
	    	
	    	for(int i = 0; i < length; i++)
	    	{
	    		counter += decimales[i] * helper;
	    		helper *= 10;
	    	}
	    	helper = helper/10;      //Esta linea es importante para posicionar helper donde debe de ser

	    	for(int i = 0; i < length; i++)
	    	{
	    		counter2 += decimales[i] * helper;
	    		helper = helper/10;
	    	}

	    	return counter == counter2;
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
	        cout<<Arreglo[final];
	        cout<<endl<<"Total de elementos: "<<numElementos;
	        cout<<endl<<"Frente: "<<frente;
	        cout<<endl<<"Final: "<<final;
	    }
};

int main()
{
	TDA_Cola c;
	
	c.crearCola();
	
	c.insertar(15);
	c.insertar(34);
	c.insertar(25);
	c.insertar(45);
	
	c.imprimir();
	
	cout<<endl<<endl;
	c.eliminar();
	c.imprimir();
	cout<<endl<<endl;
	cout<<c.getFrente();
	cout<<endl<<endl;
	c.insertar(79);
	c.imprimir();
	cout<<endl<<endl;
	
	if(c.esCapicua(121))
	{
		cout<<"Es capicua!";
	}
	else
	{
		cout<<"No es capicua";
	}
	return 0;
}