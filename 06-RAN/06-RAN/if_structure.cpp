#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
    int a, b, c, d, e;
    
    cout<<"Ingrese 5 n"<<char(163)<<"meros:\n\n";
    cout<<"a = ";
    cin>>a;
    cout<<"\nb = ";
    cin>>b;
    cout<<"\nc = ";
    cin>>c;
    cout<<"\nd = ";
    cin>>d;
    cout<<"\ne = ";
    cin>>e;
    
    if(a > b)
    {
        if(b > c)
        {
             if(c > d)
             {
                  if(d > e)
                  {
                       cout<<endl<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;    
                  }
                  else
                  {
                      if(e > b)
                      {
                          cout<<endl<<" "<<a<<" "<<e<<" "<<b<<" "<<c<<" "<<d<<endl;
                      }
                      else if(e > c)
                      {
                          cout<<endl<<" "<<a<<" "<<b<<" "<<e<<" "<<c<<" "<<d<<endl;
                      }
                      else if(e > d)
                      {
                          cout<<endl<<a<<" "<<b<<" "<<c<<" "<<e<<" "<<d<<endl;
                      }
                  }
             }
             else
             {
                 if(c > e)
                 {
                      if(d > c)
                      {
                          cout<<endl<<a<<" "<<d<<" "<<b<<" "<<c<<" "<<e<<endl;
                      }
                      else if()
                      {
                           
                      }
                 }
             }
        }
    }

    getch();
    
    return 0;    
}
