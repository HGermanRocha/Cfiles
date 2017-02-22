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
    int helper1, helper2;
    int counter = 0;
    int n;
    int k;
    int q;
    cin >> n >> k >> q;
    int array[n];
    for(int i = 0; i < n; i++){
       cin >> array[i];
    }
 
    for(int i = 0; i < k; i++)
    {
        helper1 = array[counter];
        array[0] = array[n-1];
        
        for(int j = 1; j < n-1; j++)
        {
            helper2 = array[counter+1];
            array[i] = helper1;
            counter++;
            helper1 = helper2;
        }
        counter = 0;
    }
    
    for(int i = 0; i < q; i++){
        int m;
        cin >> m;
        cout<<array[m]<<endl;
    }
    return 0;
}
