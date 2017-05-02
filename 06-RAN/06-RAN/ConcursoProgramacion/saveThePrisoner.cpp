#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int siguiente(int pos, int prisonerNum)
{
    return ((pos+1)%prisonerNum);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int testCases, prisonerNum, sweetNum, prisonerId, j;
    int counter = 0;
    cin >> testCases;
    
    for(int i = 0; i < testCases; i++) {
        cin>>prisonerNum>>sweetNum>>prisonerId;
        
       //cout<<(sweetNum%prisonerNum)<<endl;
        
        for(j = prisonerId; counter < (sweetNum%prisonerNum); j = siguiente(j, prisonerNum))
        {
            counter++;   
            
            if(counter == (sweetNum%prisonerNum) - 1)
            {
                j = siguiente(j, prisonerNum);
                cout<<j;
            }
            
            //cout<<"i: "<<j<<"counter: "<<counter<<endl;
        }
        
        //cout<<(sweetNum%prisonerNum)-(prisonerNum-prisonerId) - 1;
        //cout<<j - 1; 
        counter = 0;
        
        //cout<<(sweetNum%prisonerNum)+prisonerId-1;
        
        /*if(sweetNum)
        
        while(counter < sweetNum)
        {
            prisonerId = siguiente(prisonerId, prisonerNum);

            counter++;
        }

        cout<<prisonerId-1;
        counter=0;  */  


        
        /*for(int i = prisonerId; counter != sweetNum; i = siguiente(i, prisonerNum))
        {
            counter++;
            //cout<<"i: "<<i<<"counter: "<<counter<<endl;
            
            if(counter == sweetNum)
            {
                cout<<i+1<<endl;
            }
        }*/
        
       
        //cout<<siguiente(3,5);
        
        //cout << (sweetNum - ((sweetNum / prisonerNum) * prisonerNum))<< endl;
        //cout<<(prisionerId+1%prisonerNum);
        //cout << ((sweetNum - 1) % (prisonerNum - 1)) + prisonerId << endl;
        
    }
    
    
    return 0;
}
