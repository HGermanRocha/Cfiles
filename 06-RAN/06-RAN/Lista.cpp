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
        void test()
        {
            primero = new Nodo(19);
            primero = new Nodo(61, primero);
            primero = new Nodo(99, primero);
            
            cout<<primero->enlaceNodo()->datoNodo();
        }
};

int main()
{
    TDA_Lista_Simple l;
    
    l.test();
    
    return 0;
}