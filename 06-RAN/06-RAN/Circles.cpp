#include <iostream>
#include <string>

using namespace std;

class Circle
{
    private:
        double radius;
        string color;
        
    public:
        
        Circle(double r = 1.0, string c = "red") {
            radius = r;
            color = c;
        }
        
        double getRadius()
        {
            return radius;
        }
        
        string getColor()
        {
            return color;
        }
        
        double getArea()
        {
            return (radius*radius)/3.14159;
        }     
        double setRadius(double radius)
        {
            this->radius = radius;
            return radius;
        }         
};

int main()
{
    string c, res;
    int opc;
    double radio;
    
    cout<<"Eliga un color para el circulo #2"<<endl;
    cin>>c;
    
    cout<<endl<<endl;
    // Construct 3 instances of the class Circle: c1, c2, and c3
    Circle c1(1.2, "red");
    Circle c2(3.14, c);
    Circle c3;
    
    cout<<c1.getColor()<<"\t\t"<<c1.getRadius()<<"\t\t"<<c1.getArea();
    cout<<endl<<c2.getColor()<<"\t\t"<<c2.getRadius()<<"\t\t"<<c2.getArea();
    cout<<endl<<c3.getColor()<<"\t\t"<<c3.getRadius()<<"\t\t"<<c3.getArea()<<endl;
    
    cout<<"Desea cambiar el radio de un circulo?"<<endl;
    cin>>res;
    
    if(res == "si")
    {
        cout<<"Ingrese el circulo que desea cambiar: ";
        cin>>opc;
        
        cout<<endl<<"Ingrese el nuevo radio: ";
        cin>>radio;
        
        switch(opc)
        {
           case 1:
                c1.setRadius(radio);
                break;
           case 2:
                c2.setRadius(radio);
                break;
           case 3:
                c3.setRadius(radio);
                break;
           default:
                cout<<"Opcion invalida!";
                break;
        }
    }
    
    c3.radius = 5;
    
    cout<<c1.getColor()<<"\t\t"<<c1.getRadius()<<"\t\t"<<c1.getArea();
    cout<<endl<<c2.getColor()<<"\t\t"<<c2.getRadius()<<"\t\t"<<c2.getArea();
    cout<<endl<<c3.getColor()<<"\t\t"<<c3.getRadius()<<"\t\t"<<c3.getArea()<<endl;
    
    system("pause");
    
    return 0;
}

