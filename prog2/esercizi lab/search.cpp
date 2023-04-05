#include <iostream>
using namespace std;

void printVet(int vet[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << vet[i] << " ";
    }
    cout << endl;
}

void search(int vet[], int n , int key)
{ 
    int mid= 0;
    int count=0;
    for(int i=0; i<n; i++) 
    {
        count++;
        if(vet[i] == key) 
          cout << "Find ad index " << i << " after " << count << " steps" << endl;
    }    
}

void swap(int& a, int& b)
{ 
    int temp=b;
    b=a;
    a=temp;   
}

void bubblesort(int vet[], int n)   
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(vet[i] > vet[j])
             swap(vet[i],vet[j]);
        }
    }

}

void binarySearch(int vet[], int n, int key, int start, int end)
{
    bubblesort(vet, n);
    int count=0;
    bool found = false;
    int mid=0;

    while(!found && start!=end)
    {
        count ++;
        mid= start+(end-start)/2;
        if(vet[mid])
            found= true;

        if(key < mid)
            end= mid;

        if(key > mid)
            start=mid;    
    }

    if(found)
        cout << "Find ad index " << mid << " after " << count << " steps" << endl;
    if(!found)
        cout << "Not found" << endl;
    

}

void binarySearch(int vet[], int n, int key)
{
    int start = 0;
    int end = n;
    binarySearch(vet, n, key, start, end);
}

void recursiveBinarySearch(int vet[], int n, int key, int start, int end)
{ 
    bubblesort(vet, n);
    int mid = start+(end-start)/2;
    
    if(vet[mid]==key)
    {
          cout << "Find ad index " << mid+1 <<endl;
          return ;
    }
    if(vet[mid] != key && start == end)
    {
        cout<< " Not found"<<endl;
        return ; 
    }
    if( key < vet[mid])
      recursiveBinarySearch( vet,  n,  key,  start,  mid);

    if( key > vet[mid])
      recursiveBinarySearch( vet,  n,  key,  mid,  end);  
     


}

void recursiveBinarySearch(int vet[], int n, int key)
{
    int start = 0;
    int end = n;
    recursiveBinarySearch(vet, n, key, start, end);
}

int main()
{
    int vet[] = {4, 5, 7, 2, 1, 0, 3, 8, 6, 9};
    int n = sizeof(vet)/sizeof(int);
    printVet(vet, n);
    search(vet, n, 6);
    binarySearch(vet, n, 6);
    printVet(vet, n);
    recursiveBinarySearch(vet, n, 5);
}  