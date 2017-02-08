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
    bool exists = false;
    int limit = 1;
    
    for(int i = 0; i < n; i++)
    {
        cin>>array[i];    
    }
    
    num[0] = array[0];
    frec[0] = 1;
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(num[j] == array[i])
            {
                frec[j]++;
                exists = true;
                break;
            }
        }
        if(!exists)
        {
            //cout<<array[i]<<" No existe"<<endl;
            num[i] = array[i];
            frec[i]++;
            //limit++;
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        cout<<num[i]<<" ";    
    }
    
    return 0;
}
