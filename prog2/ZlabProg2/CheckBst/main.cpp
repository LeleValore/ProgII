#include <iostream>
#include <cstdlib>
using namespace std;

#include "Bst.h"

int main()
{
    // Crea un BST di interi
    Bst<int>* bstInt = new Bst<int>();

    // Inserimento di valori interi
    bstInt->insert(8);
    bstInt->insert(3);
    bstInt->insert(10);
    bstInt->insert(1);
    bstInt->insert(6);
    bstInt->insert(14);
    bstInt->insert(4);
    bstInt->insert(7);
    bstInt->insert(13);

    // Inserimento di valori interi con il metodo inserisciMale()
    for(int i = 0; i < 10; i++)
        bstInt->inserisciMale(rand() % 50);

    // Stampa il BST di interi con la visita in ordine
    bstInt->inOrder();
    


    // Crea un BST di char
    Bst<char>* bstChar = new Bst<char>();

    // Inserimento di valori char
    bstChar->insert('h');
    bstChar->insert('e');
    bstChar->insert('l');
    bstChar->insert('l');
    bstChar->insert('o');

    // Inserimento di valori char con il metodo inserisciMale()
    for(int i = 0; i < 5; i++)
        bstChar->inserisciMale('a' + rand() % 26);

    // Stampa il BST di char con la visita in ordine
    bstChar->inOrder();

    return 0;
}
