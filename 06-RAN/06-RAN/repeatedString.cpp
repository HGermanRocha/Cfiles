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
    int counter = 0, x = 0, i = 0;
    string s;
    cin >> s;
    long n;
    cin >> n;
    
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
    
    cout<<counter;
    
    return 0;
}
