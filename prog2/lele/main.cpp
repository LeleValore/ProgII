#include<iostream>
using namespace std;

#include "Bst.h"

int main(){

	BST<int> in;
	in.insert(15);
	in.insert(10);
	in.insert(7);
	in.insert(13);
	in.insert(11);
	in.insert(11);
	in.insert(11);
	in.insert(11);

	
	cout << "Visita del BST<int>: " << endl;
	in.postOrder();
	cout << endl;

	BST<char> ch;
	ch.insert('d');
	ch.insert('f');	//right
	ch.insert('f');	//left
	ch.insert('f');	//right
	ch.insert('f');	//left
	ch.insert('f');	//right
	cout << "Visita del BST<char>: " << endl;
	ch.postOrder();
	cout << endl;
}