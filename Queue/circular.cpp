#include<iostream>
#include<string>
#include "circular.h"
int main() {
    qeue<float> q(10);

    for(int i=1;i<=10;i++)
    {
        q.insert((i+5)/3);
    }
    q.display();

    while (q.isEmpty())
    {
        q.remove();
    }
    
}