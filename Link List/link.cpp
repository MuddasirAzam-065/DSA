#include<iostream>
#include "link.h"
using namespace std;
int main()
{
    list l1;
    l1.push(7);
    l1.push(3);
    l1.push(2);
    l1.push(5);

    l1.print();

    l1.pop();
    cout<<endl;
    l1.print();
    l1.push(8);
    cout<<endl;
    l1.print();
    l1.deleteItem(3);
    cout<<endl;
    l1.print();
}