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
            float menor;
            int counter = 0;
//            1 25 2 37 10
            while(counter != 4)
            {
                for(int i = 0; i < 4; i++)
                {
                    if(arreglo[i] < arreglo[i+ 1])
                    {
                        menor = arreglo[i];
                        arreglo[i] = arreglo[i + 1];
                        arreglo[i + 1] = menor;
                        counter = 0;
                    }
                    else
                    {
                        counter++;
                    }
                }
                for(int i = 0; i < 5; i++)
                {
                    cout<<arreglo[i]<<endl;
                } 
                cout<<endl<<endl<<counter<<endl;
                system("pause");   
            }
            
            /*for(int i = 0; i < 5; i++)
            {
                cout<<arreglo[i]<<endl;
            }
            system("pause");*/
        }
        
};

int main()
{
    int numDeMaterias;
    float cal;
    int helper;
    
    Promedios promedios;
    
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
    
    
    
    promedios.imprimirDeMayorAMenor(alumno, alumno2, alumno3, alumno4, alumno5);
    
    system("pause");
    
    return 0;
}
