#ifndef BST_H
#define BST_H

#include "Node.h"


template <typename T>
class Bst
{
	private:
		Node<T>* root;

	public:
		Bst(){root = nullptr;}

		Node<T>* getRoot()const{return root;}

		bool isEmpty(){return !root;}

		Bst* insert(T key)
		{
			if(isEmpty())
			{
				root= new Node<T>(key);
				return this;

			}
			return insert(root, key);
		}   

		Bst* insert(Node<T>* ptr, T key)
		{
			if(key == ptr->key)
			{
				if(ptr->left == nullptr)
				{
					ptr->left = new Node<T>(key);
					ptr->left->setParent(ptr);
					return this;
				}
				else if(ptr->right == nullptr)
				{
					ptr->right = new Node<T>(key);
					ptr->right->setParent(ptr);
					return this;
				}
				else if(ptr->left->key == key)
				{
					return insert(ptr->right, key);
				}
				else if(ptr->right->key >= key)
				{
					return insert(ptr->left, key);
				}

			}
			if(key <= ptr->key)
			{
				if(!ptr->left)
			    { 
					ptr->left=new Node<T>(key);
					ptr->left->setParent(ptr);
					return this;
			    }	
				return insert(ptr->left, key);
			}
			else
			{  if(!ptr->right)
			    { 
					ptr->right = new Node<T>(key);
					ptr->right->setParent(ptr);
					return this;
				}
				return insert(ptr->right, key);
			}
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


		friend ostream& operator<< (ostream& os, Bst<T>& bst){

			if(bst.isEmpty())
				return os << "\nEmpty BST!" << endl;

			os << "\nBST: " << endl;
			bst.in_order();
			return os;
		}


};
#endif



/*
ARGOMENTAZIONE METODO INSERT:
la funzione vede dove deve essere inserito il nodo nuovo partendo dalla radice
e seguendo la regola dei BST ricordiamo:
<= sinistra > destra e ogni sotto albero é un albero 

Adesso la modifica é:
se la chiave é uguale del nodo corrente il metodo cerca una posizione dove 
inserire il nodo seguendo la buona norma del Bst

Se la chiave é minore della chiave del nodo corrente la funzione cerca una
posizione vuota a sinistra del nodo corrente.

se la chiave é minore della chiave nel nodo corrente la funzione cerca una posizione vuot
a destra del nodo corrente viene poi aggiunto il nodo e restituito il puntatore all'albero stesso.



*/