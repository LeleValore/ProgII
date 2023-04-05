#ifndef BST_H
#define BST_H

template<typename T>
class BSTNode{

	T key;
	BSTNode<T>* parent;
	BSTNode<T>* right;
	BSTNode<T>* left;
	bool verbose;

	template<typename C>
	friend class BST;

 public:

	BSTNode(T key, bool verbose = false) : key(key), verbose(verbose){
		parent = nullptr;
		right = nullptr;
		left = nullptr;
	}

	//Getter
	BSTNode<T>* getParent(){return this->parent;}
	BSTNode<T>* getRight(){return this->right;}
	BSTNode<T>* getLeft(){return this->left;}
	T getKey(){return this->key;}

	//Setter
	void setParent(BSTNode<T>* parent){this->parent = parent;}
	void setRight(BSTNode<T>* right){this->right = right;}
	void setLeft(BSTNode<T>* left){this->left = left;}
	void setKey(T key){this->key = key;}

	friend ostream& operator<< (ostream& os, const BSTNode<T>& b){

		if(b.verbose){
			os << "BSTNode: " << &b << endl;
			os << "Key =" << b.key << endl;
			os << "left->" << b.left << "\t right->" << b.right << "\t parent->" << b.parent << endl;
			return os;
		}

		return os << b.key << endl;
	}
	
};

template<typename T>
class BST{
	
		BSTNode<T>* root; //radice 
		char last;	//indica come è avvenuto l'ultimo inserimento

	 public:

		BST(){root = nullptr; last = 'l';}
		
		BSTNode<T>* getRoot(){return this->root;}

		bool isEmpty(){return root == nullptr;}

        void visit(BSTNode<T>* ptr) { 
			if(ptr == root){
				cout << "\nRoot: " << *ptr << endl; 
				return;
			}

			if(ptr == ptr->parent->left)
				cout << "\nLeft son: " << *ptr << endl; 

			else if(ptr == ptr->parent->right)
				cout << "\nRight son: " << *ptr << endl; 
		}

		void postOrder(BSTNode<T>* ptr){
			if(!ptr)
				return;

			postOrder(ptr->left); // passiamo la parte sinistra 
			postOrder(ptr->right);// passiamo la parte destra 
			visit(ptr);
		}

		void postOrder(){postOrder(root);}

        void insert(T key){
			
			if(isEmpty())
			{
				root = new BSTNode<T>(key); // creiamo la radice 
				return;
			}

			insert(root, key); // overloading 
		}

		void insert(BSTNode<T>* ptr, T key){ 

			if(!ptr->left && key < ptr->key) //se non esi
			{
				ptr->left = new BSTNode<T>(key); //normale insert.
				ptr->left->setParent(ptr);
				return;
			}

			if(!ptr->left && key == ptr->key && last == 'r') //Non vi é il figlio sinistro e vi é uguaglianza tra chiavi e l'ultimo inserimento é a destra
			{
				ptr->left = new BSTNode<T>(key);//effettuaiamo l'inserimento a sinistra 
				ptr->left->setParent(ptr);//setto il parent sinistro 
				last = 'l';// aggiorniamo la variabile a  sinistra 
				return;
			}

			if(!ptr->right && key == ptr->key && last == 'l')//non ce il figlio destro e vi é uguaglianza tra chiavi e l'ultimo inserimento é stato effettuato a sinistra 
			{
				ptr->right = new BSTNode<T>(key);//effettuaiamo l'inserimento a desra 
				ptr->right->setParent(ptr);//settiamo il parent 
				last = 'r';//aggiorniamo il last a destra
				return;
			}

			if(!ptr->right && key > ptr->key) //normale inserimento se non vi é figlio destro e la chiave é maggiore
			{
				ptr->right = new BSTNode<T>(key);//normale inserimento 
				ptr->right->setParent(ptr);//dettiamo il parent 
				return;
			}
			//Sfrutto la ricorsiva del nostro Albero 

			if(key < ptr->key) // se la chiave é minore utilizziamo l'insert 
				insert(ptr->left, key);//effettuiamo l'insert, passando il figlio sinistro perche la chiave é minore 

			if(key == ptr->key){// se vi é uguaglianza tra le chiavi controlliamo l'ultimo in
				if(last == 'l')
					insert(ptr->right, key);//effettuaiamo l'inserimento a sinistra 
				else
					insert(ptr->left, key);//effettuiamo l'inserimento a sinistro 
			}

			if(key > ptr->key) //inserimento a destra 
				insert(ptr->right, key);
		}




			void pre_order(BSTNode<T>* ptr){

			if(!ptr)
				return;

			visit(ptr);
			pre_order(ptr->left);
			pre_order(ptr->right);
		}

		void pre_order(){pre_order(root);}
 

};
#endif


// Non gestisce il caso, in cui inseriamo elementi duplicati e elementi diversi subito dopo,in questo caso dovremmo cercare il massimo 
//del sottoalbero sinistro e poi il minimo del sottoalbero destro e inserire l'elemento duplivato.


/*

SI Noti che la classe Nodo prima scritta su un file .h é stata inclusa sul bst, anche se di buona norma 
deve essere inserita in file apparte e poi include il file.
Ho preferito inserite tutto nello stesso file.
*/





















