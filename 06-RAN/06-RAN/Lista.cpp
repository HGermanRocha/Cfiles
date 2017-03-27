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
        /*void test()
        {
            primero = new Nodo(19);
            primero = new Nodo(61, primero);
            primero = new Nodo(99, primero);
            
            cout<<primero->enlaceNodo()->datoNodo();
        }*/
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
            
            while(p->enlaceNodo() != NULL)
            {
                p = p->enlaceNodo();
            }
            
            return p;
        }
        void insertarLista(Nodo* anterior, Dato entrada)
        {
            
        }
        Nodo* buscarLista(Dato destino)
        {
            
        }
        Nodo* buscarPosicion(int posicion)
        {
            
        }
        void eliminar(Dato entrada)
        {
            
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
    
    l.crearLista(primero);
    
    for(int i = 0; i < 3; i++)
    {
        cout<<endl<<"Valor: ";
        cin>>valor;
        
        l.insertarCabezaLista(valor);
        
    }
    
    l.insertarUltimo(29);
    
    l.mostrar();
    
    return 0;
}