#include <iostream>
#include <string>

using namespace std;

typedef int Dato;

class Nodo
{
    private:
        Dato dato;
        Nodo* enlace;
    public:
        Nodo(Dato t)
        {
            dato = t;
            enlace = NULL;
        }
        Nodo(Dato t, Nodo* n)
        {
            dato = t;
            enlace = n;
        }
        Dato datoNodo()
        {
            return dato;
        }
        Nodo* enlaceNodo()
        {
            return enlace;
        }
        void ponerEnlace (Nodo* sgte)
        {
            enlace = sgte;
        }
};

class TDA_Lista_Simple
{
    private:
        Nodo* primero;
    public:
    
        void crearLista(Nodo* primero)
        {
            this->primero = primero;
        }
        void insertarCabezaLista(Dato entrada)
        {
            Nodo* nuevo;
            
            nuevo = new Nodo(entrada);
            
            nuevo->ponerEnlace(primero);
            
            primero = nuevo;
        }
        void insertarUltimo(Dato entrada)
        {
            Nodo* ultimo = this->ultimo();  //->this->ultimo() llama a otra funcion dentro de la clase.
            ultimo->ponerEnlace(new Nodo(entrada));
        }
        Nodo* ultimo()
        {
            Nodo* p;
         
            p = primero;
         
            if(p == NULL)
            {
                throw"ERROR: Lista vacia!";
            }
            
            while(p->enlaceNodo() != NULL)
            {
                p = p->enlaceNodo();
            }
            
            return p;
        }
        void insertarLista(Nodo* anterior, Dato entrada)
        {
            Nodo* nuevo;
            
            nuevo = new Nodo(entrada);
            
            nuevo->ponerEnlace(anterior->enlaceNodo());
            anterior->ponerEnlace(nuevo);
        }
        Nodo* buscarLista(Dato destino)
        {
            Nodo* indice;
            
            for(indice = primero; indice != NULL; indice = indice->enlaceNodo())
            {
                if(destino == indice->datoNodo())
                {
                    return indice;
                }
                
            }
            
            return NULL;
        }
        Nodo* buscarPosicion(int posicion)
        {
            Nodo* indice;
            int i;
            
            if(posicion <=0)
            {
                return NULL;
            }
            
            indice = primero;
            
            for(int i = 1; (i < posicion) && (indice != NULL); i++)
            {
                indice = indice->enlaceNodo();    
            }
            
            return indice;
        }
        void eliminar(Dato entrada)
        {
            Nodo *actual = primero, *anterior = NULL;
            bool encontrado  = false;
            
            while((actual != NULL) && (!encontrado))
            {
                encontrado = (actual->datoNodo() == entrada);
                
                if(!encontrado)
                {
                    anterior = actual;
                    actual = actual->enlaceNodo();
                }
                
            }
            
            if(actual != NULL)
            {
                if(actual == primero)
                {
                    primero = actual->enlaceNodo();
                }
                else
                {
                    anterior->ponerEnlace(actual->enlaceNodo());
                }
                delete actual;
            }
            
        }
        void mostrar()
        {
            Nodo* actual = primero;
            
            while(actual != NULL)
            {
                cout<<actual->datoNodo()<<", ";
                
                actual = actual->enlaceNodo();
            }
            
        }
};

int main()
{
    Dato valor;
    TDA_Lista_Simple l;
    
    cout<<"Inicializar lista con el valor: ";
    cin>>valor;
    
    Nodo* primero = new Nodo(valor);
    Nodo* n;
    
    l.crearLista(primero);
    
    for(int i = 0; i < 3; i++)
    {
        cout<<endl<<"Valor: ";
        cin>>valor;
        
        l.insertarCabezaLista(valor);
        
    }
    
    l.insertarUltimo(29);
    
    n = l.buscarLista(19);
    
    if(n == NULL)
    {
    	cout<<"El valor no se encuentra en la lista!"<<endl;
	}
    else
    {
    	l.insertarLista(n, 999);
	}
    
    l.insertarLista(l.buscarPosicion(2), 777);
    
    l.eliminar(29);
    
    l.mostrar();
    
    return 0;
}