#include <iostream>
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
                      if(d > b)
                      {
                          cout<<endl<<a<<" "<<d<<" "<<b<<" "<<c<<" "<<e<<endl;
                      }
                      else if(b > d)
                      {
                          cout<<endl<<a<<" "<<b<<" "<<d<<" "<<c<<" "<<e<<endl; 
                      }
                 }
                 else
                 {
                     cout<<endl<<a<<" "<<b<<" "<<d<<" "<<e<<" "<<c<<endl; 
                 }
             }
        }
        else
        {
            if(b > d)
            {
                 if(d > e)
                 {
                     cout<<endl<<a<<" "<<c<<" "<<b<<" "<<d<<" "<<e<<endl; 
                 }
                 else if(e > d)
                 {
                     cout<<endl<<a<<" "<<c<<" "<<b<<" "<<e<<" "<<d<<endl; 
                 }
            }
            else if(e > b)
            {
                if(b > d)
                {
                     cout<<endl<<a<<" "<<c<<" "<<e<<" "<<b<<" "<<d<<endl;
                }
            }
            else
            {
                if(e > d)
                {
                    cout<<endl<<a<<" "<<c<<" "<<e<<" "<<d<<" "<<b<<endl; 
                }
            }
        }
    }
    if(b > a)
    {
        if(a > c)
        {
             if(c > d)
             {
                  if(d > e)
                  {
                       cout<<endl<<" "<<b<<" "<<a<<" "<<c<<" "<<d<<" "<<e<<endl;    
                  }
                  else
                  {
                      if(e > a)
                      {
                          cout<<endl<<" "<<b<<" "<<e<<" "<<a<<" "<<c<<" "<<d<<endl;
                      }
                      else if(e > c)
                      {
                          cout<<endl<<" "<<b<<" "<<a<<" "<<e<<" "<<c<<" "<<d<<endl;
                      }
                      else if(e > d)
                      {
                          cout<<endl<<b<<" "<<a<<" "<<c<<" "<<e<<" "<<d<<endl;
                      }
                  }
             }
             else
             {
                 if(c > e)
                 {
                      if(d > a)
                      {
                          cout<<endl<<b<<" "<<d<<" "<<a<<" "<<c<<" "<<e<<endl;
                      }
                      else if(a > d)
                      {
                          cout<<endl<<b<<" "<<a<<" "<<d<<" "<<c<<" "<<e<<endl; 
                      }
                 }
                 else
                 {
                     cout<<endl<<b<<" "<<a<<" "<<d<<" "<<e<<" "<<c<<endl; 
                 }
             }
        }
        else
        {
            if(a > d)
            {
                 if(d > e)
                 {
                     cout<<endl<<b<<" "<<c<<" "<<a<<" "<<d<<" "<<e<<endl; 
                 }
                 else if(e > d)
                 {
                     cout<<endl<<b<<" "<<c<<" "<<a<<" "<<e<<" "<<d<<endl; 
                 }
            }
            else if(e > a)
            {
                if(a > d)
                {
                     cout<<endl<<b<<" "<<c<<" "<<e<<" "<<a<<" "<<d<<endl;
                }
            }
            else
            {
                if(e > d)
                {
                    cout<<endl<<b<<" "<<c<<" "<<e<<" "<<d<<" "<<a<<endl; 
                }
            }
        }
    }
    if(c > a)
    {
        if(a > b)
        {
             if(b > d)
             {
                  if(d > e)
                  {
                       cout<<endl<<" "<<c<<" "<<a<<" "<<b<<" "<<d<<" "<<e<<endl;    
                  }
                  else
                  {
                      if(e > a)
                      {
                          cout<<endl<<" "<<c<<" "<<e<<" "<<a<<" "<<b<<" "<<d<<endl;
                      }
                      else if(e > b)
                      {
                          cout<<endl<<" "<<c<<" "<<a<<" "<<e<<" "<<b<<" "<<d<<endl;
                      }
                      else if(e > d)
                      {
                          cout<<endl<<c<<" "<<a<<" "<<b<<" "<<e<<" "<<d<<endl;
                      }
                  }
             }
             else
             {
                 if(b > e)
                 {
                      if(d > a)
                      {
                          cout<<endl<<c<<" "<<d<<" "<<a<<" "<<b<<" "<<e<<endl;
                      }
                      else if(a > d)
                      {
                          cout<<endl<<c<<" "<<a<<" "<<d<<" "<<b<<" "<<e<<endl; 
                      }
                 }
                 else
                 {
                     cout<<endl<<c<<" "<<a<<" "<<d<<" "<<e<<" "<<b<<endl; 
                 }
             }
        }
        else
        {
            if(a > d)
            {
                 if(d > e)
                 {
                     cout<<endl<<c<<" "<<b<<" "<<a<<" "<<d<<" "<<e<<endl; 
                 }
                 else if(e > d)
                 {
                     cout<<endl<<c<<" "<<b<<" "<<a<<" "<<e<<" "<<d<<endl; 
                 }
            }
            else if(e > a)
            {
                if(a > d)
                {
                     cout<<endl<<c<<" "<<b<<" "<<e<<" "<<a<<" "<<d<<endl;
                }
            }
            else
            {
                if(e > d)
                {
                    cout<<endl<<c<<" "<<b<<" "<<e<<" "<<d<<" "<<a<<endl; 
                }
            }
        }
    }
   if(d > a)
    {
        if(a > b)
        {
             if(b > c)
             {
                  if(c > e)
                  {
                       cout<<endl<<" "<<d<<" "<<a<<" "<<b<<" "<<c<<" "<<e<<endl;    
                  }
                  else
                  {
                      if(e > a)
                      {
                          cout<<endl<<" "<<d<<" "<<e<<" "<<a<<" "<<b<<" "<<c<<endl;
                      }
                      else if(e > b)
                      {
                          cout<<endl<<" "<<d<<" "<<a<<" "<<e<<" "<<b<<" "<<c<<endl;
                      }
                      else if(e > c)
                      {
                          cout<<endl<<d<<" "<<a<<" "<<b<<" "<<e<<" "<<c<<endl;
                      }
                  }
             }
             else
             {
                 if(b > e)
                 {
                      if(c > a)
                      {
                          cout<<endl<<d<<" "<<c<<" "<<a<<" "<<b<<" "<<e<<endl;
                      }
                      else if(a > c)
                      {
                          cout<<endl<<d<<" "<<a<<" "<<c<<" "<<b<<" "<<e<<endl; 
                      }
                 }
                 else
                 {
                     cout<<endl<<d<<" "<<a<<" "<<c<<" "<<e<<" "<<b<<endl; 
                 }
             }
        }
        else
        {
            if(a > c)
            {
                 if(c > e)
                 {
                     cout<<endl<<d<<" "<<b<<" "<<a<<" "<<c<<" "<<e<<endl; 
                 }
                 else if(e > c)
                 {
                     cout<<endl<<d<<" "<<b<<" "<<a<<" "<<e<<" "<<c<<endl; 
                 }
            }
            else if(e > a)
            {
                if(a > c)
                {
                     cout<<endl<<d<<" "<<b<<" "<<e<<" "<<a<<" "<<c<<endl;
                }
            }
            else
            {
                if(e > c)
                {
                    cout<<endl<<d<<" "<<b<<" "<<e<<" "<<c<<" "<<a<<endl; 
                }
            }
        }
    }
    if(e > a)
    {
        if(a > b)
        {
             if(b > c)
             {
                  if(c > d)
                  {
                       cout<<endl<<" "<<e<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;    
                  }
                  else
                  {
                      if(d > a)
                      {
                          cout<<endl<<" "<<e<<" "<<d<<" "<<a<<" "<<b<<" "<<c<<endl;
                      }
                      else if(d > b)
                      {
                          cout<<endl<<" "<<e<<" "<<a<<" "<<d<<" "<<b<<" "<<c<<endl;
                      }
                      else if(d > c)
                      {
                          cout<<endl<<e<<" "<<a<<" "<<b<<" "<<d<<" "<<c<<endl;
                      }
                  }
             }
             else
             {
                 if(b > d)
                 {
                      if(c > a)
                      {
                          cout<<endl<<e<<" "<<c<<" "<<a<<" "<<b<<" "<<d<<endl;
                      }
                      else if(a > c)
                      {
                          cout<<endl<<e<<" "<<a<<" "<<c<<" "<<b<<" "<<d<<endl; 
                      }
                 }
                 else
                 {
                     cout<<endl<<e<<" "<<a<<" "<<c<<" "<<d<<" "<<b<<endl; 
                 }
             }
        }
        else
        {
            if(a > c)
            {
                 if(c > d)
                 {
                     cout<<endl<<e<<" "<<b<<" "<<a<<" "<<c<<" "<<d<<endl; 
                 }
                 else if(d > c)
                 {
                     cout<<endl<<e<<" "<<b<<" "<<a<<" "<<d<<" "<<c<<endl; 
                 }
            }
            else if(d > a)
            {
                if(a > c)
                {
                     cout<<endl<<e<<" "<<b<<" "<<d<<" "<<a<<" "<<c<<endl;
                }
            }
            else
            {
                if(d > c)
                {
                    cout<<endl<<e<<" "<<b<<" "<<d<<" "<<c<<" "<<a<<endl; 
                }
            }
        }
    }
   
		
	getch();
	
	return 0;
}
