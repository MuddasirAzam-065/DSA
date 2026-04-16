#include <iostream>
#include <string>
using namespace std;

template <class T>
class Stack {
private:
    T* arr;
    int top;
    int capacity;

public:
    // Initialize
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
            return T();
        }
        return arr[top];
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore();

    Stack<string> s(n);

    // Push strings into stack
    for (int i = 0; i < n; i++) {
        string str;
        cout << "Enter string " << i + 1 << ": ";
        getline(cin, str);
        s.push(str);
    }

    // Pop strings to reverse order
    cout << "\nStrings in reverse order:\n";
    while (!s.isEmpty()) {
        cout << s.getTop() << endl;
        s.pop();
    }

    return 0;
}
