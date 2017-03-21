#include <iostream>
#include <string>
#include <cmath>

using namespace std;


//Symbolab comprobacion: https://es.symbolab.com/solver/quadratic-equation-calculator/x%5E2-x-6%3D9?or=ex

class EcuacionCuadratica
{
    private:
        int a, b, c;
        double sol1, sol2, helper;
        string expresion;
    public:
        void setExpresion(string expresion)
        {
            this->expresion = expresion;
        }
        void definirValores(int a = 5, int b = 10, int c = 9)
        {
            this->a = a;
            this->b = b;
            this->c = c;
        }
        void solucion()
        {
            helper = (b*b) - (4*a*c);
            sol1 = (-b+(sqrt(helper)))/(2*a);
            sol2 = (-b-(sqrt(helper)))/(2*a);
            
            cout<<endl<<endl<<"x1 = "<<sol1<<"\t\tx2 = "<<sol2<<endl;
        }
};

int main()
{
    int a, b, c;
    string expresion;
    
    EcuacionCuadratica ecuacion1;
    
    cout<<"Ingresa una ecuacion cuadratica (ax^2+bx+c):"<<endl;
    cin>>expresion;
    
    ecuacion1.setExpresion(expresion);
    
    cout<<"Ingresa los valores de la ecuacion:"<<endl;
    cout<<"a: ";
    cin>>a;
    cout<<"b: ";
    cin>>b;
    cout<<"c: ";
    cin>>c;
    
    ecuacion1.definirValores(a,b,c);
    
    cout<<endl<<endl<<"El resultado de la ecuacion es: ";
    ecuacion1.solucion();
    
    return 0;
}