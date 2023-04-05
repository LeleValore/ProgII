/*
Gli insimei sono fondamentali per l'informatica, essi possono essere manipolati 
dagli algoritmi possono crescere, ridursi o cambiare nel tempo.

Questi sono detti dinamici.



-SEQUENZE LINEARI
° Insime finito di elementi disposti consecutivamente.

° Gli elementi hanno un ordine, che puo essere O meno rilevante.Ogni elemento Puo quindi avere associato un indice di posizione(univoco)

°L'operazione più elementare é l'accesso ai singoli elementi 


-MODALITA DI ACCESSO 
°Accesso diretto(array)
  -Accediamo direttamente all'elemento ai snza dover attraversare la sequenza.

°Accesso sequebziale (liste)
 -Raggiungiamo l'elemento attraversando la sequenza a partire da un suo estremo.

 -Costo O(i)

 -Accedere a ai+1 (da ai)  costa O(1)



ALLOCAZIONE DELLA MEMORIA

°Array e liste corrispondono a modi diversi di allocare la memoria 

°Array: le locazioni di memoria corrispondenti ad elementi contigui sono contigue.
  -il nome dell'array corrisponde alla locazione del primo elemento (a[0])
  -Se x é l'indirizzo di a, a[0] si trova all'indirizzo x
  - a[1] si trova all'indirizzo x+1, ecc...

°Liste: Gli elementi si trovano in locazioni di memoria non necessariamente contigue.
  -Ogni elemento memorizza, oltre al proprio valore,l'indirizzo del valore successivo.


°VANTAGGIO: le liste si prestano bene a implementare sequenze dinamiche.

ARRAY DI DIMENSIONE VARIABILE:
°E' necessario poter rimediare l'array (allocare uno novo di diversa dimensione)

°L'operazione richiede O(n) tempo per ciascuna nuova allocazione

° Si puo fare meglio?
 -Costo comulativo O(n) per ciascun gruppo di n operazione consecutive 
 -Costo(distribuito): O(1) per operazione

-LISTE 

Una LISTA CONCATENATA é una sequenza di elementi collegati l'uno all'altro da un puntatore 
gli elementi si compongono in due parti:
UNA che contiene l'informazione (chiave) e l'altra costituita da un puntatore al successivo elemento.

°Lista semplici: ogni elemento contiene un puntatore che lo collega al nodo successivo

°Liste doppiamente concatenate: ogni elemento contiene due puntatori, uno all'elemento precedente e l'altro al successivo

°Liste circolari Semplici: l'ultimo elemento si collega al primo in modo che la listanpuo essere attraversata in modo circolare.


°Liste circolari doppiamente concatenate: l'ultimo elemento si collega al primo elemento e viceversa.



-DICHIARAZIONE DI UN ELEMENTO
si puo definire un elemento, o "nodo" della lista, mediante i costruttori struct o class

class Nodo
{
    public:
     int dato;
     Nodo* successivo;
};


COSTRUZIONE DI UNA LISTA
 la creazione di una lista concatenata implica i seguenti passi:
 
 1) Dichiarare il tipo del nodo ed il puntatore di testa.
 2) Alloccare memoria per un nodo utilizzando l'operatore new assegnandone l'indirizzo ad un puntatore 
 3) Creare iterattivamente il primo elementp ad i successivi
 4) Ripetere finché vi siano nodi da immettere

 class Nodo 
 {
    public:
    Nodo* suc;
    int dato;
    Nodo (Nodo* n, int d) : suc(n), dato(d) {}
 };


 Nodo* prima = NULL; //lista vuota
 primo = new Nodo(primo, 5); //primo elemento

 primo = new Nodo(primo,3);

 primo = new Nodo(primo,4);



-INSERIMENTO IN TESTA
 void InsertHead (Nodo& testa_ptr, const Nodo::Item& inform)
 {
    Nodo* nuovo_ptr;
    nuovo_ptr = new Nodo; //assegna nuovo nodo
    nuovo_ptr->dato=inform; //mette elemento in nuovo nodo
    nuovo_ptr->suc = testa_ptr; //collega nuovo nodo
                                //al fronte della lista
    tsta_ptr=nuovo_ptr;         // muove puntatore testa
 }                              // e punta al nuovo nodo


-INSERIMENTO IN UN POSTO DETERMINATO

 void InsertList(Nodo* ant_ptr, const Nodo::Item& inform)
 {
    Nodo* nuovo_ptr;
    nuovo_ptr = new Nodo;
    nuovo_ptr->info= inform;
    nuovo_ptr->suc = ant_ptr-> suc;
    ant_ptr->suc = nuovo_ptr;

 }


-RICERCA DI UN ELEMENTO 
°Molto simile alla ricerca in array 

°Semplicemente alla fine viene restituito un puntatore all'elemento trovato 




-RIMOZIONE DI UN ELEMENTO
1) Cercare il nodo che contiene il dato, farlo puntare da POS e far puntare da ANT il nodo che lo precede (se non é il primo)

2) mettere il puntatore SUC del nodo puntato da ANT al puntatore SUC del nodo puntato da POS

3) se POS é il puntatore di testa si mette P al campo SUC del nodo puntato da POS

4) si libera la memoria occupata dal nodo puntato da POS 



-INSERI











*/