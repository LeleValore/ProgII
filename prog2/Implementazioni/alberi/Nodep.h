#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
	private:
		T key;
		Node<T>* parent;
		Node<T>* right;
		Node<T>* left;

	template <typename W>
		friend class Bst;

	public:
		Node(T key):key(key){parent = left = right = nullptr;}

		//getter
		T getKey()const{return key;}
		Node<T>* getParent()const{return parent;}
		Node<T>* getRight()const{return right;}
		Node<T>* getLeft()const{return left;}

		//setter
		void setKey(T key){this->key = key;}
		void setParent(Node<T>* node){this->parent = node;}
		void setRight(Node<T>* node){this->right = node;}
		void setLeft(Node<T>* node){this->left = node;}

		friend ostream& operator<< (ostream& os, const Node<T>& n){return os << "[ " << n.key << " ] ";}
};
#endif