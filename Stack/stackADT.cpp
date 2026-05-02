#include <iostream>
using namespace std;

template <class T>
class Stack {
private:
    T* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new T[capacity];
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == capacity - 1);
    }

    bool push(T value) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
            return false;
        }
        arr[++top] = value;
        return true;
    }

    bool pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return false;
        }
        top--;
        return true;
    }

    T getTop() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return T();
        }
        return arr[top];
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack<int> s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.getTop() << endl;

    s.pop();
    cout << "Top after pop: " << s.getTop() << endl;

    return 0;
}
