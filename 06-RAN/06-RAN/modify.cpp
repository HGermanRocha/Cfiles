#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int a, b;
    long squaredNumber;
    string square;
    int kaprekar = 0;
    bool isThereANumber = false;
    int size;
    cin>>a>>b;
    
    for(int i = 77778; i <=b; i++)
    {
        squaredNumber = i*i;
        size = ceil(square.length()/2);
        cout<<"squaredNumber: "<<squaredNumber<<endl;
        //cout<<endl<<endl<<size<<square.length()- (size)<<endl<<endl;
        
        square = to_string(squaredNumber);
        //cout<<endl<<square.length()<<endl;
        if(square.length() > 1)
        {
            char leftSide[size];
            char rightSide[square.length()- (size)];
            int helper = 0;
            
            for(int j = 0; j < size; j++)    
            {
                leftSide[j] = square[j];  
                //cout<<leftSide[j]<<" "<<endl;
            }
            for(int k = size; k < square.length(); k++)
            {
                rightSide[helper] = square[k];
                //cout<<endl<<rightSide[helper]<<" "<<endl;   
                helper++;
            }
            
            kaprekar = atoi(leftSide) + atoi(rightSide);
            
            if(kaprekar == i)
            {
                cout<<i<<" "; 
                isThereANumber = true;
            }
            cout<<"i: "<<i<<" "<<atoi(leftSide)<<endl;
        }
        else
        {
            if(i == 1)
            {
                cout<<i<<" ";
                isThereANumber = true;
            }
        }
    }
    
    if(!isThereANumber)
    {
        cout<<"INVALID RANGE";
    }
    
    return 0;
}
