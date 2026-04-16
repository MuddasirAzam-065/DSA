#pragma once
#include<iostream>
#include<string>

using namespace std;
template<class ItemType>
class qeue {
private:
    ItemType *item;
    int front, rear, count, maxQeue;

public:
    qeue(int max) : maxQeue(max) {
        count = 0;
        front = -1;
        rear = -1;
        item = new ItemType[maxQeue];
    }

    bool isEmpty() {
        return (count == 0);
    }

    bool isFull() {
        return (count == maxQeue);
    }

    void insertRear(ItemType val) {
        if (isFull()) {
            cout << "Deque Overflow\n";
            return;
        }

        if (front == -1) {
            front = rear = 0;
        } 
        else {
            rear = (rear + 1) % maxQeue;
        }

        item[rear] = val;
        ++count;
    }

    void insertFront(ItemType val) {
        if (isFull()) {
            cout << "Deque Overflow\n";
            return;
        }

        if (front == -1) {
            front = rear = 0;
        } 
        else {
            front = (front - 1 + maxQeue) % maxQeue;
        }

        item[front] = val;
        ++count;
    }

    void removeFront() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } 
        else {
            front = (front + 1) % maxQeue;
        }

        --count;
    }

    void removeRear() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } 
        else {
            rear = (rear - 1 + maxQeue) % maxQeue;
        }

        --count;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        cout << "Deque elements: ";
        int i = front;
        for (int c = 0; c < count; c++) {
            cout << item[i] << " ";
            i = (i + 1) % maxQeue;
        }
        cout << endl;
    }

    ~qeue() {
        delete[] item;
    }
};