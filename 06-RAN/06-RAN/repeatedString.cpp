#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
    int i = 0, a = 0, j = 0;
    long int div, counter = 0,x = 0;
    string s;
    cin >> s;
    long int n;
    cin >> n;
    
    if(n < 20)
    {
        while(x < n)
        {
            while(i < s.length() && x < n)
            {
                if(s[i] == 'a')
                {
                    counter++;   
                }
                i++;
                x++;    
            }
            i = 0;
        }
    }
    else
    {
    	div = n/s.length();
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'a')
                a++;
        }
        //cout<<"a: "<<a<<"\t\tdiv:"<<div<<"\t\tn: "<<n<<"\t\tlen"<<s.length()<<endl;
        counter = a*div; 
    	//cout<<"Counter: "<<counter<<endl;
		if(n%s.length() != 0)    
		{
            //cout<<"test";
            
	        x = div * s.length();
            //cout<<"x"<<x<<endl;
	        while(x < n)
	        {
	            while(j < s.length() && x < n)
	            {
	                if(s[j] == 'a')
	                {
	                    counter++;   
	                }
	                j++;
	                x++;    
	            }
	            j = 0;
	        }
	    }
        
    }
    cout<<counter;
    
    return 0;
}