#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    int array[n];
    int frec[n] = {0};
    int num[n];
    int mayor = 0;
    bool exists = false;
    int limit = 1;
    
    for(int i = 0; i < n; i++)
    {
        cin>>array[i]; 
       //cout<<array[i]<<" ";
    }
    //cout<<endl;
    num[0] = array[0];
    frec[0] = 1;
    
    for(int i = 1; i < n; i++)
    {
        //cout<<"i:"<<i<<endl;
        //cout<<"limit:"<<limit<<endl;
        for(int j = 0; j < limit; j++)
        {
            //cout<<num[j]<<endl;
            if(num[j] == array[i])
            {
                frec[j]++;
                exists = true;
                break;
            }
        }
        //cout<<endl<<endl;
        if(!exists)
        {
            //cout<<array[i]<<" No existe"<<endl;
            num[limit] = array[i];
            frec[limit]++;
            limit++;
        }
        exists = false;
    }
    
    for(int i = 0; i < n; i++)
    {
        if(frec[i] > mayor)
        {
            mayor = frec[i];    
        }
    }
    cout<<mayor;
   
    return 0;
}
