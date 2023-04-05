#ifndef BSTL_H
#define BSTL_H


template <typename T>
class Node
{
    private:
     T val;
     Node<T>* parent;
     Node<T>* right;
     Node<T>* left;
    public:
     Node(T val):val(val)
     {
        parent = nullptr;
        left = nullptr;
        right = nullptr;

     } 

     //getter 
     T getVal(){return this->val;}
     Node<T>* getParent(){return this->parent;}
     Node<T>* getLeft(){return this->left;}
     Node<T>* getRight(){return this->right;}


     //setter
     void setVal(T val){ val=val;}
     void setParent(Node<T>* ptr) {ptr= parent;}
     void settLeft(Node<T>* ptr){ ptr= left;}
     void setRight(Node<T>* ptr){ ptr = right;}

     friend ostream& operator<<(ostream& os, Node<T>& n)
     {
        return os<<"["<<n.val<<"]"<<endl;
     }


     template<typename W>
     friend class BST;

};

template <typename T>
class BST 
{
    private:
     Node<T>* root;

    public:
     BST() { root=nullptr; }

     Node<T>* getRoot(){return this->root;}

     bool isEmpty(){return !root;}

     void visit(Node<T>* ptr){cout<<*ptr<<endl;}
      
      //preorder
     void pre_order()
     {
        if(isEmpty())
        {
            cerr<<"NO albero da visistare:"<<endl;
            return;
        }
        pre_order(root);

     }
       //preorder
     void pre_order(Node<T>* ptr )
     {
        if(!ptr)return;
          visit(ptr);
          pre_order(ptr->left);
          pre_order(ptr->right);
        
     }
    //inorder
     void inorder()
     {
        if(isEmpty())
        {
            cerr<<"Albero vuoto:"<<endl;
            return;
        }
        inorder(root);

     }



     void inorder(Node<T>* ptr)
     {
        if(!ptr)return;
        inorder(ptr->left);
        visit(ptr);
        inorder(ptr->right);

     }


     void postorder()
     {
        if(isEmpty())
        {
            cerr<<"ALBERO VUOTO:"<<endl;
            return;

        }
        postorder(root);

       
     }


     void postorder(Node<T>* ptr)
     {
        if(!ptr)return;
         postorder(ptr->left);
         postorder(ptr->right);
         visit(ptr);
     }


     BST* insert(T val)
		{
			if(isEmpty())
			{
				root = new Node<T>(val);
				return this;
			}
			return insert(root, val);
		}


     BST* insert(Node<T>* ptr, T val)
		{
			if(!ptr->left && val <= ptr->val)
			{
				ptr->left = new Node<T>(val);
				ptr->left->setParent(ptr);
				return this;
			}

			if(!ptr->right && val > ptr->val)
			{
				ptr->right = new Node<T>(val);
				ptr->right->setParent(ptr);
				return this;
			}

			//sfrutto la natura intrinsecamente ricorsiva del BST

			if(val <= ptr->val)
				return insert(ptr->left, val);
			else
				return insert(ptr->right, val);
		}

        



    


};


#endif