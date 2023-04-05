#include <iostream>
using namespace std;

int sum(int a, int b)
{
    if(b == 0)
        return a;
    return (1 + sum(a,b-1));

    
}

int iterativeSum(int a, int b)
{
   
    return a+b;
    
    
      
}

int Pow(int a, int b)
{
    if(b==0)
        return 1;
    if(b==1)
         return a;
    return a * Pow(a, b-1);     
}

int fatt(int a)
{
    if(a==0)
      return 1;
    return a * fatt(a-1);
}




int main()
{
   cout << sum(4,2) << endl;
   cout << iterativeSum(4,2 )<< endl;
   cout << Pow(4,2)<< endl;
   cout << fatt(5) << endl;
}