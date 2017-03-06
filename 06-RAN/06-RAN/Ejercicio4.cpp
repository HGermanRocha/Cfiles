#include <iostream>
#include <string>

using namespace std;

#define PI 3.1416

class Circulo
{
    private:
        double radio;
    
    public:
    
        void setRadio(double radio)
        {
            this->radio = radio;
        }
        double getArea()
        {
            return (radio * radio) * PI;       
        }
};

class Triangulo
{
    private:
        double base;
        double altura;
    public:    
        void setBase(double base)
        {
            this->base = base;
        }
        void setAltura(double altura)
        {
            this->altura = altura;
        }
        double getArea()
        {
            return (base*altura)/2;
        }
};

class Rectangulo
{
    private:
        double base;
        double altura;
    public:    
        void setBase(double base)
        {
            this->base = base;
        }
        void setAltura(double altura)
        {
            this->altura = altura;
        }
        double getArea()
        {
            return (base*altura);
        }
};

int main()
{
    double base, altura, radio;
    int opc;
    
    Triangulo triangulo;
    Circulo circulo;
    Rectangulo rectangulo;
    
    cout<<"Seleccione una figura geometrica: ";
    cout<<endl<<"1. Triangulo"<<endl;
    cout<<"2. Circulo"<<endl;
    cout<<"3. Rectangulo"<<endl;
    cout<<endl<<"Opc_";
    cin>>opc;
    
    switch(opc)
    {
        case 1:
            cout<<"Base: ";
            cin>>base;
            cout<<"Altura: ";
            cin>>altura;
            
            triangulo.setAltura(altura);
            triangulo.setBase(base);
            
            cout<<endl<<endl<<"Su area es: "<<triangulo.getArea();
            break;
        case 2:
            cout<<"Radio: ";
            cin>>radio;
            
            circulo.setRadio(radio);
            
            cout<<endl<<endl<<"Su area es: "<<circulo.getArea();
            break;
        case 3:
            cout<<"Base: ";
            cin>>base;
            cout<<"Altura: ";
            cin>>altura;
            
            rectangulo.setAltura(altura);
            rectangulo.setBase(base);
            
            cout<<endl<<endl<<"Su area es: "<<rectangulo.getArea();
            break;
        default:
            cout<<"Opcion invalida!";
            break;
    }
    
    
    return 0;
}