#include <iostream>
#include <string>

using namespace std;

#define MAX 5

class Alumno
{
    private:
        int counter;
        string nombre;
        float materias[MAX];
        float promedio;
        bool aprobado;
    public:
        Alumno(){
            counter = 0;
            aprobado = false;
        }
        bool boletaEstaLlena()
        {
            return (counter==MAX);
        }
        void setCalificacion(float calificacion)
        {
            if(boletaEstaLlena())
            {
                return;
            }
            
            materias[counter] = calificacion;
            counter++;
        }
        float getPromedio()
        {
            promedio = 0;

            for(int i = 0; i < MAX; i++)
            {
                promedio += materias[i];
            }
            
            promedio = promedio / MAX;
            
            if(promedio > 7)
            {
                aprobado = true;
            }
            
            return promedio;
        }
        bool estaAprobado()
        {
            return (aprobado == true);
        }
        void setNombre(string nombre)
        {
            this->nombre =nombre;
        }
        string getNombre()
        {
            return nombre;
        }
};

int main()
{
    string nombre;
    float cal;
    Alumno alumno;
    
    cout<<"Nombre: ";
    cin>>nombre;
    
    alumno.setNombre(nombre);
    
    
    for(int i = 0; i < MAX; i++)
    {
        cout<<"Calificacion "<<i+1<<": ";
        cin>>cal;
        
        alumno.setCalificacion(cal);
    }
    
    //system("cls");
    
    cout<<"*****INFORMACION DEL ALUMNO*****"<<endl<<endl;
    cout<<"Nombre: "<<alumno.getNombre()<<endl;
    cout<<"Promedio: "<<alumno.getPromedio()<<endl;
    cout<<"Estatus: ";
    
    if(alumno.estaAprobado())
    {
        cout<<"Aprobado";
    }
    else
    {
        cout<<"Reprobado";
    }
    
    cout<<endl;
    
    return 0;
}