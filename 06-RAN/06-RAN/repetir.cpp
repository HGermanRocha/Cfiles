#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    int counter = 1;
    bool seRepite = false;
    
    cout<<"Escriba la cantidad de numeros a ingresar: ";
    cin>>n;
    
    int numeros[n];
    int repetidos[n];
    
    cout<<endl<<"Numero 1: ";
    cin>>numeros[0];
    repetidos[0] = numeros[0];
    
    for(int i = 1; i < n; i++)
    {
        cout<<endl<<"Numero "<<i + 1<<": ";
        cin>>numeros[i];
        
        for(int j = 0; j < counter; j++)
        {
            if(numeros[i] == repetidos[j])
            {
                seRepite = true; 
            }
        }
        
        if(!seRepite)
        {
            repetidos[counter] = numeros[i];
            counter++;
        }
    }
    
    cout<<endl<<endl;
    
    for(int i = 0; i < counter; i++)
    {
        cout<<repetidos[i]<<endl;
    }
                                                                        
    
    system("Pause");
 
    return 0; 
}
