#include <iostream>
#include <string>

using namespace std;

class Alumno
{
    private:
        float promedio;
        float calificacion;
        int numDeMaterias;
    public:
        Alumno()
        {
            promedio = 0;
        }
        void setCalificacion(int numDeMaterias, float calificacion)
        {
            this->calificacion = calificacion;
            this->numDeMaterias = numDeMaterias;
            
            promedio += calificacion;
        }
        float getPromedio()
        {
            return promedio/numDeMaterias;
        }
};

class Promedios
{
     private:
     
     public:
        void imprimirDeMayorAMenor(Alumno alumno, Alumno alumno2, Alumno alumno3, Alumno alumno4, Alumno alumno5)
        {
            float arreglo[5] = {alumno.getPromedio(), alumno2.getPromedio(), alumno3.getPromedio(), alumno4.getPromedio(), alumno5.getPromedio()};
            float mayor;
            
            for(int i = 0; i < 4; i++)
            {
                if(arreglo[i] > arreglo[i+ 1])
                {
                    mayor = arreglo[i];
                    arreglo[i] = arreglo[i + 1];
                    arreglo[i + 1] = mayor;
                }
            }
        }
        
};

int main()
{
    int numDeMaterias;
    float cal;
    int helper;
    
    Alumno alumno;
    Alumno alumno2;
    Alumno alumno3;
    Alumno alumno4;
    Alumno alumno5;
    
    cout<<"Ingrese el numero de materias: ";
    cin>>numDeMaterias;
    
    cout<<"Ahora por favor ingrese la califiacion de cada materia: "<<endl<<endl;
    for(int i = 0; i < numDeMaterias; i++)
    {
        helper = 1;
        
        cout<<"Calificacion "<<i+1<<" del alumno "<<helper<<": ";
        cin>>cal;
        
        alumno.setCalificacion(numDeMaterias, cal);
        
        helper++;
        cout<<"Calificacion "<<i+1<<" del alumno "<<helper<<": ";
        cin>>cal;
        
        alumno2.setCalificacion(numDeMaterias, cal);
        
        helper++;
        cout<<"Calificacion "<<i+1<<" del alumno "<<helper<<": ";
        cin>>cal;
        
        alumno3.setCalificacion(numDeMaterias, cal);
        
        helper++;
        cout<<"Calificacion "<<i+1<<" del alumno "<<helper<<": ";
        cin>>cal;
        
        alumno4.setCalificacion(numDeMaterias, cal);
        
        helper++;
        cout<<"Calificacion "<<i+1<<" del alumno "<<helper<<": ";
        cin>>cal;
        
        alumno5.setCalificacion(numDeMaterias, cal);
    }
    
    
    
    cout<<endl<<endl<<alumno.getPromedio()<<endl;
    cout<<alumno2.getPromedio()<<endl;
    cout<<alumno3.getPromedio()<<endl;
    cout<<alumno4.getPromedio()<<endl;
    cout<<alumno5.getPromedio()<<endl;
    
    
    return 0;
}