#include<iostream>
#include"priority.h"
using namespace std;
int main()
{
    priorityQueue<int> p1(5,5);

    p1.insert(54,1);
    p1.insert(32,2);
    p1.insert(23,3);
    p1.insert(45,4);
    p1.insert(65,5);
    p1.insert(89,6);
    cout<<endl;
    p1.display();
}