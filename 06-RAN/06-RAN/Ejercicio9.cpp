#include <iostream>
#include <string>

using namespace std;

#define PI 3.14159

class Cilindro
{
    private:
        double radio;
        double altura;
        double volumen;
    public:
        void setRadio(double radio)
        {
            this->radio =radio;
        }
        void setAltura(double altura)
        {
            this->altura =altura;
        }
        double getArea()
        {
            return (PI*(radio*radio)) * altura;
        }
};

int main()
{
    double r, a;
    
    Cilindro cilindro;
    
    cout<<"*****CILINDRO*****"<<endl<<endl;
    cout<<"Radio: ";
    cin>>r;
    cout<<"Altura: ";
    cin>>a;
    
    cilindro.setRadio(r);
    cilindro.setAltura(a);
    
    cout<<"El area es: "<<cilindro.getArea()<<endl;
    
    return 0;
}