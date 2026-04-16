#pragma once
#include<iostream>
#include<string>

using namespace std;
template<class ItemType>
class qeue{
    private:
    ItemType *item;
    int front,rear,count = 0,maxQeue;
    public:
    qeue(int max):maxQeue(max){
        front = -1;
        rear = -1;
        item = new ItemType[maxQeue];
    };
    bool isEmpty()
    {
        if(rear == maxQeue - 1)
            return 0;
        if (front == -1 || front > rear)
            return 1;
    };

    void push(ItemType value)
    {
        if (rear == maxQeue - 1) {
            cout << "Queue Overflow!" << endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear++;
        item[rear] = value;
    }
    

    void pop()
    {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow!" << endl;
        }
        front++;
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << item[i] << " ";
        }
        cout << endl;
    }

    ~qeue()
    {
        delete[] item;
    }

};
