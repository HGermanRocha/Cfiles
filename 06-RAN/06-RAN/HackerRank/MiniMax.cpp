#include <iostream>

using namespace std;


int main()
{
    int counter = 0;
    long int helper1, helper2;
    long int min  = 0, max = 0;
    long int a;
    long int b;
    long int c;
    long int d;
    long int e;
    cin >> a >> b >> c >> d >> e;
    
    long int array[5] = {a, b, c , d, e};
    
    while(counter != 4)
    {
        for(int i = 0; i < 4; i++)
        {
            if(array[i] < array[i + 1])
            {   
                counter++;
            }
            else
            {
                helper1 = array[i];
                helper2 = array[i+1];
                
                array[i + 1] = helper1;
                array[i] = helper2;
                
                counter = 0;
                break;
            }
        }
    }
    
    for(int i = 0; i < 4; i++)
    {
        min += array[i];    
    }
    for(int i = 1; i < 5; i++)
    {
        max += array[i];    
    }
    
    cout<<min<<" "<<max;
    //goodman - love alone
    //glass towers - tonight
}
