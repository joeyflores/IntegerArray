#include <iostream>
#include "IntegerArray.h"

using namespace std;

int main()
{
    

    int arr[] = { 1,2,3,4,5 };
    IntegerArray a(arr, 5);
    a.print();
    a.push_back(6);
    cout << endl;
    a.print();
    a.insert(10, 5);
    cout << endl;
    a.print();
    a.remove(3);
    cout << endl;
    a.print();
    cout << endl;
    cout<<a.isEmpty()<<endl;
    cout << a.isFull()<<endl;
    a.insert(20, 4);
    a.print();
   
    

}
