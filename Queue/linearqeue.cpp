#include<iostream>
#include<string>
#include "linearqeue.h"
using namespace std;

int main()
{
    qeue<string> q(4);
    if(q.isEmpty())
        cout<<"empty"<<endl;
    else 
        cout<<"Not Empty"<<endl;

    q.push("Muddasir");
    q.push("Ali");
    q.push("Asghar");
    q.display();
    q.push("Shahid");
    q.display();

    while (q.isEmpty())
    {
        q.pop();
    }
}