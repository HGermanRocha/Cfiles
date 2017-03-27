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
            
        }
        void insertarUltimo(Dato entrada)
        {
            
        }
        Nodo* ultimo()
        {
            
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
            
        }
};

int main()
{
    TDA_Lista_Simple l;
    
    Nodo* primero = new Nodo(19);
    
    l.crearLista(primero);
    
    return 0;
}