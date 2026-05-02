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
        if (isFull())
            return false;
        arr[++top] = value;
        return true;
    }
    bool pop() {
        if (isEmpty())
            return false;
        top--;
        return true;
    }
    T getTop() {
        if (isEmpty())
            return T();
        return arr[top];
    }
    int size() {
        return top + 1;
    }
    ~Stack() {
        delete[] arr;
    }
};

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%' || ch == '\\');
}

bool isOperand(char ch) {
    return ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

bool isValidPostfix(string postfix) {
    Stack<char> s(postfix.length());
    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];
        if (isOperand(ch)) {
            s.push(ch);
        } else if (isOperator(ch)) {
            if (s.size() < 2) {
                return false;
            }
            s.pop();
            s.pop();
            s.push('x');
        } else {
            return false;
        }
    }
    return (s.size() == 1);
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    getline(cin, postfix);
    if (isValidPostfix(postfix)) {
        cout << "The postfix expression is VALID\n";
    } else {
        cout << "The postfix expression is INVALID\n";
    }
    return 0;
}

