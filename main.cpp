#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <time.h>
using namespace std;

void imprimir(int vec[], int n);
void Shell(int vec[], int n, int salto);

int main(int argc, char *argv[])
{
   clock_t inicio,fin;


    int n=500000;
     int vec[n];

  /*  for(int i=0; i<n; i++){
       cout<<"Ingrese numero: ";
        cin>>vec[i];
    }*/

     srand(time(NULL));

     for(int i=0; i<n; i++){
            //vec[i]=rand()%(50-1)+1;
          vec[i]=rand()%(500000-1)+1;
         }

      int salto=n/2;
     //imprimir(vec, n);
     cout<<endl<<endl;
         inicio = clock();
     Shell(vec, n, salto);
    //imprimir(vec, n);



       cout<<endl<<"Tiempo de ejecucion Shell: "<<(((double)clock() - inicio) / CLOCKS_PER_SEC)*1000<< " milisegundos"<<endl;
     return 0;
 }

void imprimir(int vec[], int n){
    for(int i=0; i<n; i++){
        cout<<vec[i]<<" ";
    }
}

void Shell(int vec[], int n, int salto){

  int aux;

    bool band=true;


    while(band){
        band=false;
        for(int i=0; i+salto < n; i++){

            if(vec[i]<vec[salto+i]){
                aux=vec[i];
                vec[i]=vec[salto+i];
                vec[salto+i]=aux;
                band=true;

            }
        }


    }

    salto=salto/2;
        if(salto!=0)
            Shell(vec, n, salto);

}
