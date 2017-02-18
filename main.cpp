#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <time.h>
using namespace std;

void imprimir(int[], int);
void Shell(int[], int, int);
void initRand(void);
void generate(int[],int);
   
   clock_t inicio,fin;

int main(int argc, char *argv[])
{
    int n=500000;
    int vec[n];

  /*  
     for(int i=0; i<n; i++){
       cout<<"Ingrese numero: ";
        cin>>vec[i];
     }
  */
     initRand();
     generate(vec,n);

    int salto=n/2;
     //imprimir(vec, n);
     cout<<endl<<endl;
    inicio = clock();
    Shell(vec, n, salto);
    // imprimir(vec, n);



     cout<<endl<<"Tiempo de ejecucion Shell: "<<( (double)(fin - inicio) / (double)CLOCKS_PER_SEC ) *1000 << " milisegundos"<<endl;
     return 0;
 }

void initRand()
{
   srand(time(NULL));
}

void generate(int v[],int length){
     for(int i=0; i<length; i++){
          //vec[i]=rand()%(50-1)+1;
         v[i]=rand()%(length-1)+1;  
     }
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

   fin = clock();
}
