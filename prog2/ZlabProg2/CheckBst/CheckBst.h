#ifndef BST_H
#define BST_H

#include "Node.h"


template <typename T>
class Bst
{
	private:
	 Node<T>* root;
     
     void insertMale(Node<T>* ptr, T key)
        {
            if (!ptr->left)
            {
                ptr->left = new Node<T>(key);
                ptr->left->setParent(ptr);
            }
            else if (!ptr->right)
            {
                ptr->right = new Node<T>(key);
                ptr->right->setParent(ptr);
            }
            else
            {
                // Ricorsione casuale
                if (rand() % 2 == 0)
                    insertMale(ptr->left, key);
                else
                    insertMale(ptr->right, key);
            }
        }

	public:
		Bst(){root = nullptr;}

		Node<T>* getRoot()const{return root;}

		bool isEmpty(){return !root;}

		Bst* insert(T key)
		{
			if(isEmpty())
			{
				root = new Node<T>(key);
				return this;
			}
			return insert(root, key);
		}

		Bst* insert(Node<T>* ptr, T key)
		{
			if(!ptr->left && key <= ptr->key)
			{
				ptr->left = new Node<T>(key);
				ptr->left->setParent(ptr);
				return this;
			}

			if(!ptr->right && key > ptr->key)
			{
				ptr->right = new Node<T>(key);
				ptr->right->setParent(ptr);
				return this;
			}

			//sfrutto la natura intrinsecamente ricorsiva del BST

			if(key <= ptr->key)
				return insert(ptr->left, key);
			else
				return insert(ptr->right, key);
		}

		void visit(Node<T>* ptr){ cout << *ptr << endl;}

		

		//IN-ORDER
		void inOrder()
		{
			if(isEmpty())
			{
				cerr << "Empty Bst\n" << endl;
				exit(EXIT_FAILURE);

			}
			cout << "\nIn-order visit : " << endl;
			inOrder(root);
		}

		void inOrder(Node<T>* ptr)
		{
			if(!ptr) return;

			inOrder(ptr->left);
			visit(ptr);
			inOrder(ptr->right);
		}





		//MAX
		Node<T>* max()
		{
			if(isEmpty())
			{
				cerr << "Max doesn't exists" << endl;
				exit(EXIT_FAILURE);
			}
			return max(root);
		}

		Node<T>* max(Node<T>* ptr)
		{
			while(ptr->right)
				ptr = ptr->right;
			return ptr;
		}

		//MIN
		Node<T>* min()
		{
			if(isEmpty())
			{
				cerr << "Min doesn't exists" << endl;
				exit(EXIT_FAILURE);
			}
			return min(root);
		}

		Node<T>* min(Node<T>* ptr)
		{
			while(ptr->left)
				ptr = ptr->left;
			return ptr;
		}

        Node<T>* search(T key){
			if(isEmpty())
                return nullptr;
			return search(root, key);
		}

		Node<T>* search(Node<T>*ptr , T key){

			if(!ptr)
				return nullptr;

			if(ptr->key == key)
				return ptr;

			if(key <= ptr->key)
				return search(ptr->left, key);

			else
				return search(ptr->right, key);
		}

        


		Node<T>* successor(T key){

            Node<T>* ptr = search(key);
            if(!ptr || ptr == max())
                throw out_of_range("...successor doesn't exist...");

            return successor(ptr);
        }

		Node<T>* successor(Node<T>* x){

			if(isEmpty())
				return nullptr;

			if(x->right) 
				return min(x->right);

			Node<T>* y = x->parent;
			while(x && x == y->right)  //risalgo fino a che x non è un figlio sinistro, il successore sarà P[]
			{
				x = y;
				y = y->parent;
			}

			return y;
		}

        Node<T>* predecessor(T key){

            Node<T>* ptr = search(key);
            if(!ptr || ptr == min())
                throw out_of_range("...predecessor doesn't exist...");

            return predecessor(ptr);
        }

		Node<T>* predecessor(Node<T>* x){

			if(isEmpty())
				return nullptr;

			if(x->left)
				return max(x->left);

			Node<T>* y = x->parent;
			while(x && x == y->left)  //fino a che x non è un figlio destro
			{
				x = y;
				y = y->parent;
			}
			
			return y;
		}

		
		Node<T>* remove(Node<T>* node){ 

			//Caso 1: node è una foglia
			if(!node->left && !node->right)
			{
				if(node == node->parent->left)
					node->parent->left = nullptr;

				else if(node == node->parent->right)
					node->parent->right = nullptr;

				return node;
			}

			//Caso 2: node ha un solo figlio
			if(!node->right && node->left)
			{
				node->left->setParent(node->parent);

				if(node == node->parent->left)
					node->parent->left = node->left;

				else if(node == node->parent->right)
					node->parent->right = node->left;

				return node;
			}

			if(!node->left && node->right)
			{
				node->right->setParent(node->parent);

				if(node == node->parent->left)
					node->parent->left = node->right;

				else if(node == node->parent->right)
					node->parent->right = node->right;

				return node;
			}

			return nullptr;
		}

		Node<T>* remove(T key){

			if(isEmpty()) //albero vuoto
				return nullptr;

			Node<T>* node = search(key);

			if(!node)  //nodo non trovato
				return nullptr;

			Node<T>* toDelete = remove(node);

			//se non sono nel terzo caso mi ritorno il valore del nodo, che ho comunque cancellato con "remove(node)"

			if(toDelete != nullptr) 
				return toDelete;

			//Caso 3 -> Voglio eliminare un nodo con due figli

			//Sostituisco il nodo da cancellare con il successore
			Node<T>* next = successor(node);

			//Sostituisco la chiave
			T swap = node->key;
			node->key = next->key;
			next->key = swap;

			toDelete = remove(next); //stavolta sono sicuramente in uno dei due casi precedenti
			return toDelete;
		}

		friend ostream& operator<< (ostream& os, Bst<T>& bst){

			if(bst.isEmpty())
				return os << "\nEmpty BST!" << endl;

			os << "\nBST: " << endl;
			bst.in_order();
			return os;
		}
       
        bool checkBST(Node<T>* node, T* minVal = nullptr, T* maxVal = nullptr)
        {
            if (node == nullptr) {
                return true;
            }

            // Verifica se il nodo corrente rispetta il vincolo del BST.
            if ((minVal != nullptr && node->key <= *minVal) || (maxVal != nullptr && node->key > *maxVal)) {
                return false;
            }

            // Verifica se il sotto-albero sinistro e il sotto-albero destro sono entrambi BST.
            return checkBST(node->left, minVal, &node->key) && checkBST(node->right, &node->key, maxVal);
        }
         void inserisciMale(T key)
        {
         if (isEmpty())
         {
           root = new Node<T>(key);
           return;
         }
         insertMale(root, key);
        }







};
#endif