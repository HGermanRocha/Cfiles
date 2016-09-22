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
    int n;
    int counter = 0;
    int diferencia = 0;
    cin >> n;
    int array[n];
    
    for(int i = 0;i < n;i++){
        cin >> array[i];
    }
    
    for(int i = 0; i < n; i++)
    {   
        for(int j = 0; j < n; j++)
        {
            if(abs(array[i]) == abs(array[j]) && (i != j))
            {
                diferencia = j - i;
                if(diferencia == )
                counter++;
            }
        }
    }
    
    cout<<endl<<counter;
    
    return 0;
}
