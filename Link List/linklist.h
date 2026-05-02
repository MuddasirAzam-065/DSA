#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    
    Node(int value)
    {
        data = value;
        next = nullptr;
    }

};

class list{
    Node *head;
    Node *tail;
    public:
    list(){head = tail = nullptr;}
    void push(int value)
    {
        Node *newNode = new Node(value);
        if(head == nullptr)
        {
            head = tail = newNode;
            return;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void pop(int value)
    {
        Node *newNode = new Node(value);
        if(head == nullptr)
        {
            head = tail = newNode;
            return;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void popFront()
    {
        if (head == nullptr){
            cout<<"list is empty";
        return;
        }
        else{
            Node *temp = head;
            head = head->next;
            temp->next = nullptr;
            delete temp;
        }
    }

    void popBack()
    {
        if (head == nullptr){
            cout<<"list is empty";
        return;
        }
        Node *temp = head;
        while(temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = nullptr;
        delete tail;
        tail = temp;
    }

    int search(int value)
    {
        int index = 0;
        Node *temp = head;
        while(temp->next != nullptr)
        {
            if(temp->data == value)
                return index;
            
            temp = temp->next;
            index++;

        }
        return -1;
    }

    void print()
    {
        Node *temp = head;
        while(temp != nullptr)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
    }
};