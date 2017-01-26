#include <iostream>

using namespace std;


class Conjunto {
    private:
        int arreglo[50];  
        int tam;  

    public:
        Conjunto(){
            tam = 0;
        }



        void Insertar( int x ){    
            for (int i = 0; i < tam; i++)    {
                if (arreglo[i] == x  ){
                    cout << "No se pudo insertar el elemento " << x << " ya que ya existe en el conjunto !!!" << endl << endl;
                    return;
                }
            }


            arreglo[tam] = x;
            tam++;    
            //cout << "El elemento " << x << " se insertó correctamente" << endl << endl;

            return;
        }



        void Eliminar( int x ){
            bool band=false;

            for (int i = 0; i < tam; i++)    
                if ( arreglo[i] == x  ){
                    band = true;             
                    arreglo[i] = arreglo[ tam-1 ];
                    tam--;
            }

            if(band){
                //cout<<"Se eliminó "<< x <<" del conjunto" << endl << endl;
            }
            else
                cout<<"No se pudo eliminar el " <<  x << " ya que no se encontró en el conjunto !!!" << endl << endl;

            return;
        }



        int Mostrar( int Posicion ){
            if (Posicion < 0  ||  Posicion >= tam){
                //cout << "Posición " << Posicion << " inválida !!!" << endl << endl;
                return -1;
            }

            //cout << "Elemento de la posición " << Posicion << " recuperado: " << arreglo[Posicion] << endl << endl;
            return arreglo[Posicion];
        }



        bool Pertenece( int x ){
            // PERTENECE: indica si un elemento pertenece a un conjunto.
            for ( int i = 0;  i < tam;  i++ ){
                if ( arreglo[i] == x ){
                    //cout << "El elemento " << x << " pertenece al conjunto" << endl << endl;
                    return true;
                }
            }


            //cout << "El elemento " << x << " NO pertenece al conjunto !!!" << endl << endl;
            return false;
        }



        bool EsVacio(){
            // ESVACIO: indica si el conjunto es vacío.
            if (tam == 0){
                //cout << "El conjunto está vacío" << endl << endl;
            }
            else{
                //cout << "El conjunto NO está vacío" << endl << endl;
            }


            return (tam == 0);
        }



        int Tamaño(){
            // TAM: da la cardinalidad de un conjunto
            //cout << "Tamaño: " << tam << endl << endl;
            return tam;
        }



        void Imprimir(){
            cout << "Elementos del conjunto: " << endl;

            for (int i = 0;  i < tam;  i++){
                cout << arreglo[i] << endl;
            }

            cout << "*************************" << endl << endl;
        }
};





class Conjuntos {
    public:
        Conjunto creaConjuntoVacio(){
            Conjunto a;    
            return a;
        }



        Conjunto Union(Conjunto x, Conjunto y){
            // UNION: efectúa la unión de dos conjuntos.
            Conjunto c;

            c=x;

            for (int i = 0;  i < y.Tamaño(); i++ ){
                c.Insertar( y.Mostrar(i) );
            }

            return c;
        }



        Conjunto Interseccion(Conjunto x, Conjunto y){
            // INTERSECCIÓN: intersección de 2 conjuntos.
            Conjunto c;

            for ( int i = 0;  i < x.Tamaño(); i++ )
                for ( int j = 0;  j < y.Tamaño(); j++ )
                    if ( y.Pertenece( x.Mostrar( i ) )){
                        c.Insertar( x.Mostrar( i ) );
                    }


            for ( int i = 0;  i < y.Tamaño(); i++ )
                for ( int j = 0;  j < x.Tamaño(); j++ )
                    if ( x.Pertenece( y.Mostrar( i ) )){
                        c.Insertar( y.Mostrar( i ) );
                    }


            return c;
        }



        bool EsSubconjunto(Conjunto x, Conjunto y){
            // ESSUBCONJ: indica si un conjunto es subconjunto de otro.
            for ( int i = 0;  i < x.Tamaño(); i++ )
                for ( int j = 0;  j < y.Tamaño(); j++ )
                    if ( ! y.Pertenece( x.Mostrar( i ) )){
                        cout << "El conjunto X no es subconjunto de Y por el elemento: " << x.Mostrar( i ) << " !!!" << endl << endl;
                        return false;
                    }


                    cout << "X si es subconjunto de Y" << endl << endl;
            return true;
        }

}; //Clase





int main (int argc, char *argv[]){
    Conjuntos cs;

    Conjunto c1 = cs.creaConjuntoVacio();

    c1.EsVacio();
    c1.Tamaño();
    c1.Imprimir();


    c1.Insertar( 12 );
    c1.Insertar( 12 );
    c1.Insertar( 3 );
    c1.Insertar( 24 );

    c1.Pertenece( 12 );
    c1.Pertenece( 120 );


    c1.EsVacio();
    c1.Tamaño();
    c1.Imprimir();


    c1.Eliminar(2);
    c1.Eliminar(12);

    c1.EsVacio();
    c1.Tamaño();
    c1.Imprimir();


    c1.Mostrar(-1);
    c1.Mostrar(0);
    c1.Mostrar(1);
    c1.Mostrar(2);
    c1.Mostrar(3);



    Conjunto c2 = cs.creaConjuntoVacio();

    c2.Insertar( 3 );
    c2.Insertar( 24 );
    c2.Insertar( 1114 );





    Conjunto cUnion = cs.Union(c1, c2);
    cUnion.Imprimir();



    Conjunto cInterseccion = cs.Interseccion(c1, c2);
    c1.Imprimir();
    c2.Imprimir();
    cInterseccion.Imprimir();


    cout << cs.EsSubconjunto( c1, c2 );
    cout << cs.EsSubconjunto( c2, c1 );

    return 0;
}