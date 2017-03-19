#include<iostream>
#include <string>

using namespace std;

class Atleta
{
    private:
        string nombre;
        string nacionalidad;
        int numero;
        int tiempo;
    public:
        void setTiempo(int tiempo)
        {
            this->tiempo = tiempo;
        }
        void setNombre(string nombre)
        {
            this->nombre = nombre;
        }
        void setNacionalidad(string nacionalidad)
        {
            this->nacionalidad = nacionalidad;
        }
        void setNumero(int numero)
        {
            this->numero = numero;
        }
        string getNombre()
        {
            return nombre;
        }
        string getNacionalidad()
        {
            return nacionalidad;
        }
        int getNumero()
        {
            return numero;
        }
        int getTiempo()
        {
            return tiempo;
        }
};

int main()
{
    string nombre, nacionalidad;
    int numero, tiempo;
    
    Atleta atleta1;
    Atleta atleta2;
    
    cout<<"Nombre del atleta: ";
    cin>>nombre;
    cout<<"Nacionalidad: ";
    cin>>nacionalidad;
    cout<<"Numero de participante: ";
    cin>>numero;
    cout<<"Tiempo en que concluyo la carrera: ";
    cin>>tiempo;
    
    atleta1.setNombre(nombre);
    atleta1.setNacionalidad(nacionalidad);
    atleta1.setNumero(numero);
    atleta1.setTiempo(tiempo);
    
    cout<<endl<<endl;
    //system("cls");
    
    cout<<"Nombre del atleta: ";
    cin>>nombre;
    cout<<"Nacionalidad: ";
    cin>>nacionalidad;
    cout<<"Numero de participante: ";
    cin>>numero;
    cout<<"Tiempo en que concluyo la carrera: ";
    cin>>tiempo;
    
    atleta2.setNombre(nombre);
    atleta2.setNacionalidad(nacionalidad);
    atleta2.setNumero(numero);
    atleta2.setTiempo(tiempo);
    
    cout<<endl<<"El atleta mas veloz es:"<<endl;
    
    if(atleta1.getTiempo()<atleta2.getTiempo())
    {
        cout<<"Nombre: "<<atleta1.getNombre();
        cout<<endl<<"Nacionalidad: "<<atleta1.getNacionalidad();
        cout<<endl<<"Numero de participante: "<<atleta1.getNumero();
        cout<<endl<<"Tiempo: "<<atleta1.getTiempo();
    }
    else
    {
        cout<<"Nombre: "<<atleta2.getNombre();
        cout<<endl<<"Nacionalidad: "<<atleta2.getNacionalidad();
        cout<<endl<<"Numero de participante: "<<atleta2.getNumero();
        cout<<endl<<"Tiempo: "<<atleta2.getTiempo();
    }
    
    return 0;
}