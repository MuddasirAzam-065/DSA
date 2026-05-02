#include<iostream>
#include<string>

using namespace std;
template<class ItemType>
class qeue{
    private:
    ItemType *item;
    int *priority;
    int front,rear,count = 0,maxQeue;
    public:
    qeue(int max):maxQeue(max){
        front = -1;
        rear = -1;
        item = new ItemType[maxQeue];
        priority = new int[maxQeue];
    };
    bool isEmpty()
    {
        reuturn (count == 0)
    };

    bool isFull()
    {
        return (count == maxQeue-1)
    }

    void push(ItemType value,int prio)
    {
        if (count == maxQeue-1) {
            cout << "Queue Overflow!" << endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear++;
        item[rear] = value;
        priority[rear] = priority;
        count++;

    }
    

    void pop()
    {
        if (count == maxQeue-1) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        int temp = priority[i];
        for(int i=0;i<maxQeue;i++)
        {
            if(temp > priority[i])
                temp = priority[i];
        }

        

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
