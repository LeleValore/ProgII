#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "print_swap.h"

//Insertion sort                    Complessità O(n)^2 nel caso medio e peggiore
                                //  Complessità O(n) per collocare un elemento in un array ordinato
void insertion_sort(int vet[], int n){

    int temp;
    for(int i=1; i<n; i++)
    {
        temp = vet[i];
        int j;
        for(j=i-1; j>0; j--) //scorro la partizione di sx
        {
            if(temp < vet[j])
                vet[j] = vet[j-1]; //sposto tutti gli elementi nella partizione ordinata in avanti
            else 
                break;
        }
        vet[j] = temp;
    }
}

//ALTERNATIVA
void insertionSort(int vet[], int n)
{
    for(int j=1;j<n;j++) 
    { 
        int key = vet[j]; 
        int i=j-1; 
        while(i>=0 && vet[i]>key) 
        { 
            vet[i+1] = vet[i]; 
            i--;
        } 
        vet[i+1] = key ;  
    } 
}


/*
Possiamo migliorare l’insertion sort utilizzando la ricerca binaria
per collocare correttamente l’elemento a[i] nel sottoarray
ordinato.
*/

#endif

//SCANSIONE DELLA SEQUENZA IN INPUT, ELEMENTO PER ELEMENTO


//INSERIMENTO DELL'ELEMENTO CONSIDERATO,NELLA POSIZIONE CORRETTA ALL'INTERNO
//DELLA SEQUENZA FINO A QUEL MOMENTO ORDINATA.