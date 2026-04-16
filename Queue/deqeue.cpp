#include<iostream>
#include "deqeue.h"
using namespace std;

int main() {
    qeue<int> dq(5);

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(2);

    dq.display();

    dq.removeFront();
    dq.removeRear();

    dq.display();
}
