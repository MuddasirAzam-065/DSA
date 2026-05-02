#include<iostream>
#include "linklist.h"
using namespace std;
int main()
{
    list l1;
    l1.push(5);
    l1.push(6);
    l1.push(7);
    l1.pop(5);
    l1.print();

    l1.popBack();cout<<"\n";
    l1.print();

    cout<<"\nValue found at index: "<<l1.search(7);
}