/*
	Alberi binari di ricerca

	Albero -> Struttura dati gerarchica dove vengono stabiliti rapporti padre-figlio più o meno diretti. 

	Ha le radici(roots) in alto e le foglie in basso. Ogni elemento è un nodo con le seguenti proprietà:

	-Arietà : massimo numero di figli possibili;
	-Figli: nodi che discendono dal nodo di partenza;
	-Parent: genitore del nodo; 

	L'arietà definisce la nomenclatura dell'albero : un albero con due figli si chiama BINARIO.

	Si può identificare in ogni albero due nodi che stanno allo stesso livello (stessa profondità).
	La radice ha sempre profondità 0.
	I figli della radice hanno profondità 1.
	I nipoti hanno profondità 2....
	La profondità(numero di livelli) viene detta "altezza" dell'albero.

	Un'altra proprietà riguarda il numero di nodi presenti in ogni livello.

	Liv.0 -> 2^0 = 1
	Liv.1 -> 2^1 = 2
	.
	.
	.
	Liv.4-> 2^4 = 16

	In generale in un livello n troviamo al massimo 2^n nodi:

		(h altezza)  n˚nodi <= 2^h -1 ovvero h = ceil (log base 2 di n)

	Un albero è completo se e solo se "n˚nodi == 2^h"

	Se voglio calcolare il numero di nodi fino ad un certo livello devo fare la sommatoria "per i che va da 0 a h - 1"
	
	Un albero è "bilanciato" se la differenza di altezza tra il sottoalbero sx e quello dx è al massimo 1.
	I nodi che non hanno figli si chiamano "foglie".

	Albero Binario di Ricerca (BST - binary search tree)

	I valori che vengono posti nel sottoalbero sx sono <= della radice(root);
	I valori che vengono posti nel sottoalbero dx sono > della radice(root);
	
	La definizione è ricorsiva.
	

	La stampa di un albero(visita) può avvenire in tre modi:

	- Pre-order: Visito prima la radice, poi il sottoalbero sinistro e poi quello destro.
	- Post-order: Visito ricorsivamente il sottoalbero sx, poi il sottoalbero destro ed infine la radice.
				 (implemenabile come pila)

	- In_order Visito prima il sottoalbero sinistro, poi la radice, poi il sottoalbero destro.
				(gli elementi vengono stampati in ordine)

	Il predecessore di un nodo è:
		-se esiste un sottoalbero sinistro è il massimo del sottoalbero sinistro
		-se non esiste un sottoalbero sinistro devo risalire fin quando il nodo corrente è un figlio destro.

	Il successore di un nodo è:
		-se esiste un sottoalbero destro è il minimo del sottoalbero destro
		-se non esiste il sottoalbero destro devo risalire fin quando il nodo corrente è un figlio sinistro.

	Cancellazione di un nodo z:

		caso 1: z è una foglia
		caso 2: z ha solo un figlio
		caso 3: z ha due figli

	1) Metto a nullptr il collegamento a partire dal genitore (verificare se z è figlio sinistro o destro);

	2) Il figlio sinistro di z->parent diventa il figlio di z e cancello z;

	3)  Trovare il successore di z :

		-Se il successore ha al più un figlio stacco il successore e sostituisco il nodo da eliminare con 
		 il suo successore

		-Se il successore ha due figli il sottoalbero sinistro di z viene trapiantato nel successore di z

		_Sostituire il valore da eliminare con il suo successore;
		_Riorganizzare il BST in modo da mantenere la proprietà dell'albero binario di ricerca. 

		In questo caso il successore si troverà sempre nel sottoalbero
		destro ed inoltre il successore avrà al più un figlio, perchè se ne avesse due il figlio sinistro sarebbe il 
		reale successore del nodo da eliminare.
		Il successore per tanto o sarà una foglia o avrà solo un figlio, quindi posso eliminarlo sfruttando o il 
		caso 1) o il caso 2).


		Complessità dei metodi di visita: Log n

*/

#include<iostream>

#include "BST.h"

using namespace std;

int main(){
	
	BST<int> bst;

	try
	{
		bst.min();
	}
	catch(const char*) //se dovessi trovare un'eccezione const char* nel blocco "try"
	{
		cout << "\nEmpty BST!" << endl;
	}

	bst.insert(10);
	bst.insert(4);
	bst.insert(5);
	bst.insert(18);
	bst.insert(11);
	bst.insert(3);
	bst.insert(12);
/*
	cout << "\nVisita pre order: " << endl;
	bst.pre_order();

	cout << "\nVisita post order: " << endl;
	bst.post_order();
*/
	cout << "\nVisita in order: " << endl;
	bst.in_order();
/*
	cout << "Max:\n" << *bst.max() << endl;
	cout << "Min:\n" << *bst.min() << endl;

	cout << "Successore di " << *bst.get_root() << *bst.successor(bst.get_root()) << endl;
	cout << "Predecessore di " << *bst.get_root() << *bst.predecessor(bst.get_root()) << endl;

	cout << "Nodo 3 : \t" << *bst.search(3) << endl;
	cout << "Nodo 8 : \t" << (bst.search(8) ? "Found" : "Not found !") << endl;

	//Successore di una foglia
	cout << "\nSuccessore di " << *bst.get_root() << *bst.successor(bst.get_root()) << endl;
*/
	cout << "Elimino il nodo 12" << endl;
	bst.remove(12);
	bst.in_order();

}

/*
int main(){

	BST<int> bst;

	bst.insert(40);
	bst.insert(25);
	bst.insert(21);
	bst.insert(18);
	bst.insert(57);
	bst.insert(36);
	bst.insert(46);
	bst.insert(32);
	bst.insert(78);
	bst.insert(52);
	bst.insert(11);
	bst.insert(44);

	cout << bst << endl;

	bst.remove(11);
	bst.remove(21);
	bst.remove(40);

	cout << "Cancellazione di 11-21-40" << endl;

	cout << bst << endl;
}
*/