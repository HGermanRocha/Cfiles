#include <iostream>

using namespace std;

class Operacion
{
    private:
        int n[10];
        int fact[10], i;
    public:
        Operacion(){
            for(int i = 0; i < 10; i++)
            {
                n[i] = i;
            }
        }
        void setNumeros()
        {
            for(int i = 1; i < 10; i+=2)
            {
                for(fact[i] = n[i] - 1; fact[i] > 0; fact[i]--)
                {
                    n[i]= n[i] * fact[i];
                }
            }
        }
        void mostrar()
        {
            cout<<"Numero       Factorial"<<endl;
            for(int i = 1; i < 10; i+=2)
            {
                cout<<i<<"            "<<n[i]<<endl;
            }
        }

};

int main()
{
    Operacion factorial;
    
    factorial.setNumeros();
    
    factorial.mostrar();
    
    return 0;
}