#include <iostream>
using namespace std;
#include "Bst.h"




int main()
{
    Bst<int> bstInt;
    bstInt.insert(5)->insert(2)->insert(8)->insert(2)->insert(6)->insert(9)->insert(5)->insert(7);
    bstInt.inOrder();

    Bst<char> bstChar;
    bstChar.insert('c')->insert('a')->insert('d')->insert('a')->insert('b')->insert('e')->insert('f')->insert('b');
    bstChar.inOrder();

    return 0;
}
